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

static int init() {
		if (lua != NULL) {
			return 0;
		}
		lua = luaL_newstate();
		if (lua == NULL) {
			return 1;
		}
    luaL_openlibs(lua);
    lua_register(lua, "webSend", lua_web_send);
    return 0;
}

static int send_top(const int error) {
	size_t len = 0;
	const char* value = lua_tolstring(lua, lua_gettop(lua), &len);
	web_send(error ? "error" : "return", value);
	return error;
}

int run_lua(const char* runner, const char* script) {
    if (init()) {
				web_send("error", "oh no");
				return 1;
    }
    lua_settop(lua, 0);
    int res = luaL_dostring(lua, runner);
    if (res) {
			return send_top(res);
    }
    res = luaL_loadstring(lua, script);
		if (res) {
			return send_top(res);
    }
    res = lua_pcall(lua, 1, LUA_MULTRET, 0);
    return send_top(res);
}
