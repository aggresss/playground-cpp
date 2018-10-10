#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>
#include <string>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;

class Component
{
public:
    Component(){}
    virtual ~Component(){}

    virtual void operation() = 0;
};


class Decorator : public Component
{
public:
    Decorator(Component *com):component(com){}
    ~Decorator(){}
    virtual void before() = 0;
    virtual void after() = 0;
    void operation()
    {
        before();
        component->operation();
        after();
    }

private:
    Component *component;
};


class ConcreteComponent : public Component
{
public:
    ConcreteComponent(string n):name(n){}
    ~ConcreteComponent(){}

    void operation(){cout << name << endl;}

private:
    string name;
};


class ConcreteDecorator : public Decorator
{
public:
    ConcreteDecorator(string n, Component *com):Decorator(com), name(n){}
    ~ConcreteDecorator(){}

    void before(){cout << name;}
    void after(){}

private:
    string name;
};


#endif
