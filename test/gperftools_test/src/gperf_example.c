#include <gperftools/profiler.h>
void func1() {
    int i = 0;
    while (i < 100000) {
        ++i;
    }
}
void func2() {
    int i = 0;
    while (i < 200000) {
        ++i;
    }
}
void func3() {
    for (int i = 0; i < 1000; ++i) {
        func1();
        func2();
    }
}
int main(){
    ProfilerStart("my.prof");
    func3();
    ProfilerStop();
    return 0;
}
