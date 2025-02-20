all: copy

copy: main
	cp lua-wasm.* ./webby-lua-site/

main: lua
	emcc -Ilua-5.4.7/src main.c lua-5.4.7/src/liblua.a -s WASM=1 -O3 -o lua-wasm.js -s SINGLE_FILE -s EXPORTED_FUNCTIONS="['_run_lua']" -s 'EXPORTED_RUNTIME_METHODS=["ccall", "FS"]' -s 'EXPORT_NAME="initWasmModule"' -s MODULARIZE=1 -s ALLOW_MEMORY_GROWTH=1

lua:
	cd lua-5.4.7/src && make generic

