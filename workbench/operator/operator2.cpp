#include <iostream>

using namespace std;

class person
{
private:
    int age;

public:
    person(int nAge)
    {
        this->age = nAge;
    }

    bool operator==(const person &ps)
    {
        if (this->age == ps.age)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    person p1(10);
    person p2(10);

    if (p1 == p2)
    {
        cout << "p1 is equal with p2." << endl;
    }
    else
    {
        cout << "p1 is not equal with p2." << endl;
    }

    return 0;
}
