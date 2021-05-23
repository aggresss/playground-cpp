#include <iostream>
#include <string>

typedef int (*AddFunc)(int, int);

int Add(int a, int b, AddFunc addFunc) {
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

int addProxy(int a, int b) {
    return AddCls().operator()(a, b);
}

int main() {
    std::cout << Add(1, 2, addImpl) << std::endl;
    std::cout << Add(1, 2, addProxy) << std::endl;
    return 0;
}