#include "proxy.hpp"

#include <memory>

using std::make_shared;

int main()
{
    auto sub = make_shared<RealSubject>();
    auto proxy = make_shared<Proxy>(sub.get());

    proxy->operation();
    
    return 0;
}
