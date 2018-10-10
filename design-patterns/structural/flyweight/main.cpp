#include "flyweight.hpp"

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

int main()
{
    FlyweightFactory ff;
    auto f1 = ff.getFlyweight("apple");
    f1->operation(1);

    auto f2 = ff.getFlyweight("apple");
    f1->operation(2);

    cout << (void*)f1.get() << " " << (void*)f2.get() << endl;

    return 0;
}
