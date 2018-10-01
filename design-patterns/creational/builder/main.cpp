#include "builder.hpp"

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;

int main()
{
    auto builder = make_shared<ConcreteBuilder>();
    Director director(builder.get());
    director.buildProduct();
    auto product = builder->getProduct();
    product->showProduct();
    cout << " =[* *]= " << endl;

    return 0;
}
