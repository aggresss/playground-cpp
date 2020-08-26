#include <iostream>
//#include <array>
#include <typeinfo>


using namespace std;

class Base
{
public:
    Base()
    {}
    ~Base(){}

    void dis1()
    {
        cout<<"dis1"<<endl;
    }
    void dis2()
    {
        cout<<"dis2"<<endl;
    }
};

class BaseA : private Base
{
public:
    using Base::dis1; //需要在BaseA的public下释放才能对外使用，
    void dis2show()
    {
        this->dis2();
    }
};

int main(int argc, char *argv[])
{

    BaseA ba;
    ba.dis1();
    ba.dis2show();

    return 0;
}