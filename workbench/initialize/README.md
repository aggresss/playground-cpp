## 初始化规则

### Reference
- https://en.cppreference.com/w/cpp/language/list_initialization
- https://zhiqiang.org/coding/list-initializer-in-cpp.html

初始化方式
- 直接初始化(direct initialized)
- 复制初始化(copy initialized)

花括号初始化规则
- 聚合初始化 aggregate initialization
- 初始化列表初始化 initializer list initialization
- 匹配构造函数参数
- 复制初始化 copy initialized

聚合结构是指一个数组（ array ）或者一个满足下面条件的结果：
- 所有非静态的成员都是共有的（ public ）
- 没有自定义的初始化函数。
- 没有虚拟成员函数
- 继承基于 public

聚合结构可以简单理解为 c 语言里的普通结构。聚合初始化时，结构用花括号里的数据依次填充成员变量。

**花括号初始化的基本原理是匹配构造函数和初始化列表**

还有个特殊的情况，是匹配构造函数参数和上面的初始化列表初始化的的结合。比如下面这种写法：
```
std::vector<int> x{{1, 2}};
```

