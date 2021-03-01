/**
 * @file lua_hello.c
 * @brief https://www.cnblogs.com/blueberryzzz/p/9557256.html
 *
 */

#include <stdio.h>
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

int main() {
    // 创建lua运行环境
    lua_State *luaEnv = lua_open();
    luaopen_base(luaEnv);
    luaL_openlibs(luaEnv);
    if (!luaEnv) {
        return -1;
    }

    // 载入lua文件
    int loadInfo = luaL_loadfile(luaEnv, "lua_hello.lua");
    if (loadInfo) {
        return loadInfo;
    }
    // 执行lua文件
    lua_pcall(luaEnv, 0, 0, 0);

    // 调用PrintHelloLua函数
    lua_getglobal(luaEnv, "PrintHelloLua");
    lua_pcall(luaEnv, 0, 0, 0);
    return 0;
}
