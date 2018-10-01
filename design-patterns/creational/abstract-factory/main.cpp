#include "abstract-factory.hpp"

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::make_unique;

int main()
{
    auto factory = make_unique<ConcreteFactory>();
    auto pa = factory->createProductA();
    auto pb = factory->createProductB();
    cout << " =[* *]= " << endl;

    return 0;
}
