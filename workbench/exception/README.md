## exception

### Reference
- http://www.cplusplus.com/reference/stdexcept/
- http://www.cplusplus.com/reference/exception/

exception 定义了与异常处理相关的类，声明和函数。exception类是c++库中所有异常的父类。
stdexcept 中的类均继承于 exception

- Logic errors
- Runtime errors

函数后使用 throw() 进行修饰
```
func() throw(type) // 会抛出某种异常
func() throw() // 不会抛出
func() throw(...) // 可能是任何类型的异常
```

