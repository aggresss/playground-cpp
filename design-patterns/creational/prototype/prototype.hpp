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

class Prototype
{
public:
    Prototype(){};
    virtual ~Prototype(){};

    virtual string name() = 0;
    virtual void setName(string newName) = 0;
    virtual shared_ptr<Prototype> clone() = 0;
};

class ConcretePrototype: public Prototype
{
public:
    ConcretePrototype(string n):myName_(n){}
    ~ConcretePrototype(){};
    ConcretePrototype(const ConcretePrototype &other):myName_(other.myName_){}

    string name(){return myName_;}
    void setName(string newName){myName_ = newName;}
    shared_ptr<Prototype> clone(){return make_shared<ConcretePrototype>(*this);}

private:
    string myName_;
};

#endif

