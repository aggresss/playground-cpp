
template <typename T>
struct TypeTraits {
    static bool IsPODType() {
        return false;
    }
};

template <>
struct TypeTraits<int> {
    static bool IsPODType() {
        return true;
    }
};

template <>
struct TypeTraits<unsigned int> {
    static bool IsPODType() {
        return true;
    }
};

template <>
struct TypeTraits<char> {
    static bool IsPODType() {
        return true;
    }
};

template <>
struct TypeTraits<unsigned char> {
    static bool IsPODType() {
        return true;
    }
};

template <>
struct TypeTraits<short> {
    static bool IsPODType() {
        return true;
    }
};

template <>
struct TypeTraits<unsigned short> {
    static bool IsPODType() {
        return true;
    }
};

#include <iostream>
template <typename T>
void CheckTypeTraits(T &v) {
    std::cout << v << " is POD type: " << TypeTraits<T>::IsPODType() << std::endl;
}

int main() {
    int a = 1;
    char b = '2';
    short c = 3;
    float d = 4.4; /* 没有特化处理,因此返回0 */

    CheckTypeTraits(a);
    CheckTypeTraits(b);
    CheckTypeTraits(c);
    CheckTypeTraits(d);
    return 0;
}
