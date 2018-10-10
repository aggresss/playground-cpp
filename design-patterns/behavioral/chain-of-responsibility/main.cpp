#include "chain-of-responsibility.hpp"

#include <memory>

using std::make_shared;

int main()
{
    auto h2 = make_shared<ConcreteHandler2>(nullptr);
    auto h1 = make_shared<ConcreteHandler1>(h2.get());

    h1->handlerRequest(1);
    h1->handlerRequest(11);
    h1->handlerRequest(111);
    return 0;
}
