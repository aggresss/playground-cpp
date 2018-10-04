#include "decorator.hpp"

#include <memory>

using std::make_shared;

int main()
{
    auto component = make_shared<ConcreteComponent>("man");
    auto decorator = make_shared<ConcreteDecorator>("good ", component.get());

    decorator->operation();

    return 0;
}
