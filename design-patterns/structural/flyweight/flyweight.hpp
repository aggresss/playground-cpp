#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>
#include <map>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::make_shared;
using std::shared_ptr;


class Flyweight
{
public:
    Flyweight(){}
    virtual ~Flyweight(){}

    virtual void operation(int extrinsicState) = 0;
};


class ConcreteFlyweight : public Flyweight
{
public:
    ConcreteFlyweight(string n):name(n){}
    ~ConcreteFlyweight(){}

    void operation(int extrinsicState){cout << name << " " << extrinsicState << endl;}
    void show(){}

private:
    string name;
};


class FlyweightFactory
{
public:
    FlyweightFactory(){}
    ~FlyweightFactory(){}

    shared_ptr<Flyweight> getFlyweight(string key){
        if (!pool[key]){
            pool[key] = make_shared<ConcreteFlyweight>(key);
        }
        return pool[key];
    }

private:
    map<string, shared_ptr<Flyweight> > pool;
};


#endif

