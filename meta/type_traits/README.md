
## 1 POD (Plain Old Data)

Plain 代表它是一个普通类型，Old 代表它可以与 C 兼容，可以使用比如 memcpy() 这类 C 中最原始函数进行操作。C++11 中把 POD 分为了两个基本概念的集合:
* 平凡的（trivial）
* 标准布局的（standard layout）

POD 数据满足的条件：
1. 可以使用字节赋值，比如memset，memcpy操作；
2. 对C内存布局兼容；
3. 保证了静态初始化的安全有效；

## 2 模版特化 (Template Specialization)



## 3 类型萃取 (Type Traits)



## Reference

- https://en.cppreference.com/w/cpp/language/template_specialization
- https://www.cnblogs.com/DswCnblog/p/6371071.html
- https://blog.csdn.net/lucky52529/article/details/104127705
