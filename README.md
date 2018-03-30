<p align="center">
  <b>GLMW</b> - WebAssembly powered Matrix and Vector library
</p>

<br/>

#### Description

This is a near 1:1 port of [gl-matrix](https://github.com/toji/gl-matrix) [v2.4.0](https://github.com/toji/gl-matrix/blob/master/package.json#L4) to WebAssembly.

#### Performance

In most cases *glmw* runs more than twice as fast as *gl-matrix*.

Some methods like ``*.str`` and ``*.equals`` are bridged and bring in some call overhead.

#### Limitations

 - This library requires async instantiation, since WebAssembly has a [synchronous buffer instantiation size limitation](https://github.com/WebAssembly/design/issues/1190).
 - You need to manually free data, since there is no garbage collection yet (**be careful! :p**).
 - Methods like ``mat4.create()`` and ``mat4.multiply`` return a numeric address. To get an view on your data you need to use e.g. ``mat4.view(address)``. This returns a ``Float32Array`` which is a direct view onto the allocated data in the WebAssembly's memory. You can read/write from this view.
 - WebAssembly's memory cannot be shared with JavaScript's memory. This means that you cannot pass an JavaScript array into methods like ``vec3.length``. You first have to convert it into the given module type (e.g. ``vec3.fromValues``) which then gives you the memory address of the allocated data.

#### Bridged methods
 - ``*.str`` so a *JavaScript String* is returned.
 - ``*.equals`` so a *JavaScript Boolean* is returned.
 - ``*.exactEquals`` (see ``*.equals``).

#### New methods
 - ``*.view`` lets you create views onto your data in WebAssembly's memory.
 - ``*.free`` to free data from WebAssembly's memory.

#### What is left
 - ``mat2``
 - ``mat2d``
 - ``mat3``
 - ``vec2``
 - ``quat``

### Installation

````
npm install glmw
````
or the browser distribution from [here](//cdn.rawgit.com/maierfelix/glmw/master/dist/glmw-browser.js).

### Usage

#### Instantiation
This builds and compiles the WebAssembly module.

````js
  glwmatrix.init().then(instance => {
    // instance contains the compiled, ready-to-use module
  });
````

#### Original API
You can assign the instance to ``window`` and receive a near 1:1 API to its original.

````js
glwmatrix.init().then(instance => {
  Object.assign(window, instance);
  vec3.create(); // native function, TADA!
});
````
