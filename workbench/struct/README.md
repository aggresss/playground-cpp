## struct

### Reference
- https://blog.csdn.net/weixin_39640298/article/details/84349171

在C中使用结构体时需要加上struct，或者对结构体使用typedef取别名，而C++可直接使用
```
struct Student
{
	int  iAgeNum;
	string strName;
}
typedef struct Student Student2；// C中取别名

struct  Student  stu1;	// C中正常使用
Student2   stu2;		// C中通过取别名的使用
Student    stu3;		// C++使用
```
|| C | C++ |
|--|--|--|
成员函数|不可以|可以
静态成员|不可以|可以
访问控制|默认 public 不可修改|public protected private
继承关系|不支持继承|支持继承
初始化|不能直接初始化成员|可以直接初始化成员

struct 默认访问控制属性是 public，而 class 默认访问控制属性是 private

C与C++实际上编程思想的区别，C是面向过程，C++面向对象。
所以在C中结构体就是不同类型数据的集合，并不涉及算法和操作。
而C++是把数据变量及对这些数据变量的相关算法和操作给封装起来。
