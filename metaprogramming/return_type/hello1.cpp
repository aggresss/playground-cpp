#include <iostream>

template <typename _tp1, typename _tp2>
struct _return_type {
    typedef double value_type;
};

template <typename _tp1>
struct _return_type<_tp1, double> {
    typedef double value_type;
};

template <typename _tp2>
struct _return_type<double, _tp2> {
    typedef double value_type;
};

template <>
struct _return_type<int, int> {
    typedef int value_type;
};

template <>
struct _return_type<int, float> {
    typedef float value_type;
};

template <>
struct _return_type<float, int> {
    typedef float value_type;
};

template <>
struct _return_type<float, float> {
    typedef float value_type;
};


template <typename _tp1, typename _tp2>
inline typename _return_type<_tp1, _tp2>::value_type
max(const _tp1& __a, const _tp2& __b) {
    return __a > __b ? __a : __b;
}

int main() {
    std::cout << max(3, 4.5) << std::endl;
    return 0;
}
