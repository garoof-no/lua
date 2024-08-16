#include <stdio.h>
#include "lua.h"
#include <lauxlib.h>
#include <lualib.h>
#include "emscripten.h"

EM_JS(void, web_send, (const char* code, const char* payload), {
    Module.send(UTF8ToString(code), UTF8ToString(payload));
});

static int lua_web_send(lua_State* L) {
    size_t len = 0;
    const char *code = lua_tolstring(L, 1, &len);
	const char *payload = lua_tolstring(L, 2, &len);
    web_send(code, payload);
    return 0;
}

lua_State* lua = NULL;

int run_lua(const char* script) {

	if (lua == NULL) {
		lua = luaL_newstate();
		luaL_openlibs(lua);
		lua_register(lua, "webSend", lua_web_send);
	}
	lua_settop(lua, 0);
	int res = luaL_dostring(lua, script);

	size_t len = 0;
	const char* value = lua_tolstring(lua, lua_gettop(lua), &len);
	web_send("return", value);

	return 0;
}
