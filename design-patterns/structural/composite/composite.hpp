#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>
#include <string>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;

class Component
{
public:
    Component(){};
    virtual ~Component(){};

    virtual void add(shared_ptr<Component> com){cout << "Operation not supported" << endl;}
    virtual void remove(shared_ptr<Component> com){cout << "Operation not supported" << endl;}
    virtual void show(int level) = 0;
    void showEmpty(int level)
    {
        int count = 4 * level;
        for (int i = 0; i < count; i++) {
            cout << " ";
        }
    }
};


class Composite : public Component
{
public:
    Composite(string sName):name_(sName){}
    ~Composite(){};
    void add(shared_ptr<Component> com){vec_.push_back(com);}
    void remove(shared_ptr<Component> com){}

    void show(int level)
    {
        showEmpty(level);
        cout << name_ << endl;
        for (vector<shared_ptr<Component>>::size_type i = 0; i != vec_.size(); i++) {
            vec_[i]->show(level + 1);
        }
    }

private:
    string name_;
    vector<shared_ptr<Component>> vec_;
};


class Leaf : public Component
{
public:
    Leaf(string sName):name_(sName){};
    ~Leaf(){};

    void show(int level)
    {
        showEmpty(level);
        cout << name_ << endl;
    }

private:
    string name_;
};


#endif

