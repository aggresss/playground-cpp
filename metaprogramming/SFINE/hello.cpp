#include <iostream>
using namespace std;
void f(double a) {
    cout << "in double f()" << endl;
}
template <typename T>
void f(typename T::noexist a) {
    cout << "in T::noexist f()" << endl;
}
int main() {
    f(1);
    f(1.0);
}