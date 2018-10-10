#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>

using std::cout;
using std::endl;


class AbstractClass
{
public:
    AbstractClass(){}
    virtual ~AbstractClass(){}

    void templateMethod()
    {
        primitiveOperation1();
        primitiveOperation2();
    }
    virtual void primitiveOperation1() = 0;
    virtual void primitiveOperation2() = 0;
};


class ConcreteClass : public AbstractClass
{
public:
    ConcreteClass(){}
    ~ConcreteClass(){}

    void primitiveOperation1(){cout << "Executing primitive operation1 in ConcreteClass" << endl;}
    void primitiveOperation2(){cout << "Executing primitive operation2 in ConcreteClass" << endl;}
};


#endif
