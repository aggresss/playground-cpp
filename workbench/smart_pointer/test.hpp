#include <string>

class A {
   public:
    A(std::string s) {
        str = s;
        std::cout << "A constructure" << std::endl;
    }
    ~A() {
        std::cout << "A destructure: " << str << std::endl;
    }
    std::string& getStr() {
        return str;
    }
    void setStr(std::string s) {
        str = s;
    }
    void print() {
        std::cout << str << std::endl;
    }
    void deleter() {
        std::cout << "A delete " << str << std::endl;
        delete this;
    }
   private:
    std::string str;
};

struct ADeleter {
    void operator()(A* a) const { a->deleter(); }
};

class B {
   public:
    B(std::string s) {
        str = s;
        std::cout << "B constructure" << std::endl;
    }
    ~B() {
        std::cout << "B destructure: " << str << std::endl;
    }
    std::string& getStr() {
        return str;
    }
    void setStr(std::string s) {
        str = s;
    }
    void print() {
        std::cout << str << std::endl;
    }

   private:
    std::string str;
};
