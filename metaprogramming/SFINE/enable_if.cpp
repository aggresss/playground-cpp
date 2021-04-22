#include <iostream>
using namespace std;
template <bool B, class T = void>
struct user_enable_if {};

template <class T>
struct user_enable_if<true, T> { typedef T type; };

struct A {};

template <typename T>
struct Traits {
    static const bool is_basic = true;
};

template <>
struct Traits<A> {
    static const bool is_basic = false;
};

template <typename T>
void f(T a, typename user_enable_if<Traits<T>::is_basic, void>::type* dump = 0) {
    cout << "a basic type" << endl;
}

template <typename T>
void f(T a, typename user_enable_if<!Traits<T>::is_basic, void>::type* dump = 0) {
    cout << "a class type" << endl;
}

int main() {
    A a;
    f(1);
    f(a);
}