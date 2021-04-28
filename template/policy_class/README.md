## Policy class template

- 策略类强调订制模板的行为，而特化模板强调模板参数的不同。
- 策略类通常作为模板的参数以便用户决定根据不同的行为选择何种策略类，而特化模板通常由模板隐式调用不需要用户选择。


### template template parameter

```
warning: template template parameter using 'typename' is a C++17 extension [-Wc++17-extensions]
```

- C++17 之前 template template parameter 只能是 class
-


### Reference

- https://blog.csdn.net/liuxuejiang158blog/category_1829095.html
