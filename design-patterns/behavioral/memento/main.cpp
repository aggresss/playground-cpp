#include "memento.hpp"

#include <memory>

using std::make_shared;

int main()
{
    auto o = make_shared<Originator>();
    auto c = make_shared<Caretaker>(o);
    o->add();
    o->showState();
    c->saveState();
    o->add();
    o->showState();
    c->restoreState();
    o->showState();

    return 0;
}

