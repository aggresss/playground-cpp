#include <iostream>

template <typename T1, typename T2>
class Data {
   public:
    Data() { std::cout << "Primary template" << std::endl; }

   private:
    T1 _d1;
    T2 _d2;
};

template <>
class Data<int, char> {
   public:
    Data() { std::cout << "Full template specialization" << std::endl; }

   private:
    int _d1;
    char _d2;
};

template <typename T1>
class Data<T1, int> {
   public:
    Data() { std::cout << "Partial template specialization" << std::endl; }

   private:
    T1 _d1;
    char _d2;
};

int main() {
    Data<int, double> d1;  // primary
    Data<int, char> d2;    // full
    Data<char, int> d3;    // partial
    return 0;
}
