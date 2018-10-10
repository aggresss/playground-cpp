#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>
#include <map>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::string;


class Subject
{
public:
    Subject(){}
    virtual ~Subject(){}

    virtual void operation() = 0;
};


class Proxy : public Subject
{
public:
    Proxy(Subject *sub):subject(sub){}
    ~Proxy(){}

    void operation()
    {
        cout << "Executing operation in Proxy" << endl;
        subject->operation();
    }

private:
    Subject *subject;
};


class RealSubject : public Subject
{
public:
    RealSubject(){}
    ~RealSubject(){}

    void operation(){cout << "Executing operation in RealSubject" << endl;}
};


#endif

