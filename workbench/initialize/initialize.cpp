#include <string>
#include <array>
struct S
{
    int x;
    struct Foo
    {
        int i;
        int j;
        int a[3];
    } b;
};

int main()
{
    S s1 = {1, {2, 3, {4, 5, 6}}};
    S s2 = {1, 2, 3, 4, 5, 6};  // same, but with brace elision
    S s3{1, {2, 3, {4, 5, 6}}}; // same, using direct-list-initialization syntax
}