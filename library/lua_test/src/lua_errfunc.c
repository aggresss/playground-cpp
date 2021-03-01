/**
 * @file lua_errfunc.c
 * @brief https://www.cnblogs.com/keviwu/p/5877883.html
 *
 */

#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <stdio.h>

int main() {
    lua_State *L = lua_open();
    luaopen_base(L);
    luaopen_table(L);
    luaopen_string(L);

    if (luaL_loadfile(L, "lua_errfunc.lua")) {
        printf("open file error\n");
        return 1;
    }
    if (lua_pcall(L, 0, 0, 0)) {
        printf("function call error 0\n");
    }

    lua_getglobal(L, "errorhandle");    // -2
    lua_getglobal(L, "printmsg");       // -1

    // 使用errorhandle函数处理错误信息
    if (lua_pcall(L, 0, 0, -2)) {
        printf("%s\n", lua_tostring(L, -1));
        printf("function call error 1\n");
    }

    lua_close(L);

    return 0;
}