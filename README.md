<p align="center">
  <b>GLMW</b> - WebAssembly powered Matrix and Vector library
</p>

<br/>

### Description
This is a handcrafted, experimental near 1:1 port of [gl-matrix](https://github.com/toji/gl-matrix) [v2.4.0](https://github.com/toji/gl-matrix/blob/master/package.json#L4) to WebAssembly.

### Performance
In most cases *glmw* runs more than twice as fast as *gl-matrix*.

Some methods like ``*.str`` and ``*.equals`` are bridged and bring in some call overhead.

### Limitations
 - This library requires async instantiation, since WebAssembly has a [synchronous buffer instantiation size limitation](https://github.com/WebAssembly/design/issues/1190).
 - You need to manually free data, since there is no garbage collection yet (**be careful! :p**).
 - Methods like ``mat4.create`` and ``mat4.multiply`` return a numeric address. To get an view on your data you need to use e.g. ``mat4.view(address)``. This returns a ``Float32Array`` which is a direct view onto the allocated data in WebAssembly's memory. You can manually read/write from this view.
 - WebAssembly's memory cannot be directly shared with JavaScript's memory. This means that you cannot pass an JavaScript array into methods like ``vec3.sqrLength``. You first have to convert it into the given module type (e.g. ``vec3.fromValues``) which then gives you the memory address of the allocated data.

### Bridged methods
 - ``*.str`` so a *JavaScript String* is returned.
 - ``*.equals`` so a *JavaScript Boolean* is returned.
 - ``*.exactEquals`` (see ``*.equals``).

### New methods
 - ``*.view`` lets you create views onto your data in WebAssembly's memory.
 - ``*.free`` to free data from WebAssembly's memory.

### What is left

#### API modules
 - ``mat2``
 - ``mat2d``
 - ``mat3``
 - ``vec2``
 - ``quat``

### Installation
````
npm install glmw
````
or the browser distribution from [here](//rawgit.com/maierfelix/glmw/master/dist/glmw-browser.js).

### Usage

#### Instantiation
Before being able to use this library, you have to call it's ``init`` method which asynchronously compiles the WebAssembly module.

If you call a ``glmw`` function before it got instantiated somewhere, then a ``TypeError`` is thrown, because the function is simply not compiled yet.

#### Instantiation/Browser
This builds and compiles the WebAssembly module.
````js
glmw.init().then(ready => {
  // glmw is now ready and can be used anywhere
});
````

#### Instantiation/ES
Import and call the init method in your main file. Afterwards you can use ``glmw`` **anywhere**.

*index.js*
````js
import { init, vec3 } from "glmw";
import calc from "./calc";

init().then(ready => {
  // glmw is now ready and can be used anywhere
  calc();
});
````

*calc.js*
````js
import { mat4 } from "glmw";
export default function() {
  return mat4.create();
};
````

#### Instantiation/Node
Require and call the init method in your main file. Afterwards you can use ``glmw`` **anywhere**.

*index.js*
````js
const glmw = require("glmw");
const calc = require("./calc");

glmw.init().then(ready => {
  // glmw is now ready and can be used anywhere
  calc();
});
````

*calc.js*
````js
const { mat4 } = require("glmw");
module.exports = function() {
  return mat4.create();
};
````

#### Original API
You can assign the instance to ``window`` and receive a near 1:1 API to its original.
````js
glmw.init().then(instance => {
  Object.assign(window, instance);
  vec3.create(); // native function, TADA!
});
````

#### Applied usage
As you can see here, the API didn't really change.
````js
let a = vec3.create();
let b = vec3.fromValues(1.0, 2.0, 3.0);
vec3.add(a, a, b);
console.log( vec3.view(a) ); // Float32Array(3) [1, 2, 3]
````

#### Creating views
First, this is what *glmw* returns to you. Instead of references, only the numeric addresses are returned:
````js
a = mat4.create();          // 65688
b = mat4.create();          // 65760
c = mat4.multiply(a, a, b); // 65688
````
You can change data by hand this way:
````js
vA = mat4.view(a); // Float32Array([1, 0, 0...])
vA[0] = 2;         // you can now read/write
vA;                // Float32Array([2, 0, 0...])
````
