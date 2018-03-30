const fs = require("fs");
const compiler = require("webassembly/cli/compiler");

let source = `src/gl-matrix/`;

let args = [
  "-q",
  "-O3",
  source + "main.c",
  "-o", "./wasm_tmp.wasm",
  "-i", source + "mat4.c",
  "-i", source + "vec3.c",
  "-i", source + "vec4.c"
];

module.exports = function() {
  return new Promise((resolve) => {
    compiler.main(args, (e, path) => {
      if (e) throw e;
      let data = fs.readFileSync(path);
      let code = `
        let binary = new Uint8Array([${new Uint8Array(data).toString()}]);
        export default binary;
      `;
      fs.unlinkSync(path);
      fs.writeFileSync("src/module.js", code, "utf-8");
      resolve();
    });
  });
};
