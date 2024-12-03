all: copy

copy: main
	cp lua-wasm.* ./webby-lua-site/

main: lua
	emcc -Ilua-5.4.6/src main.c lua-5.4.6/src/liblua.a -s WASM=1 -O3 -o lua-wasm.js -s SINGLE_FILE -s EXPORTED_FUNCTIONS="['_run_lua']" -s 'EXPORTED_RUNTIME_METHODS=["ccall"]' -s 'EXTRA_EXPORTED_RUNTIME_METHODS=["FS"]' -s MODULARIZE=1 -s 'EXPORT_NAME="initWasmModule"'

lua:
	cd lua-5.4.6/src && make generic CC='emcc -s WASM=1'

