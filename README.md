# Webby Lua

[Lua](https://www.lua.org/) VM in browser.

A for-my-needs variant of [this wasm_lua](https://github.com/Dreagonmon/wasm_lua).

The my-needs-stuff:

* The Lua VM is started once and never stopped, so you can use it more REPL-like/interactively
* There's one function for sending some Lua code from JS to the Lua, and one function for sending two string ("code" and "payload") from Lua to the JS. (The JS chooses how to interpret code/payload. Can use it for things like sending code "log" to have the JS console.log the payload...)

# Example

This repo is built and deployed to GitHub Pages, so there's [an example you can try here](https://glorp.github.io/webby-lua).

If you don't want to build the wasm stuff yourself, you can remix or download stuff through the Glitch stuff. Or you can download the individual files directly: The Emscripten-built file:
* [main.js](https://glorp.github.io/webby-lua/lua-wasm.js)

Others used in the example:
* [index.html](https://glorp.github.io/webby-lua/index.html) is the HTML
* [halp.js](https://glorp.github.io/webby-lua/halp.js) has JS for sending to Lua and receiving from Lua
* [lz-string-1.4.4.js](https://glorp.github.io/webby-lua/lz-string-1.4.4.js) is used for compressing code for putting it in URL query. Not needed unless you wanna do exactly that :)
* [gcd.lua](https://glorp.github.io/webby-lua/gcd.lua) and [lcd.lua](https://glorp.github.io/webby-lua/gcd.lua) are example Lua libraries that you probably don't want
