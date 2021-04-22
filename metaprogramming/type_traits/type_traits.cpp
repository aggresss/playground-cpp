#include <iostream>
#include <type_traits>

int demo_01() {
    std::cout << "is_*" << std::endl;
    std::cout << std::is_const<const int>::value << std::endl;
    std::cout << std::is_volatile<volatile int>::value << std::endl;
    std::cout << std::is_lvalue_reference<int &>::value << std::endl;
    std::cout << std::is_rvalue_reference<int &&>::value << std::endl;
    std::cout << std::is_pointer<int *>::value << std::endl;
    std::cout << std::is_same<int, int>::value << std::endl;

    std::cout << "add_const remove_const" << std::endl;
    std::cout << std::is_same<const int, std::add_const<int>::type>::value << std::endl;
    std::cout << std::is_same<int, std::remove_const<const int>::type>::value << std::endl;

    std::cout << "add_volatile remove_volatile" << std::endl;
    std::cout << std::is_same<volatile int, std::add_volatile<int>::type>::value << std::endl;
    std::cout << std::is_same<int, std::remove_volatile<volatile int>::type>::value << std::endl;

    std::cout << "add_cv remove_cv" << std::endl;
    std::cout << std::is_same<volatile const int, std::add_cv<int>::type>::value << std::endl;
    std::cout << std::is_same<int, std::remove_cv<const volatile int>::type>::value << std::endl;

    std::cout << "add_lvalue_reference add_rvalue_reference" << std::endl;
    std::cout << std::is_same<int &, std::add_lvalue_reference<int>::type>::value << std::endl;
    std::cout << std::is_same<int &&, std::add_rvalue_reference<int>::type>::value << std::endl;

    std::cout << "decay" << std::endl;
    std::cout << std::is_same<int, std::decay<const volatile int &&>::type>::value << std::endl;

    std::cout << "common_type" << std::endl;
    typedef std::common_type<unsigned char, short, int>::type NumericType;
    std::cout << std::is_same<int, NumericType>::value << std::endl;

    return 0;
}

template <typename T, typename U>
struct decay_equiv : std::is_same<typename std::decay<T>::type, U>::type {};

int demo_02() {
    std::cout << std::boolalpha
              << decay_equiv<int, int>::value << std::endl
              << decay_equiv<int &, int>::value << std::endl
              << decay_equiv<int &&, int>::value << std::endl
              << decay_equiv<const int &, int>::value << std::endl
              << decay_equiv<int[2], int *>::value << std::endl
              << decay_equiv<int(int), int (*)(int)>::value << std::endl;

    return 0;
}

// SFINAE
template<typename T, typename = typename std::enable_if<std::is_integral<T>::value, void>::type>
bool isodd(T x)
{
    return x % 2;
}

int main() {
    std::cout << std::boolalpha;
    // demo_01();
    // demo_02();
    std::cout << isodd(10) << std::endl;

    return 0;
}
