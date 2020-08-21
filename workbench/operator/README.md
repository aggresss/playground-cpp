## operator

### Reference
- http://www.cplusplus.com/doc/tutorial/operators/
- https://en.cppreference.com/w/cpp/language/operators
- https://www.cnblogs.com/ZY-Dream/p/10068993.html
- https://www.cnblogs.com/Joezzz/p/9733345.html

operator const char*() const
operator的作用不仅仅在于运算符的重载，他还有另外一种作用：强制类型转换

C++中没有返回类型的函数有3个，构造函数、析构函数、类型转换函数。前两个是不写返回类型函数实现中也不允许出现return语句（所以不同于void)，最后一个则是不写返回类型，但是必须返回对应类型的值，即必须出现return语句。
operator char*()是类型转换函数的定义，即该类型可以自动转换为char*类型

类型转换中返回类型在operator后面在括号前面，且没有参数。 函数运算符中是类型在 operator 前面。

any of the following operators:
```
+ - * / % ^ & | ~ ! = < > += -= *= /= %= ^= &= |= << >> >>= <<= == != <= >= <=> (since C++20) && || ++ -- , ->* -> ( ) [ ]
```

c++的两种类类型转化
1）转换构造函数
    当一个构造函数只有一个参数，而且该参数又不是本类的const引用时，这种构造函数称为转换构造函数。
2）类型转换运算符
    operator const char*() const
