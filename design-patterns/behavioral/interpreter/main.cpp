#include "interpreter.hpp"

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::make_shared;

int main()
{
    auto c = make_shared<Context>();

    auto e1 = make_shared<TerminalExpression>('a');
    e1->interpret(c.get());
    auto e2 = make_shared<NonTerminalExpression>('+');
    e2->interpret(c.get());

    e1->interpret(c.get());

    cout << endl;
    return 0;
}

