# lua-5.4.6
lua的原封不动的源码

# lua_lib
把lua编译成windows的库

# cpp_call_lua
在C++侧调用lua脚本及函数

# lua构建windows库及使用说明
## 1. 构建lua library（.lib and .dll）
1.1 在Visual Studio中创建一个空工程（此处命名为lua_lib)

1.2 右键项目（lua_lib），把所有lua源码都添加进来

1.3 移除'lua.c'和'luac.c'文件（否则会main会编译不过）

1.4 右键项目（lua_lib）| Properties
- General | Configuration Type，修改为Static library (.lib)
- C/C++ | General | Preprocessor | Preprocessor Definitions，添加 LUA_BUILD_AS_DLL;（注意分号）
- C/C++ | Advanced | Compile As，修改为Compile as C Code (/TC)

1.5 编译，正常情况下可以正常生成lua_lib.lib

## 2. 使用构建的lua library
参考代码：
```c++
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
	
	lua_close(L);                               /* Clean up, free the Lua state var */
	return 0;
}
```