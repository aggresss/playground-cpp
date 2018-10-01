#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class AbstractProductA
{
public:
    AbstractProductA(){cout << "Making productA" << endl;}
    virtual ~AbstractProductA(){};
};

class AbstractProductB
{
public:
    AbstractProductB(){cout << "Making productB" << endl;}
    virtual ~AbstractProductB(){};
};

class ProductA: public AbstractProductA
{
public:
    ProductA(){cout << "I am ProductA" << endl;}
    ~ProductA(){};
};

class ProductB: public AbstractProductB
{
public:
    ProductB(){cout << "I am ProductB" << endl;}
    ~ProductB(){};
};

class AbstractFactory
{
public:
    AbstractFactory(){};
    virtual ~AbstractFactory(){};

    virtual std::shared_ptr<AbstractProductA> createProductA() = 0;
    virtual std::shared_ptr<AbstractProductB> createProductB() = 0;
};

class ConcreteFactory: public AbstractFactory
{
public:
    ConcreteFactory(){cout << "In factory" << endl;}
    ~ConcreteFactory(){};

    shared_ptr<AbstractProductA> createProductA(){return make_shared<ProductA>();}
    shared_ptr<AbstractProductB> createProductB(){return make_shared<ProductB>();}
};



#endif

