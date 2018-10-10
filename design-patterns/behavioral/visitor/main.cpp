#include "visitor.hpp"

#include <memory>

using std::make_shared;


int main()
{
    auto v1 = make_shared<ConcreteVisitor1>();
    auto v2 = make_shared<ConcreteVisitor2>();
    auto e1 = make_shared<ConcreteElementA>("ElementA");
    auto e2 = make_shared<ConcreteElementB>("ElementB");

    e1->accept(v1.get());
    e1->accept(v2.get());
    e2->accept(v1.get());
    e2->accept(v2.get());

    return 0;
}

