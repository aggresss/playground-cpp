#include <iostream>
#include <string>

typedef int (*AddFunc)(int, int);

template <typename T>
int Add(int a, int b, T addFunc) {
    return addFunc(a, b);
}

int addImpl(int a, int b) {
    return a + b;
}

class AddCls {
   public:
    int operator()(int a, int b) {
        return a + b;
    }
};

int main() {
    std::cout << Add(1, 2, addImpl) << std::endl;
    std::cout << Add(1, 2, AddCls()) << std::endl;
    return 0;
}