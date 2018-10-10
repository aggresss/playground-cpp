#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>

using std::cout;
using std::endl;


class Strategy
{
public:
    Strategy(){}
    virtual ~Strategy(){}

    virtual void algorithmInterface() = 0;
};


class Context
{
public:
    Context():strategy(nullptr){}
    ~Context(){}

    void contextInterface(){strategy->algorithmInterface();}
    void setStrategy(Strategy *s){strategy = s;}
private:
    Strategy *strategy;
};


class ConcreteStrategyA : public Strategy
{
public:
    ConcreteStrategyA(){}
    ~ConcreteStrategyA(){}

    void algorithmInterface(){cout << "Executing algorithm in ConcreteStrategyA" << endl;}
};


class ConcreteStrategyB : public Strategy
{
public:
    ConcreteStrategyB(){}
    ~ConcreteStrategyB(){}

    void algorithmInterface(){cout << "Executing algorithm in ConcreteStrategyB" << endl;}
};


#endif
