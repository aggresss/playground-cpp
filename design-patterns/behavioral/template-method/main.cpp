#include "template-method.hpp"

#include <memory>

using std::make_shared;

int main()
{
    auto ac = make_shared<ConcreteClass>();
    ac->templateMethod();

    return 0;
}

