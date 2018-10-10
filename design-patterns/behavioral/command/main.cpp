#include "command.hpp"

#include <memory>

using std::make_shared;

int main()
{
    auto r = make_shared<Receiver>();
    auto cmd1 = make_shared<ConcreteCommand1>(r.get());
    auto cmd2 = make_shared<ConcreteCommand2>(r.get());

    cmd1->execute();
    cmd2->execute();

    return 0;
}
