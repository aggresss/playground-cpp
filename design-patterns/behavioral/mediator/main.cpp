#include "mediator.hpp"

#include <memory>

using std::make_shared;

int main()
{
    auto cc1 = make_shared<ConcreteColleague1>();
    auto cc2 = make_shared<ConcreteColleague2>();
    auto m = make_shared<ConcreteMediator>(cc1.get(), cc2.get());
    cc1->setMediator(m.get());
    cc2->setMediator(m.get());

    cc1->notify("colleague2");
    cc2->notify("colleague1");

    return 0;
}

