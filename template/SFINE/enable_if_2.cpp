#include <iostream>
#include <type_traits>

// SFINAE
template <typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
is_odd(T t) {
    return bool(t % 2);
}

template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even(T t) {
    return !is_odd(t);
}

int main() {
    std::cout << is_odd(10) << std::endl
              << is_even(10) << std::endl;
}