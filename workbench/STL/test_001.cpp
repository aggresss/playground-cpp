#include <iostream>
#include <map>
#include <vector>

class Foo {
   public:
    Foo(int omicron) : omicron(omicron) {
    }

    ~Foo() {
        std::cout << "~Foo" << std::endl;
    }

    int GetOmicron() {
        return this->omicron;
    }

    void SetOmicron(int omicron) {
        this->omicron = omicron;
    }

   protected:
   private:
    int omicron{0};
};

struct Bar {
};

int main(int argc, char const* argv[]) {
    std::map<int, Foo> alpha;
    Foo* beta = nullptr;

    for (int i = 0; i < 10; i++) {
        alpha.emplace(i, i);
    }

    for (auto& kv : alpha) {
        std::cout << kv.second.GetOmicron() << std::endl;
    }

    for (auto& kv : alpha) {
        kv.second.SetOmicron(10 - kv.second.GetOmicron());
        if (kv.first == 5) {
            beta = &kv.second;
        }
    }

    beta->SetOmicron(100);

    for (auto& kv : alpha) {
        std::cout << kv.second.GetOmicron() << std::endl;
    }

    std::cout << "" << std::endl;
    return 0;
}
