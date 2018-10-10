#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>

using std::cout;
using std::endl;

class Implementor
{
public:
    Implementor(){}
    virtual ~Implementor(){}

    virtual void impOperate() = 0;
};

class Abstraction
{
public:
    Abstraction(){}
    virtual ~Abstraction(){}

    virtual void operate() = 0;
    virtual void setImplementor(Implementor *i) = 0;
};

class ConcreteImplementor : public Implementor
{
public:
    ConcreteImplementor(){}
    ~ConcreteImplementor(){}

    void impOperate(){cout << "Executing operation in ConcreteImplementor" << endl;}
};

class RefinedAbstraction : public Abstraction
{
public:
    RefinedAbstraction():implementor_(nullptr){}
    ~RefinedAbstraction(){}

    void operate()
    {
        cout << "Execute refined operations" << endl;
        implementor_->impOperate();
    }
    void setImplementor(Implementor *imp){implementor_ = imp;}

private:
    Implementor *implementor_;
};

#endif
