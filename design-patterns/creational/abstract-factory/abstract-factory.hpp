#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::string;

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

class ProductA1: public AbstractProductA
{
public:
    ProductA1(){cout << "I am ProductA1" << endl;}
    ~ProductA1(){};
};

class ProductA2: public AbstractProductA
{
public:
    ProductA2(){cout << "I am ProductA2" << endl;}
    ~ProductA2(){};
};

class ProductB1: public AbstractProductB
{
public:
    ProductB1(){cout << "I am ProductB1" << endl;}
    ~ProductB1(){};
};

class ProductB2: public AbstractProductB
{
public:
    ProductB2(){cout << "I am ProductB2" << endl;}
    ~ProductB2(){};
};

class AbstractFactory
{
public:
    AbstractFactory(){};
    virtual ~AbstractFactory(){};

    virtual std::shared_ptr<AbstractProductA> createProductA() = 0;
    virtual std::shared_ptr<AbstractProductB> createProductB() = 0;
};

class ConcreteFactory1: public AbstractFactory
{
public:
    ConcreteFactory1(){cout << "In factory 1" << endl;}
    ~ConcreteFactory1(){};

    std::shared_ptr<AbstractProductA> createProductA()
    {
        return std::make_shared<ProductA1>();
    }
    std::shared_ptr<AbstractProductB> createProductB()
    {
        return std::make_shared<ProductB1>();
    }
};

class ConcreteFactory2: public AbstractFactory
{
public:
    ConcreteFactory2(){cout << "In factory 2" << endl;}
    ~ConcreteFactory2(){};

    std::shared_ptr<AbstractProductA> createProductA()
    {
        return std::make_shared<ProductA2>();
    }
    std::shared_ptr<AbstractProductB> createProductB()
    {
        return std::make_shared<ProductB2>();
    }
};

#endif

