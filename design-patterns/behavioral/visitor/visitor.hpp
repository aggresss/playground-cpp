#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
public:
    Visitor(){}
    virtual ~Visitor(){}

    virtual void visitConcreteElementA(ConcreteElementA *element) = 0;
    virtual void visitConcreteElementB(ConcreteElementB *element) = 0;
};


class Element
{
public:
    Element(){}
    virtual ~Element(){}

    virtual void accept(Visitor *v) = 0;
    virtual string getName() = 0;
};


class ConcreteElementA : public Element
{
public:
    ConcreteElementA(string n): name(n){}
    ~ConcreteElementA(){}

    void accept(Visitor *v){v->visitConcreteElementA(this);}
    string getName(){return name;}

private:
    string name;
};


class ConcreteElementB : public Element
{
public:
    ConcreteElementB(string n): name(n){}
    ~ConcreteElementB(){}

    void accept(Visitor *v){v->visitConcreteElementB(this);}
    string getName(){return name;}

private:
    string name;
};


class ConcreteVisitor1 : public Visitor
{
public:
    ConcreteVisitor1(){}
    ~ConcreteVisitor1(){}

    void visitConcreteElementA(ConcreteElementA *element)
    {
        cout << "Visiting ConcreteElementA " << element->getName() << " from ConcreteVisitor1" << endl;
    }
    void visitConcreteElementB(ConcreteElementB *element)
    {
        cout << "Visiting ConcreteElementB " << element->getName() << " from ConcreteVisitor1" << endl;
    }
};


class ConcreteVisitor2 : public Visitor
{
public:
    ConcreteVisitor2(){}
    ~ConcreteVisitor2(){}

    void visitConcreteElementA(ConcreteElementA *element)
    {
        cout << "Visiting ConcreteElementA " << element->getName() << " from ConcreteVisitor2" << endl;
    }
    void visitConcreteElementB(ConcreteElementB *element)
    {
        cout << "Visiting ConcreteElementB " << element->getName() << " from ConcreteVisitor2" << endl;
    }
};


#endif
