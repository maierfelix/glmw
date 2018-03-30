/**
 * The following methods need to be bridged
 * within js which results in some overhead
 */
export default function(module, memory) {
  // @str
  module.str = function(address) {
    let view = memory.F32.subarray(address >> 2, (address >> 2) + 3);
    return `vec3(${ view[0] }, ${ view[1] }, ${ view[2] })`;
  };
  // @view
  module.view = function(address) {
    let view = memory.F32.subarray(address >> 2, (address >> 2) + 3);
    view.address = address;
    return view;
  };
  // @exactEquals
  module.exactEquals = function(a, b) {
    return !!module.exactEquals(a.address, b.address);
  };
  // @equals
  module.equals = function(a, b) {
    return !!module.equals(a.address, b.address);
  };
};
