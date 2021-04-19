## Smart Pointer

unique_ptr具有 -> 和 * 运算符重载符，因此它可以像普通指针一样使用

unique_ptr 不能通过赋值初始化

```
std::unique_ptr<Task> taskPtr2 = new Task(); // 编译错误
```

需要使用直接初始化

```
std::make_unique<int>(1);
std::unique_ptr<int>(new int(1));
```

unique_ptr 通过 `std::move()` 进行管理权转移

### Reference
- https://www.cnblogs.com/TenosDoIt/p/3456704.html
- https://blog.csdn.net/shaosunrise/article/details/85158249


