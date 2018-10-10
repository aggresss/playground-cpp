#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>

using std::cout;
using std::endl;


class SubsystemA
{
public:
    SubsystemA(){}
    ~SubsystemA(){}

    void operation(){cout << "Executing operation in SubsystemA" << endl;}
};

class SubsystemB
{
public:
    SubsystemB(){}
    ~SubsystemB(){}

    void operation(){cout << "Executing operation in SubsystemB" << endl;}
};


class Facade
{
public:
    Facade(){}
    ~Facade(){}

    void operation()
    {
        SubsystemA().operation();
        SubsystemB().operation();
    }

};


#endif
