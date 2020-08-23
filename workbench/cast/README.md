## cast

引用类型
指针类型


### Reference
- https://zhuanlan.zhihu.com/p/86321450
- https://blog.csdn.net/chenlycly/article/details/38713981
- https://blog.csdn.net/TanJiaLiang_/article/details/83992337
- https://www.cnblogs.com/ider/archive/2011/07/31/cpp_cast_operator_part4.html
- https://www.cnblogs.com/jerry19880126/archive/2012/08/14/2638192.html

### 隐式类型转换

C++ 的两种类类型隐式转化
1）类型转换为类
    当一个构造函数只有一个参数，而且该参数又不是本类的const引用时，这种构造函数称为转换构造函数。
2）类转换为类型
    operator const type-id() const

### 显式类型转换

C++ 的显式类型转换
- static_cast
- dynamic_cast
- const_cast
- reinterpret_cast

上行转换（up-casting）与 下行转换（down-casting）
不安全来源于两个方面：其一是类型的窄化转化，会导致数据位数的丢失；其二是在类继承链中，将父类对象的地址（指针）强制转化成子类的地址（指针），这就是所谓的下行转换。“下”表示沿着继承链向下走（向子类的方向走）。
类似地，上行转换的“上”表示沿继承链向上走（向父类的方向走）。
我们给出结论，**上行转换一般是安全的，下行转换很可能是不安全的**。

C风格转换是“万能的转换”，但需要程序员把握转换的安全性，编译器无能为力；
static_cast 最接近于C风格转换，但在无关类指针转换时，编译器会报错，提升了安全性；
dynamic_cast 要求转换类型必须是指针或引用，且在下行转换时要求基类是多态的，如果发现下行转换不安全，dynamic_cast返回一个null指针，dynamic_cast总是认为void*之间的转换是安全的；
reinterpret_cast 可以对无关类指针进行转换，甚至可以直接将整型值转成指针，这种转换是底层的，有较强的平台依赖性，可移植性差；
const_cast 可以将常量转成非常量，但不会破坏原常量的const属性，只是返回一个去掉const的变量。

**static_cast**


C 中的强制类型转换
```
Type(Value)
(Type)Value
```

```
double a=2000.3;
short b;
b = (short) a;    // c-like cast notation
b = short (a);    // functional notation
```

static_cast 相当于 C 中的强制类型转换语法

对于对象的转换，也是需要有关系的，这层关系就是C++用户自定义类型转换中提到的方法：
- 构造函数（Constructor）
- 类型转换运算符（Type–Cast Operator)


**dynamic_cast**

**const_cast**

const 指针作为函数参数，调用时可以是 const 或 非 const 指针；但 非 const 指针作为函数参数时，调用时只能传入非 const 指针

**需要明确的是，即使用户通过constcast强行去除了const属性，也不代表当前变量从不可变变为了可变。constcast只是使得用户接管了编译器对于const限定的管理权，故用户必须遵守“不修改变量”的承诺。如果违反此承诺，编译器也不会因此而引发编译时错误，但可能引发运行时错误。**

**reinterpret_cast**


