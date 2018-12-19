#include <stdio.h>
int ppp(int a)
{
    int i, b;
    b = 0;
    for(i = 0; i<1000000; i++) {
        b++;
    }
    return 0;
}


int prime(int n)
{
    int i, j, b;
    b = 0;
    for(i=2; i<n; i++) {
        for(j = 0; j<1000000; j++) {
            b++;
        }
        if(n%i == 0)
            return 0;
        return 1;
    }
}


int main(void)
{
    int i, n;
    n = 1000;
    for(i=2; i<=n; i++) {
        if(prime(i)) {
            ppp(i);
        }
    }
    return 0;
}
