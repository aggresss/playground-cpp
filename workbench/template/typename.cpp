#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void print2nd(const T &container)
{
    typename T::const_iterator iter(container.begin()); //未加 typename 会报错
    ++iter;
    int value = *iter;
    std::cout << value << std::endl;
}

int main()
{
    vector<int> vi = {1, 2, 3, 4, 5};
    print2nd(vi);

    return 0;
}