#include "observer.hpp"

#include <memory>

using std::make_shared;

int main()
{
    auto o1 = make_shared<ConcreteObserver>("observer1");
    auto o2 = make_shared<ConcreteObserver>("observer2");

    auto sub = make_shared<ConcreteSubject>();
    sub->attach(o1.get());
    sub->attach(o2.get());

    sub->notify();

    return 0;
}

