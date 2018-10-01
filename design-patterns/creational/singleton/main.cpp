#include "singleton.hpp"

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class Server
{
public:
    Server(int input):nMagic_(input){cout<<"server create "<<nMagic_<<endl;}
    ~Server(){cout<<"server destroy "<<nMagic_<<endl;}

    void out()
    {cout<<"server out() "<<nMagic_<<endl;}
private:
    int nMagic_;
};

int main()
{
    auto s = std::make_unique<Server>(9);
    auto ss = Singular<Server>::Instance(8);
    auto sss = Singular<Server>::Instance(7);
    s->out();
    ss->out();
    sss->out();

    return 0;
}

