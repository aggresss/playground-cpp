## explicit implicit

### Reference
- https://www.cnblogs.com/lijiaxin/p/10659157.html
- https://www.cnblogs.com/QG-whz/p/4472566.html

首先, C++中的 explicit 关键字只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的, 跟它相对应的另一个关键字是 implicit, 意思是隐藏的,类构造函数默认情况下即声明为implicit(隐式).

隐式转换
  隐式类型转换
  隐式类对象转换

显式转换
  显式类型转换
  显式类对象转换

```
void fun(CTest test);

class CTest
{
public:
    CTest(int m = 0);
}
fun(20); //隐式转换
fun(static_cast<CTest>(20)); //显式转换
```

