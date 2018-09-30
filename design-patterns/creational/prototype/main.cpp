#include "prototype.hpp"

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

int main()
{
    auto obj1 = make_shared<ConcretePrototype1>("obj1");
    cout << obj1->name() << endl;
    
    auto obj2 = obj1->clone();
    cout << obj2->name() << endl;
    obj2->setName("obj2");
    cout << obj2->name() << endl;

    auto obj3 = make_shared<ConcretePrototype2>("special obj2");
    cout << obj3->name() << endl;

    auto obj4 = obj3->clone();
    cout << obj4->name() << endl;

    return 0;
}
