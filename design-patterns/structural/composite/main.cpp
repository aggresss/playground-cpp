#include "composite.hpp"

#include <memory>
#include <iostream>

using std::cout;
using std::endl;
using std::make_shared;

int main()
{
    auto root = make_shared<Composite>("/");
    auto comp1 = make_shared<Composite>("home");
    auto comp2 = make_shared<Composite>("usr");
    auto comp3 = make_shared<Composite>("etc");

    comp1->add(make_shared<Leaf>("aggresss"));
    comp1->add(make_shared<Leaf>("jaggeryu"));
    comp1->add(make_shared<Leaf>("share"));

    comp2->add(make_shared<Leaf>("local"));
    comp2->add(make_shared<Leaf>("share"));

    comp3->add(make_shared<Leaf>("rc.local"));
    comp3->add(make_shared<Leaf>("fstab"));
    comp3->add(make_shared<Leaf>("hosts"));

    root->add(comp1);
    root->add(comp2);
    root->add(comp3);
    root->show(0);

    cout << endl;
    return 0;
}
