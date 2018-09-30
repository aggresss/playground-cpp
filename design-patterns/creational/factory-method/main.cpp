#include "factory-method.hpp"

int main()
{

    Creator *creator = new ConcreteCreator1();
    Product *product1 = creator->createProduct();
    cout << product1->name() << endl;

    creator = new ConcreteCreator2();
    Product *product2 = creator->createProduct();
    cout << product2->name() << endl;

    return 0;
}
