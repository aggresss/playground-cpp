#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

class Product
{
public:
    Product(){}
    virtual ~Product(){}

    virtual string name() = 0;
};

class Creator
{
public:
    Creator(){}
    virtual ~Creator(){}

    virtual Product *createProduct() = 0;
};

class ConcreteProduct1: public Product
{
public:
    ConcreteProduct1(){}
    ~ConcreteProduct1(){}

    string name()
    {
        return string("ConcreteProduct1");
    }
};

class ConcreteProduct2: public Product
{
public:
    ConcreteProduct2(){}
    ~ConcreteProduct2(){}

    string name()
    {
        return string("ConcreteProduct2");
    }
};

class ConcreteCreator1: public Creator
{
public:
    ConcreteCreator1(){}
    ~ConcreteCreator1(){}

    Product *createProduct()
    {
        return new ConcreteProduct1;
    }
};

class ConcreteCreator2: public Creator
{
public:
    ConcreteCreator2(){}
    ~ConcreteCreator2(){}

    Product *createProduct()
    {
        return new ConcreteProduct2;
    }
};

#endif

