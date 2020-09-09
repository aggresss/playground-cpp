#include <vector>

int main()
{
    int a[4] = {1, 3, 4, 2};
    int *p = a;
    std::vector<int> vInt(p, p + 4);

    return 0;
}
