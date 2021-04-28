#include <iostream>

template<typename T, typename U>
auto max(const T& __t, const U& __u) -> decltype(__t + __u) {
    return __t > __u ? __t : __u;
}

auto main() -> int {
    std::cout << max(3, 4.5) << std::endl;
    return 0;
}
