#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>

using std::cout;
using std::endl;

class Adaptee
{
public:
    Adaptee(){}
    ~Adaptee(){}

    void specialOperate(){cout << "Execute special operation" << endl;}
};

class Target
{
public:
    Target(){}
    virtual ~Target(){}

    virtual void operate(){};
};


class Adapter: public Target
{
public:
    Adapter(Adaptee* pAdaptee):adaptee_(pAdaptee){}
    ~Adapter(){}

    void operate(){adaptee_->specialOperate();}

private:
    Adaptee *adaptee_;
};


#endif
