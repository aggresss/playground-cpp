#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;

class Product
{
public:
    Product(){};
    ~Product(){};

    void addPart(string newPart){vecParts_.push_back(newPart);}
    void showProduct()
    {
        for (vector<string>::const_iterator it = vecParts_.begin(); it != vecParts_.end(); ++it)
        {
            cout << *it << endl;
        }
    }

private:
    vector<string> vecParts_;
};

class AbstractBuilder
{
public:
    AbstractBuilder(){};
    virtual ~AbstractBuilder(){};

    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual shared_ptr<Product> getProduct() = 0;
};

class ConcreteBuilder: public AbstractBuilder
{
public:
    ConcreteBuilder(){product = make_shared<Product>();}
    ~ConcreteBuilder(){}

    void buildPartA(){product->addPart(string("PartA from builder"));}
    void buildPartB(){product->addPart(string("PartB from builder"));}
    void buildPartC(){product->addPart(string("PartC from builder"));}
    shared_ptr<Product> getProduct(){return product;}

private:
    shared_ptr<Product> product;
};

class Director
{
public:
    Director(AbstractBuilder *builder){this->builder = builder;}
    ~Director(){};

    void buildProduct()
    {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }
    void setBuilder(AbstractBuilder *builder){this->builder = builder;}

private:
    AbstractBuilder *builder;
};

#endif
