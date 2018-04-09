import {
  load,
  imports
} from "./utils";

import module from "./module.js";

import vec3_bridge from "./gl-matrix/bridges/vec3.js";
import vec4_bridge from "./gl-matrix/bridges/vec4.js";
import mat4_bridge from "./gl-matrix/bridges/mat4.js";

let vec3 = {};
let vec4 = {};
let mat4 = {};

function validateEnvironment() {
  if (typeof WebAssembly === "undefined") {
    throw new Error(`WebAssembly is not available or unsupported!`);
  }
};

function init() {
  return new Promise(resolve => {
    validateEnvironment();
    load(module, imports).then(instance => {
      createLinks(vec3, "vec3", instance);
      createLinks(vec4, "vec4", instance);
      createLinks(mat4, "mat4", instance);
      resolve(true);
    });
  });
};

function getMethodsFromExportsByName(exports, name) {
  let module = {};
  for (let key in exports) {
    if (key.substr(0, name.length) === name) {
      module[key.substr(name.length + 1, key.length)] = exports[key];
    }
  };
  return module;
};

function createLinks(module, name, instance) {
  let memory = instance.memory;
  let exports = instance.exports;
  // link
  let methods = getMethodsFromExportsByName(exports, name);
  Object.assign(module, methods);
  // bridge
  switch (name) {
    case "vec3": vec3_bridge(module, memory); break;
    case "vec4": vec4_bridge(module, memory); break;
    case "mat4": mat4_bridge(module, memory); break;
  };
};

export {
  init,
  vec3,
  vec4,
  mat4
};
