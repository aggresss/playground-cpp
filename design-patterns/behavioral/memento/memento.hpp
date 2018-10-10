#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::make_unique;
using std::unique_ptr;


class Memento
{
public:
    ~Memento(){}

private:
    friend class Originator;
    Memento(int s):state(s){}
    int getState(){return state;}
    int state;
};


class Originator
{
public:
    Originator():state(0){}
    ~Originator(){}
    void add(){state++;}
    // XXX shared_prt cant not access private member as friend.
    Memento* createMemento(){return new Memento(state);}
    void setState(Memento* m){state = m->getState();}
    void showState(){cout << "Current state is: " << state << endl;}

private:
    int state;
};


class Caretaker
{
public:
    Caretaker(shared_ptr<Originator> o): originator(o), memento(nullptr){}
    ~Caretaker(){if (memento != nullptr) delete memento;}

    void saveState(){memento = originator->createMemento();}
    void restoreState(){originator->setState(memento);}

private:
    shared_ptr<Originator> originator;
    Memento* memento;
};


#endif
