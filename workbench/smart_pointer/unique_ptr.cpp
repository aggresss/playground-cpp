#include <iostream>
#include <memory>
#include "test.hpp"

using namespace std;

unique_ptr<A> fun()
{
    return unique_ptr<A>(new A("789"));
}
int main()
{
    unique_ptr<A> ptest(new A("123"));
    unique_ptr<A> ptest2(new A("456"));
    ptest->print();
    ptest2 = std::move(ptest);
    if(ptest == NULL)cout<<"ptest = NULL\n";
    A* p = ptest2.release();
    p->print();
    ptest.reset(p);
    ptest->print();
    ptest2 = fun();
    ptest2->print();
    return 0;
}
