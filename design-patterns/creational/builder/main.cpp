#include "builder.hpp"

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;

int main()
{
    auto builder1 = make_shared<ConcreteBuilder1>();
    Director director1(builder1.get());
    director1.buildProduct();
    auto product1 = builder1->getProduct();
    product1->showProduct();
    cout << " =[* *]= " << endl;
    auto builder2 = make_shared<ConcreteBuilder2>();
    Director director2(builder2.get());
    director2.buildProduct();
    auto product2 = builder2->getProduct();
    product2->showProduct();

    return 0;
}
