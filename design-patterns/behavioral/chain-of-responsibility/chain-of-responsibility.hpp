#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>

using std::cout;
using std::endl;


class Handler
{
public:
    Handler(){}
    virtual ~Handler(){}

    virtual void handlerRequest(int req) = 0;
};


class ConcreteHandler1 : public Handler
{
public:
    ConcreteHandler1(Handler *s):successor(s){}
    ~ConcreteHandler1(){}

    void handlerRequest(int req)
    {
        if (req >= 0 && req < 10) {
            cout << "Handling request " << req << " in ConcreteHandler1" << endl;
        } else if (successor){
            successor->handlerRequest(req);
        } else {
            cout << "No successor handler to process this request" << endl;
        }
    }

private:
    Handler *successor;
};


class ConcreteHandler2 : public Handler
{
public:
    ConcreteHandler2(Handler *s):successor(s){}
    ~ConcreteHandler2(){}

    void handlerRequest(int req)
    {
        if (req >= 10 && req < 20) {
            cout << "Handling request " << req << " in ConcreteHandler2" << endl;
        } else if (successor){
            successor->handlerRequest(req);
        } else {
            cout << "No successor handler to process this request" << endl;
        }
    }

private:
    Handler *successor;
};


#endif

