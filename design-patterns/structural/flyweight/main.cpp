#include "flyweight.hpp"

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

int main()
{
    auto f1 = FlyweightFactory().getFlyweight("apple");
    f1->operation(1);

    auto f2 = FlyweightFactory().getFlyweight("apple");
    f1->operation(2);

    cout << (void*)f1.get() << " " << (void*)f2.get() << endl;

    return 0;
}
