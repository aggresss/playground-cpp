#include <iostream>
#include <memory>

#include "test.hpp"

using namespace std;

int main() {
    shared_ptr<A> ptest(new A("123"));
    shared_ptr<A> ptest2(new A("456"));
    cout << ptest2->getStr() << endl;
    cout << ptest2.use_count() << endl;
    ptest = ptest2;
    ptest->print();
    cout << ptest2.use_count() << endl;
    cout << ptest.use_count() << endl;
    ptest.reset();
    ptest2.reset();
    cout << "done !\n";
    return 0;
}
