export let imports = {
  initialMemory: 0,
  imports: {
    randf: () => Math.random(),
    printi: console.log.bind(console),
    printch: (cc) => console.log(String.fromCharCode(cc))
  }
};

export function load(buffer, options = {}) {

  let imports = options.imports || {};

  let memory = imports.memory;
  if (!memory) {
    let opts = { initial: options.initialMemory || 1 };
    memory = new WebAssembly.Memory(opts);
    memory.initial = options.initialMemory || 1;
  }

  let table = imports.table;
  if (!table) table = new WebAssembly.Table({ initial: 0, element: "anyfunc" });

  function grow() {
    let buffer = memory.buffer;
    memory.F32 = new Float32Array(buffer);
    memory.F64 = new Float64Array(buffer);
  };

  grow();

  let env = {};
  env.memoryBase = imports.memoryBase || 0;
  env.memory = memory;
  env.tableBase = imports.tableBase || 0;
  env.table = table;

  Object.keys(imports).forEach(key => env[key] = imports[key]);

  env._abort = errno => { throw Error("abnormal abort in " + file + ": " + errno); };
  env._exit = code => { if (code) throw Error("abnormal exit in " + file + ": " + code); }

  env._grow = grow;

  return WebAssembly.instantiate(buffer, { env: env })
  .then(module => {
    var instance = module.instance;
    instance.imports = imports;
    instance.memory = memory;
    instance.env = env;
    return instance;
  });

};
