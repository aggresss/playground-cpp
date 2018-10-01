#include "bridge.hpp"

#include <memory>

using std::make_shared;

int main()
{
    auto imp = make_shared<ConcreteImplementor>();
    auto abstraction = make_shared<RefinedAbstraction>();

    abstraction->setImplementor(imp.get());
    abstraction->operate();

    return 0;
}
