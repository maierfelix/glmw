import {
  load,
  imports
} from "./utils";

import module from "./module.js";

import vec3_bridge from "./gl-matrix/bridges/vec3.js";
import vec4_bridge from "./gl-matrix/bridges/vec4.js";
import mat4_bridge from "./gl-matrix/bridges/mat4.js";

function init(resolve) {
  return new Promise(resolve => {
    let ns = {
      vec3: {},
      vec4: {},
      mat4: {}
    };
    load(module, imports).then(instance => {
      createLinks(ns, "vec3", instance);
      createLinks(ns, "vec4", instance);
      createLinks(ns, "mat4", instance);
      resolve(ns);
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

function createLinks(ns, name, instance) {
  let memory = instance.memory;
  let exports = instance.exports;
  let module = ns[name];
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

let glwmatrix = {};
glwmatrix.init = init;

export default glwmatrix;
