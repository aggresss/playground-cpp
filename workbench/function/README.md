## function

### Reference
- https://www.cnblogs.com/heartchord/p/5017071.html
- http://docs-old.anysdk.com/CPP11Function

std::function 最大的用处是函数回调

std::function
- 包装普通函数
- 包装模板函数
- 包装lambda表达式
- 包装函数对象
- 包装类静态成员函数
- 包装类对象成员函数

对C++中各种可调用实体（普通函数、Lambda表达式、函数指针、以及其它函数对象等）的封装，形成一个新的可调用的std::function对象；让我们不再纠结那么多的可调用实体。

std::function
std::function是一组函数对象包装类的模板，实现了一个泛型的回调机制。function与函数指针比较相似，优点在于它允许用户在目标的实现上拥有更大的弹性，即目标既可以是普通函数，也可以是函数对象和类的成员函数。

设置回调函数，以用户系统为例
```
typedef std::function<void(int, std::string&)> ProtocolUserCallback;
/* OR */
using ProtocolUserCallback = std::function<void(int, std::string&)>;
```
开发者实现返回值为void，带有两个参数(第一次参数类型int，第二个参数类型std::string&)的函数
void setCallback(const ProtocolUserCallback &cb);将实现的函数传递即可
代码范例
