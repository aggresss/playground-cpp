#include "factory-method.hpp"

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

int main()
{

    auto creator = std::make_unique<ConcreteCreator>();
    auto product = creator->createProduct();
    cout << product->name() << endl;

    return 0;
}

