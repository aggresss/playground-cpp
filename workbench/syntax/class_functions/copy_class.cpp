#include <iostream>

using std::cout;
using std::endl;
class MyCppClass
{
    public:
        MyCppClass()
        {
            std::cout <<"In Default Constructor!" <<std::endl;
        }

        MyCppClass(const MyCppClass& rhs)
        {
            std::cout <<"In Copy Constructor!" <<std::endl;
        }

        MyCppClass& operator= (const MyCppClass& rhs)
        {
            std::cout <<"In Copy Assignment Operator!" <<std::endl;

            return *this;
        }
};

int main()
{
    MyCppClass testClass1;                 // default constructor
    MyCppClass testClass2(testClass1);     // copy constructor
    testClass1 = testClass2;               // copy assignment operator
    MyCppClass testClass3 = testClass1;    // copy constructor

    return 0;
}
