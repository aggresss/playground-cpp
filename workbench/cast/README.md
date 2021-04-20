## cast

引用类型
指针类型


### Reference
- https://zhuanlan.zhihu.com/p/86321450
- https://blog.csdn.net/chenlycly/article/details/38713981
- https://blog.csdn.net/TanJiaLiang_/article/details/83992337
- https://www.cnblogs.com/ider/archive/2011/07/31/cpp_cast_operator_part4.html
- https://www.cnblogs.com/jerry19880126/archive/2012/08/14/2638192.html
- https://blog.csdn.net/u014624623/article/details/79837849

### 隐式类型转换

C++ 的两种类类型隐式转化
1）类型转换为类
    当一个构造函数只有一个参数，而且该参数又不是本类的const引用时，这种构造函数称为转换构造函数。
2）类转换为类型
    operator const type-id() const

当一个类或者类的引用作为函数参数时，传入一个可以隐式构造该类的参数同样可行。

### 显式类型转换

C++ 的显式类型转换
- static_cast
- dynamic_cast
- const_cast
- reinterpret_cast

上行转换（up-casting）与 下行转换（down-casting）
不安全来源于两个方面：其一是类型的窄化转化，会导致数据位数的丢失；其二是在类继承链中，将父类对象的地址（指针）强制转化成子类的地址（指针），这就是所谓的下行转换。“下” 表示沿着继承链向下走（向子类的方向走）。
类似地，上行转换的“上”表示沿继承链向上走（向父类的方向走）。
我们给出结论，**上行转换一般是安全的，下行转换很可能是不安全的**。

C 风格转换是 “万能的转换”，但需要程序员把握转换的安全性，编译器无能为力；
static_cast (编译时转换) 最接近于 C 风格转换，但在无关类指针转换时，编译器会报错，提升了安全性；
dynamic_cast (运行时转换) 要求转换类型必须是指针或引用，且在下行转换时要求基类是多态的，如果发现下行转换不安全，dynamic_cast 返回一个 null 指针，dynamic_cast 总是认为 void* 之间的转换是安全的；
reinterpret_cast 可以对无关类指针进行转换，甚至可以直接将整型值转成指针，这种转换是底层的，有较强的平台依赖性，可移植性差；
const_cast 可以将常量转成非常量，但不会破坏原常量的const属性，只是返回一个去掉 const 的变量。

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

static_cast 类似于 C 中的强制类型转换语法，在编译期进行类型转换

对于对象的转换，也是需要有关系的，这层关系就是C++用户自定义类型转换中提到的方法：
- 构造函数（Constructor）
- 类型转换运算符（Type–Cast Operator)

编译时检查，用于非多态的转换，可以转换指针及其他，但没有运行时类型检查来保证转换的安全性。它主要有如下几种用法：

1. 用于类层次结构中基类（父类）和派生类（子类）之间指针或引用的转换。
    - 进行上行转换（把派生类的指针或引用转换成基类表示）是安全的；
    - 进行下行转换（把基类指针或引用转换成派生类表示）时，由于没有动态类型检查，所以是不安全的。
2. 用于基本数据类型之间的转换，如把int转换成char，把int转换成enum。
3. 把空指针转换成目标类型的空指针。
4. 把任何类型的表达式转换成void类型。

**dynamic_cast**

dynamic_cast主要用于类层次间的上行转换和下行转换，还可以用于类之间的交叉转换（cross cast）

格式: dynamic_cast <type-id> (expression)
该运算符把expression装成type-id类型的对象。type-id必须是类的指针、类的引用或者void*；
如果type-id是类的指针类型，那么expression也必须是类的指针；
如果type-id是类的引用类型，那么expression也必须是类的引用；
注意，用于多态，即：必须有虚函数

dynamic_cast是唯一无法由旧式语法执行的动作，也是唯一可能耗费重大运行成本的转型动作。

**const_cast**

const 指针作为函数参数，调用时可以是 const 或 非 const 指针；但 非 const 指针作为函数参数时，调用时只能传入非 const 指针
**需要明确的是，即使用户通过constcast强行去除了const属性，也不代表当前变量从不可变变为了可变。constcast只是使得用户接管了编译器对于const限定的管理权，故用户必须遵守“不修改变量”的承诺。如果违反此承诺，编译器也不会因此而引发编译时错误，但可能引发运行时错误。**

**reinterpret_cast**

reinterpret_cast 和 C 风格的强转是一样的。

格式：reinterpret_cast <type-id> (expression)
1. type-id 必须是一个指针、引用、算术类型、函数指针或者成员指针
2. 它可以把一个指针转换成一个整数，也可以把一个整数转换成一个指针
3. 跟 C 风格的强制转换类似，没有安全性检查
