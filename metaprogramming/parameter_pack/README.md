## 可变长度参数模版

#### C++11 前使用 C 风格可变长度参数 (variable argument lists)

```
#include <cstdarg>

```

#### C++11 后可以使用 Variadic templates

可变参数函数通常是递归的。第一步调用处理包中的第一个实参，然后用剩余实参调用自身。

可变参数模板是模板编程时，模板参数(template parameter)的个数可变的情形。C++11之前，模板(类模板与函数模板)在声明时必须有固定数量的模板参数。C++11允许模板定义有任意类型任意数量的模板参数。

省略号(…)在可变参数模板中有两种用途：
1. 省略号出现在形参名字左侧，声明了一个参数包(parameter pack)。使用这个参数包，可以绑定0个或多个模板实参给这个可变模板形参参数包。参数包也可以用于非类型的模板参数。
2. 省略号出现在包含参数包的表达式的右侧，则把这个参数包解开为一组实参，使得在省略号前的整个表达式使用每个被解开的实参完成求值，所有表达式求值结果被逗号分开。注意这里的逗号不是作为逗号运算符，而是用作：
    - 被逗号分隔开的一组函数调用实参列表(该函数必须是可变参数函数，而不能是固定参数个数的函数)；
    - 被逗号分隔开的一组初始化列表(initializer list)；
    - 被逗号分隔开的一组基类列表(base class list)与构造函数初始化列表(constructor’s initialization list)；
    - 被逗号分隔开的一组函数的可抛出的异常规范(exception specification)的声明列表。

实际上，能够接受可变参数个数的参数包展开的场合，必须是能接受任意个数的逗号分隔开的表达式列表。


```
#include <cstdio>
#include <iostream>

template <typename... Targs>
void tprintf(Targs... Fargs) {
    printf("%s %s %s\n", Fargs...);
}

int main() {
    tprintf("admin", "foo", "bar");
    return 0;
}
```

**参数包展开后就是以逗号分隔的形式**

### Reference

- https://www.cprogramming.com/tutorial/lesson17.html
- https://en.cppreference.com/w/cpp/utility/variadic
- https://en.cppreference.com/w/cpp/language/parameter_pack
