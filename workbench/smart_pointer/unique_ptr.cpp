#include <iostream>
#include <memory>

#include "test.hpp"

using namespace std;

unique_ptr<A, ADeleter> fun() {
    return unique_ptr<A, ADeleter>(new A("789"));
}
int main() {
    unique_ptr<A, ADeleter> ptest(new A("123"));
    unique_ptr<A, ADeleter> ptest2(new A("456"));
    ptest->print();
    ptest2 = std::move(ptest);
    if (ptest == nullptr) cout << "ptest = NULL" << endl;
    A* p = ptest2.release();
    p->print();
    ptest.reset(p);
    ptest->print();
    ptest2 = fun();
    ptest2->print();
    return 0;
}
