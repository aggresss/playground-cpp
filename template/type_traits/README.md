
## 1 POD (Plain Old Data)

Plain 代表它是一个普通类型，Old 代表它可以与 C 兼容，可以使用比如 memcpy() 这类 C 中最原始函数进行操作。C++11 中把 POD 分为了两个基本概念的集合:
* 平凡的（trivial）
* 标准布局的（standard layout）

POD 数据满足的条件：
1. 可以使用字节赋值，比如memset，memcpy操作；
2. 对C内存布局兼容；
3. 保证了静态初始化的安全有效；

## 2 类型萃取 (Type Traits)

类型萃取技术其实就是 trait 模板技术的具体体现。获取类型的具体特征在 Java、C# 等语言中也称为反射(reflection)，C++ 中通过模板技术也可以实现一定的反射行为。

类型信息是编译期的实体，现在要针对类型来进行编程，这其实就是模板元编程的一个方面。

在 C 和 C++ 中，普通的函数可以称为值函数，它们接受的参数是某些值，返回的结果也是值。而所谓的类型函数接受的实参是类型，返回的是被抽取出来的类型或常量值等（即用 typedef 定义的类型别名，一般不同的具体类型都定义统一的别名）。如类模板就是类型函数，sizeof 是内建的类型函数，返回给定类型实参的大小。在类型编程中，很多地方都要用到 sizeof 。

类型萃取通过对函数模板的特化来实现

## 3 constexpr

指示值或返回值是常数，并且如果可能，将在编译时计算值或返回值

## 4 #include <type_traits>

- type_traits 是 C++11 提供的模板元基础库
- type_traits 可实现在编译期计算、判断、转换、查询等等功能
- type_traits 提供了编译期的 true 和 false

## Reference

- http://www.cplusplus.com/reference/type_traits/
- https://en.cppreference.com/w/cpp/language/template_specialization
- https://www.cnblogs.com/DswCnblog/p/6371071.html
- https://blog.csdn.net/lucky52529/article/details/104127705
