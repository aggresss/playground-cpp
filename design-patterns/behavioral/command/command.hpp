#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>

using std::cout;
using std::endl;


class Command
{
public:
    Command(){}
    virtual ~Command(){}

    virtual void execute() = 0;
};


class Receiver
{
public:
    Receiver(){}
    ~Receiver(){}

    void action1(){cout << "Executing action1 in Receiver" << endl;}
    void action2(){cout << "Executing action2 in Receiver" << endl;}
};


class ConcreteCommand1 : public Command
{
public:
    ConcreteCommand1(Receiver *r):receiver(r){}
    ~ConcreteCommand1(){}

    void execute(){receiver->action1();}

private:
    Receiver *receiver;
};


class ConcreteCommand2 : public Command
{
public:
    ConcreteCommand2(Receiver *r):receiver(r){}
    ~ConcreteCommand2(){}

    void execute(){receiver->action2();}

private:
    Receiver *receiver;
};


#endif

