#include "singleton.hpp"
#include <iostream>

class Server
{
public:
    Server(int input)
        : magic(input)
    {
        std::cout<<"server.construct "<<this->magic<<std::endl;
        return;
    }
    ~Server()
    {
        std::cout<<"server.deconstruct "<<this->magic<<std::endl;
        return;
    }
    void out()
    {
        std::cout<<"server.out() "<<this->magic<<std::endl;
        return;
    }
private:
    int magic;
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

