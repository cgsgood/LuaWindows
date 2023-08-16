extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h> 
}

int main()
{
	lua_State* L;
	L = luaL_newstate();

	luaL_openlibs(L);

	luaL_loadfile(L, "script.lua");
	lua_pcall(
		L,
		0,
		0,
		0
	);

	printf("before lua_getglobal top %d\n",lua_gettop(L));
	lua_getglobal(L, "debug");
	{
		const char* result = lua_tostring(L, -1);		
	}
	printf("before lua_getfield top %d\n",lua_gettop(L));
	lua_getfield(L, -1, "traceback");
	{
		const char* result = lua_tostring(L, -1);		
	}
	printf("before lua_pcall top %d\n",lua_gettop(L));
	lua_pcall(L,
		0,
		1,
		0);
	{
		const char* result = lua_tostring(L, -1);
		printf(result);
	}
	printf("after lua_pcall top %d\n",lua_gettop(L));
	lua_pop(L, 2);
	printf("after lua_pop top %d\n",lua_gettop(L));
	
	lua_close(L);                               /* Clean up, free the Lua state var */
	return 0;
}