# Webby Lua

There's [an example you can try here](https://glorp.github.io/webby-lua). (Repo is set up so it builds the stuff and deploys to GitHub Pages.)

Anyway: A [Lua](https://www.lua.org/) VM in browser. It's based on [this wasm_lua](https://github.com/Dreagonmon/wasm_lua), but I've changed a few things:

* The Lua VM is started once and never stopped, so you can use it more REPL-like/interactively
* There's one function for sending a chunk of Lua code from JS to the Lua, and one function for sending two string (`code` and `payload`) from Lua to the JS. (The JS chooses how to interpret code/payload, so you can decide that e.g. sending the code `"log"` should make the JS `console.log` the payload...)
* Builds a somewhat large .js files instead of a .wasm and a .js file
* It only does Lua 5.4, since that's what I'm using
* Like, different example HTML and stuff
* Don't know

# Files and stuf

If you don't want to build the wasm stuff yourself, you can just download the built stuff: You can [grab a zip file with everything here](https://glorp.github.io/webby-lua/webby-lua.zip). Or grab individual files:

* [lua-wasm.js](https://glorp.github.io/webby-lua/lua-wasm.js) is the Emscripten-built file
* [simple.html](https://glorp.github.io/webby-lua/simple.html) is a simple example that only depends on lua-wasm.js
* [index.html](https://glorp.github.io/webby-lua/index.html) is the larger example that also uses the files below
* [halp.js](https://glorp.github.io/webby-lua/halp.js) has JS for sending to Lua and receiving from Lua
* [lz-string-1.4.4.js](https://glorp.github.io/webby-lua/lz-string-1.4.4.js) is used for compressing code for putting it in URL query. Not needed unless you wanna do exactly that :)
* [gcd.lua](https://glorp.github.io/webby-lua/gcd.lua) and [lcd.lua](https://glorp.github.io/webby-lua/lcd.lua) are example Lua libraries that you probably don't want

# String literal or .wasm

In the makefile there's a bit that goes `-s SINGLE_FILE`. That makes it so the wasm stuff is Base64 encoded and put in a string literal in lua-wasm.js. It can be removed to get a smaller lua-wasm.js, along with a lua-wasm.wasm file. That makes things smaller, since the .wasm is all proper binary, but it also means that the .wasm is fetched by the browser in a way that doesn't work too well if you just open HTML files and such directly from the file system. It's possible to do one thing or the other thing anyway.

