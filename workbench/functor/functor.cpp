#include <iostream>
#include <string>

class StringAppend
{
public:
    explicit StringAppend(const std::string &str) : ss(str) {}

    void operator()(const std::string &str) const
    {
        std::cout << str << ' ' << ss << std::endl;
    }

private:
    const std::string ss;
};

int main()
{
    StringAppend myFunc("is world");
    myFunc("hello");
}
