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

        void RunCb(onTest &cb)
        {
            cb(false);
        }

        void RunCbPtr(onTest *cb)
        {
            (*cb)(false);
        }
    };
};

int main()
{
	Admin::foo f;

    auto a = Admin::onTest(gFunc);
    f.cb = &a;
    (*f.cb)(false);

    auto b = new Admin::onTest(gFunc);
    f.cb = b;
    (*f.cb)(false);

    f.RunCb(gFunc);

    auto lambdaFunc = new Admin::onTest([](bool send){
	    std::cout << send << std::endl;
        return send;
    });
    f.RunCbPtr(lambdaFunc);

	return 0;
}
