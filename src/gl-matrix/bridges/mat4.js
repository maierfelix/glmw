/**
 * The following methods need to be bridged
 * within js which results in some overhead
 */
export default function(module, memory) {
  // @str
  module.str = function(address) {
    let view = memory.F32.subarray(address >> 2, (address >> 2) + 16);
    let out = "";
    for (let ii = 0; ii < 16; ++ii) {
      if (ii + 1 < 16) out += view[ii] + ", ";
      else out += view[ii];
    };
    return "mat4(" + out + ")";
  };
  // @view
  module.view = function(address) {
    let view = memory.F32.subarray(address >> 2, (address >> 2) + 16);
    view.address = address;
    return view;
  };
  // @exactEquals
  let _exactEquals = module.exactEquals;
  module.exactEquals = function(a, b) {
    return !!_exactEquals(a, b);
  };
  // @equals
  let _equals = module.equals;
  module.equals = function(a, b) {
    return !!_equals(a, b);
  };
};
