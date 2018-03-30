const fs = require("fs");
const acorn = require("acorn");
let walker = require("acorn/dist/walk");

let options = {
  ecmaVersion: 7,
  allowImportExportEverywhere: true
};

function findReturn(node) {
  let ret = null;
  walker.simple(node, {
    ReturnStatement(child) {
      ret = child;
    }
  });
  return ret;
};

function findAllocation(node) {
  let ret = null;
  walker.simple(node, {
    NewExpression(child) {
      let callee = child.callee;
      let args = child.arguments;
      let object = callee.object;
      let property = callee.property;
      let computed = callee.computed;
      if (
        !computed &&
        object.type === "Identifier" &&
        object.name === "glMatrix" &&
        property.type === "Identifier" &&
        property.name === "ARRAY_TYPE"
      ) {
        let size = args[0];
        if (
          size &&
          size.type === "Literal"
        ) {
          ret = size.value;
        }
      }
    }
  });
  return ret;
};

function getReturnType(node) {
  let type = node.type;
  if (type === "Identifier") return "out";
  return type;
};

function getExport(node) {
  let decl = node.declaration;
  if (decl.type === "FunctionDeclaration") {
    let declName = decl.id.name;
    let ret = findReturn(node);
    let retType = getReturnType(ret.argument);
    let allocation = findAllocation(node);
    let result = {
      id: declName,
      returns: retType
    };
    if (allocation) result.allocation = allocation;
    return result;
  }
};

function isCustomInterfaceRequired(moduleInterface) {
  return (
    (moduleInterface.returns !== "out") ||
    (moduleInterface.allocation !== void 0)
  );
};

function processComment(comment) {
  let arg = {
    arguments: [],
    returns: null
  };
  let split = comment.split("\n");
  split.map(line => {
    if (line.match("@param")) {
      let start = line.indexOf("{") + 1;
      let end = line.lastIndexOf("}");
      let type = line.substr(start, end - start);
    }
    else if (line.match("@return")) {
      let start = line.indexOf("{") + 1;
      let end = line.lastIndexOf("}");
      let type = line.substr(start, end - start);
      console.log(type);
    }
  });
  return arg;
};

module.exports = function(source) {

  let cmnts = [];
  options.onComment = cmnts;

  let ast = acorn.parse(source, options);
  let program = ast;

  let table = {};
  for (let ii = 0; ii < program.body.length; ++ii) {
    let node = program.body[ii];
    if (node.type === "ExportNamedDeclaration") {
      let decl = getExport(node);
      if (!decl) continue;
      decl.specialInterface = isCustomInterfaceRequired(decl);
      table[decl.id] = decl;
    }
  };

  let comments = [];
  for (let ii = 0; ii < cmnts.length; ++ii) {
    let comment = cmnts[ii].value;
    if (
      cmnts[ii].type === "Block" &&
      (comment.match("@returns ") !== null || comment.match("@return ") !== null)
    ) {
      comments.push(processComment(comment));
    }
  };

  return table;

};
