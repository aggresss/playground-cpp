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

class ConcreteProduct: public Product
{
public:
    ConcreteProduct(){}
    ~ConcreteProduct(){}

    string name(){return string("ConcreteProduct");}
};

class ConcreteCreator: public Creator
{
public:
    ConcreteCreator(){}
    ~ConcreteCreator(){}

    shared_ptr<Product> createProduct(){return make_shared<ConcreteProduct>();}
};

#endif

