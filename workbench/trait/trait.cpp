#include <iostream>
using namespace std;

/*先定义一些tag*/
struct A
{
};
struct B : A
{
};  // 继承的好处就是，当函数需要参数为A，
    // 而你传入的参数为B的时候，可以往上一直找到适合的对象

/*假设有一个未知类*/
template <class AorB>
struct unknown_class
{
    typedef AorB return_type;
};

/*特性萃取器*/
template <class unknown_class>
struct unknown_class_traits
{
    typedef typename unknown_class::return_type return_type;
};

/*特性萃取器 —— 针对原生指针*/
template <class T>
struct unknown_class_traits<T *>
{
    typedef T return_type;
};

/*特性萃取其 —— 针对指向常数*/
template <class T>
struct unknown_class_traits<const T *>
{
    typedef const T return_type;
};

/*决定使用哪一个类型*/
template <class unknown_class>
inline typename unknown_class_traits<unknown_class>::return_type
    return_type(unknown_class)
{
    typedef typename unknown_class_traits<unknown_class>::return_type RT;
    return RT();
}

template <class unknown_class>
inline typename unknown_class_traits<unknown_class>::return_type
    __func(unknown_class, A)
{
    cout << "use A flag" << endl;
    return A();
}

template <class unknown_class>
inline typename unknown_class_traits<unknown_class>::return_type
    __func(unknown_class, B)
{
    cout << "use B flag" << endl;
    return B();
}

template <class unknown_class, class T>
T
    __func(unknown_class, T)
{
    cout << "use origin ptr" << endl;
    return T();
}

template <class unknown_class>
inline typename unknown_class_traits<unknown_class>::return_type
func(unknown_class u)
{
    typedef typename unknown_class_traits<unknown_class>::return_type return_type;
    return __func(u, return_type());
}

int main()
{
    unknown_class<B> b;
    unknown_class<A> a;
    //unknown_class<int> i;
    int value = 1;
    int *p = &value;

    A v1 = func(a);
    B v2 = func(b);
    int v3 = func(p);

    char ch = getchar();
}
