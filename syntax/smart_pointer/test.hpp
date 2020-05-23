#include <string>

class A
{
public:
    A(std::string s)
    {
        str = s;
        std::cout<<"A create"<<std::endl;
    }
    ~A()
    {
        std::cout<<"A delete:"<<str<<std::endl;
    }
    std::string& getStr()
    {
        return str;
    }
    void setStr(std::string s)
    {
        str = s;
    }
    void print()
    {
        std::cout<<str<<std::endl;
    }
private:
    std::string str;
};

class B
{
public:
    B(std::string s)
    {
        str = s;
        std::cout<<"B create"<<std::endl;
    }
    ~B()
    {
        std::cout<<"B delete:"<<str<<std::endl;
    }
    std::string& getStr()
    {
        return str;
    }
    void setStr(std::string s)
    {
        str = s;
    }
    void print()
    {
        std::cout<<str<<std::endl;
    }
private:
    std::string str;
};


