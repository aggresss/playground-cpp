#include "factory-method.hpp"

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

int main()
{

    auto creator1 = std::make_unique<ConcreteCreator1>();
    auto product1 = creator1->createProduct();
    cout << product1->name() << endl;

    auto creator2 = std::make_unique<ConcreteCreator2>();
    auto product2 = creator2->createProduct();
    cout << product2->name() << endl;

    return 0;
}

