#include <functional>
#include <iostream>

bool gFunc(bool send)
{
	std::cout << send << std::endl;
    return send;
}

class Admin
{
public:
    using onTest = const std::function<bool(bool)>;
    //using onTest = bool(bool);
    class foo
    {
    public:
        onTest *cb{ nullptr };
    };
};

int main()
{
	Admin::foo f;
    std::function<bool(bool)> fun = gFunc;
    f.cb = &fun;

    (*f.cb)(false);
	return 0;
}
