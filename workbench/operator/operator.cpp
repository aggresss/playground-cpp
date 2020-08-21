#include <iostream>

int i;
class test
{
    int k;

public:
    operator const bool() const
    {
        i = 4;
        return true;
    }
};

int main(int argc, char *argv[])
{
    test i;
    if (i)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    return 0;
}
