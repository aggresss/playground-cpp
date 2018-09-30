#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::string;

class Product
{
public:
    Product(){cout<<"Product create"<<endl;}
    virtual ~Product(){cout<<"Product destroy"<<endl;}

    virtual string name() = 0;
};

class Creator
{
public:
    Creator(){cout<<"Creator create"<<endl;}
    virtual ~Creator(){cout<<"Creator destroy"<<endl;}

    virtual std::shared_ptr<Product> createProduct() = 0;
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

    std::shared_ptr<Product> createProduct()
    {
        return std::make_shared<ConcreteProduct2>();
    }
};

class ConcreteCreator2: public Creator
{
public:
    ConcreteCreator2(){}
    ~ConcreteCreator2(){}

    std::shared_ptr<Product> createProduct()
    {
        return std::make_shared<ConcreteProduct2>();
    }
};

#endif

