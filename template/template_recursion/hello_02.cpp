#include <iostream>
using namespace std;

template <typename Child>
class Animal {
   public:
    void Run() {
        static_cast<Child *>(this)->Run();
    }
};

class Dog : public Animal<Dog> {
   public:
    void Run() {
        cout << "Dog Run" << endl;
    }
};

class Cat : public Animal<Cat> {
   public:
    void Run() {
        cout << "Cat Run" << endl;
    }
};

template <typename T>
void Action(Animal<T> &animal) {
    animal.Run();
}

int main() {
    Dog dog;
    Action(dog);

    Cat cat;
    Action(cat);
    return 0;
}
