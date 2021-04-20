#include <iostream>
#include <type_traits>

int main() {
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
    std::cout << std::is_same<int&, std::add_lvalue_reference<int>::type>::value << std::endl;
    std::cout << std::is_same<int&&, std::add_rvalue_reference<int>::type>::value << std::endl;

    std::cout << "decay" << std::endl;
    std::cout << std::is_same<int, std::decay<const volatile int &&>::type>::value << std::endl;

    std::cout << "common_type" << std::endl;
    typedef std::common_type<unsigned char, short, int>::type NumericType;
    std::cout << std::is_same<int, NumericType>::value << std::endl;

    return 0;
}
