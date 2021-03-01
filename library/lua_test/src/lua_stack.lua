-- 变量系数
Param =
{
    a = 2;
    b = 1;
}

-- 全局变量，满足c=2a+b，在c语言中实现
C = 100;

-- f(x) = ax + b
function Lua_func(x)
    return (Param.a * x * x + Param.b * x + C)
end
