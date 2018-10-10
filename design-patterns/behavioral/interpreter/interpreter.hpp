#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>

using std::cout;
using std::endl;


class Context
{
public:
    Context(): toUpper(false), toLower(false){}
    ~Context(){}

    void setToLower(bool v){toLower = v;}
    bool getToLower(){ return toLower; }
    void setToUpper(bool v){toUpper = v;}
    bool getToUpper(){ return toUpper; }

private:
    bool toUpper;
    bool toLower;
};


class AbstractExpression
{
public:
    AbstractExpression(){}
    virtual ~AbstractExpression(){}

    virtual void interpret(Context *c) = 0;
};


class NonTerminalExpression : public AbstractExpression
{
public:
    NonTerminalExpression(char v): value(v){}
    ~NonTerminalExpression(){}

    void interpret(Context *c)
    {
        switch (value)
        {
        case '+':
            c->setToLower(false);
            c->setToUpper(true);
            break;
        case '-':
            c->setToLower(true);
            c->setToUpper(false);
            break;
        default:
            cout << "Unknown non treminal expression" << endl;
            break;
        }
    }

private:
    char value;
};


class TerminalExpression : public AbstractExpression
{
public:
    TerminalExpression(char v): value(v){}
    ~TerminalExpression(){}

    void interpret(Context *c)
    {
        if (c->getToLower())
        {
            cout << (char)tolower(value);
        }
        else if (c->getToUpper())
        {
            cout << (char)toupper(value);
        }
        else
        {
            cout << value;
        }
    }

private:
    char value;
};


#endif
