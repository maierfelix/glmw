const fs = require("fs");
const glMatrix = require("../static/gl-matrix.min.js");
const generate = require("./generate");

let sourceDir = __dirname + "/../gl-matrix/";
let moduleSources = require(__dirname + "/modules");

//let baseTablePath = __dirname + "/base-table.js";

let interfaces = {};
let specialInterfaces = {};
moduleSources.map(moduleName => {
  let file = fs.readFileSync(sourceDir + moduleName + ".js", "utf-8");
  let table = generate(file);
  // full interface
  {
    interfaces[moduleName] = {};
    let interface = interfaces[moduleName];
    for (let name in table) {
      let method = table[name];
      interface[name] = method;
    };
  }
  // special interface
  {
    specialInterfaces[moduleName] = {};
    let interface = specialInterfaces[moduleName];
    for (let name in table) {
      let method = table[name];
      if (method.specialInterface) interface[name] = method;
    };
  }
});

let stubs = {
  
};

for (let key in interfaces) {
  let methods = interfaces[key];
  for (let key in methods) {
    let method = methods[key];
    if (!method.specialInterface) {
      let stub = function(out, a, b) {
        
      };
    }
  };
};

//fs.writeFileSync(__dirname + "/interfaces.json", JSON.stringify(interfaces, null, 2), "utf-8");
//fs.writeFileSync(__dirname + "/interfaces-special.json", JSON.stringify(specialInterfaces, null, 2), "utf-8");
