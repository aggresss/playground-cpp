#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>

using std::cout;
using std::endl;


class Context;

class State
{
public:
    State(){}
    virtual ~State(){}

    virtual void action1(Context *c) = 0;
    virtual void action2(Context *c) = 0;
    virtual void showState() = 0;
};


class Context
{
public:
    Context(): state(nullptr){}
    ~Context(){}

    void setState(State *s){state = s;}
    void action1(){state->action1(this);}
    void action2(){state->action2(this);}
    void showState(){state->showState();}
private:
    State *state;
};


class ConcreteState1 : public State
{
public:
    static ConcreteState1 *getInstance()
    {
        if (!instance)
        {
            instance = new ConcreteState1();
        }
        return instance;
    }
    ~ConcreteState1(){}
    void action1(Context *c){cout << "Nothing to do" << endl;}
    void action2(Context *c);
    void showState(){cout << "State1" << endl;}

private:
    static ConcreteState1 *instance;
    ConcreteState1(){}
};


class ConcreteState2 : public State
{
public:
    static ConcreteState2 *getInstance()
    {
        if (!instance)
        {
            instance = new ConcreteState2();
        }
        return instance;
    }
    ~ConcreteState2(){}
    void action1(Context *c);
    void action2(Context *c){cout << "Nothing to do" << endl;}
    void showState(){cout << "State2" << endl;}

private:
    static ConcreteState2 *instance;
    ConcreteState2(){}
};

ConcreteState1 *ConcreteState1::instance = nullptr;
ConcreteState2 *ConcreteState2::instance = nullptr;


void ConcreteState1::action2(Context *c)
{
    cout << "Switch to ConcreteState2" << endl;
    ConcreteState2 *state2 = ConcreteState2::getInstance();
    c->setState(state2);
}

void ConcreteState2::action1(Context *c)
{
    cout << "Switch to ConcreteState1" << endl;
    ConcreteState1 *state1 = ConcreteState1::getInstance();
    c->setState(state1);
}

#endif

