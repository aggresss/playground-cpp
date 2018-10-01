#include "adapter.hpp"

#include <memory>

using std::make_shared;

int main()
{
    Adaptee adaptee;
    auto t = make_shared<Adapter>(&adaptee);
    t->operate();

    return 0;
}
