## SFINAE (Substitution Failure Is Not An Error)

这种技术在代码中的一个大的用途就是在编译时期来确定某个 type 是否具有我们需要的性质

## enable_if

```
template <bool, typename T=void>
struct enable_if {
};

template <typename T>
struct enable_if<true, T> {
  using type = T;
};
```

由上可知，只有当第一个模板参数为 true 时，type 才有定义，否则使用 type 会产生编译错误，并且默认模板参数可以让你不必指定类型(默认为 void)。

#### 用法一：类型偏特化

```
template <typename T, typename Enable=void>
struct check;

template <typename T>
struct check<T, typename std::enable_if<T::value>::type> {
  static constexpr bool value = T::value;
};

```

`typename Enable = void` 用于编译检验的占位，`Enable` 可以省略。

#### 用法二：控制函数返回类型

对于模板函数，有时希望根据不同的模板参数返回不同类型的值，进而给函数模板也赋予类型模板特化的性质。

```
template <std::size_t k, class T, class... Ts>
typename std::enable_if<k==0, typename element_type_holder<0, T, Ts...>::type&>::type
get(tuple<T, Ts...> &t) {
  return t.tail;
}

template <std::size_t k, class T, class... Ts>
typename std::enable_if<k!=0, typename element_type_holder<k, T, Ts...>::type&>::type
get(tuple<T, Ts...> &t) {
  tuple<Ts...> &base = t;
  return get<k-1>(base);
}
```

由于函数模板不能偏特化，通过 enable_if 便可以根据 k 值的不同情况选择调用哪个 get，进而实现函数模板的多态

#### 用法三：校验函数模板参数类型

```
template <typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
is_odd(T t) {
  return bool(t%2);
}

template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even(T t) {
  return !is_odd(t);
}
```
定义的模板函数，只希望特定的类型可以调用

## Reference

- https://en.cppreference.com/w/cpp/language/sfinae
- https://blog.csdn.net/jeffasd/article/details/84667071
- https://blog.csdn.net/jeffasd/article/details/84667090
