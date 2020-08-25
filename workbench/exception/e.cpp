#include <iostream>
#include <exception>
using namespace std;

struct MyException : public std::exception
{
    /* const char *what() const throw() */
    virtual const char *what() const noexcept
    {
        return "C++ Exception";
    }
};

int main()
{
    try
    {
        throw MyException();
    }
    catch (MyException &e)
    {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch (std::exception &e) // catch (...)
    {
        std::cout << "Other Error" << std::endl;
    }
}
