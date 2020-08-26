## using


1. 配合命名空间，对命名空间权限进行管理

```
using namespace std; //释放整个命名空间到当前作用域
using std::cout;     //释放某个变量到当前作用域
```

2. 别名 在 C++11 中，尽量用 using，而不用 typedef

```
#define DString std::string    //! 不建议使用！
typedef std::string TString;   //! 使用typedef的方式
using Ustring = std::string;   //！使用 using
```

```
typedef void (tFunc*)(void);
using uFunc = void(*)(void);
```
3. 继承体系中，改变部分接口的继承权限。

在私有继承中父类公有成员和保护成员都作为子类的私有成员，并且不能被这个子类的对象所访问。
