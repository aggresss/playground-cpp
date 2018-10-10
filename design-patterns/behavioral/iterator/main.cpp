#include "iterator.hpp"

#include <memory>
#include <iostream>

using std::make_shared;
using std::cout;
using std::endl;

int main()
{
    auto a = make_shared<ConcreteAggregate>();
    a->addItem(5);
    a->addItem(4);
    a->addItem(3);
    a->addItem(2);
    a->addItem(1);

    auto i = a->createIterator();
    while (!i->isDone())
    {
        cout << i->next() << endl;
    }

    return 0;
}

