#include "strategy.hpp"

#include <memory>

using std::make_shared;

int main()
{
    auto c = make_shared<Context>();
    auto sa = make_shared<ConcreteStrategyA>();
    auto sb = make_shared<ConcreteStrategyB>();

    c->setStrategy(sa.get());
    c->contextInterface();
    c->setStrategy(sb.get());
    c->contextInterface();

    return 0;
}

