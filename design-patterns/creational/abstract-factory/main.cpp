#include "abstract-factory.hpp"

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::make_unique;

int main()
{
    auto factory1 = make_unique<ConcreteFactory1>();

    auto pa1 = factory1->createProductA();
    auto pb1 = factory1->createProductB();
    cout << " =[* *]= " << endl;
    auto factory2 = make_unique<ConcreteFactory2>();
    auto pa2 = factory2->createProductA();
    auto pb2 = factory2->createProductB();

    return 0;
}
