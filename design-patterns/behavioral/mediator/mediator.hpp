#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Mediator
{
public:
    Mediator(){}
    virtual ~Mediator(){}

    virtual void notify(string name) = 0;
};


class Colleague
{
public:
    Colleague(){}
    virtual ~Colleague(){}

    virtual void action() = 0;
    virtual void notify(string name) = 0;
    virtual void setMediator(Mediator*m) = 0;
};


class ConcreteMediator : public Mediator
{
public:
    ConcreteMediator(Colleague *cc1, Colleague *cc2): colleague1(cc1), colleague2(cc2){}
    ~ConcreteMediator(){}

    void notify(string name)
    {
        if (name == "colleague1")
        {
            colleague1->action();
        }
        else if (name == "colleague2")
        {
            colleague2->action();
        }
    }

private:
    Colleague *colleague1;
    Colleague *colleague2;

};


class ConcreteColleague1 : public Colleague
{
public:
    ConcreteColleague1(): mediator(0){}
    ~ConcreteColleague1(){}

    void setMediator(Mediator *m){mediator = m;}
    void action(){cout << "Executing action in ConcreteColleague1" << endl;}
    void notify(string name){mediator->notify(name);}

private:
    Mediator *mediator;
};


class ConcreteColleague2 : public Colleague
{
public:
    ConcreteColleague2(): mediator(0){}
    ~ConcreteColleague2(){}

    void setMediator(Mediator *m){mediator = m;}
    void action(){cout << "Executing action in ConcreteColleague2" << endl;}
    void notify(string name){mediator->notify(name);}

private:
    Mediator *mediator;
};


#endif

