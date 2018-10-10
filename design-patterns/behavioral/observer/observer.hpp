#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;


class Observer
{
public:
    Observer(){}
    virtual ~Observer(){}
    virtual void update() = 0;
};


class Subject
{
public:
    Subject(){}
    virtual ~Subject(){}

    virtual void attach(Observer *o) = 0;
    virtual void notify() = 0;
};

class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(string n): name(n){}
    ~ConcreteObserver(){}

    void update(){cout << "Updating " << name << endl;}

private:
    string name;
};


class ConcreteSubject : public Subject
{
public:
    ConcreteSubject(){}
    ~ConcreteSubject(){}

    void attach(Observer *o){vec.push_back(o);}
    void notify()
    {
        int size = vec.size();
        for (int i = 0; i < size; i++)
        {
            vec[i]->update();
        }
    }

private:
    vector<Observer *> vec;
};


#endif

