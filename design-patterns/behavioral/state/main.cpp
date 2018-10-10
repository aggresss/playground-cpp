#include "state.hpp"

#include <memory>

using std::make_shared;

int main()
{
    auto c = make_shared<Context>();
    c->setState(ConcreteState1::getInstance());
    c->showState();
    c->action1();
    c->showState();
    c->action2();
    c->showState();
    c->action1();
    c->showState();

    return 0;
}

