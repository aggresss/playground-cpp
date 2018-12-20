#include <iostream>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cout << "parameter error" << std::endl;
        return -1;
    }

    int a, b;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    std::cout << a << " + " << b << " is " << a + b << std::endl;
    return 0;
}

