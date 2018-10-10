#ifndef __XXXX_H__
#define __XXXX_H__

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::enable_shared_from_this;


class Iterator
{
public:
    Iterator(){}
    virtual ~Iterator(){}

    virtual int first() = 0;
    virtual int next() = 0;
    virtual bool isDone() = 0;
    virtual int currentItem() = 0;
};


class Aggregate
{
public:
    Aggregate(){}
    virtual ~Aggregate(){}

    virtual shared_ptr<Iterator> createIterator() = 0;
};

class ConcreteAggregate : public Aggregate, public enable_shared_from_this<ConcreteAggregate>
{
public:
    ConcreteAggregate(): currentIndex(0){}
    ~ConcreteAggregate(){}

    void addItem(int value){array[currentIndex++] = value;}
    int getItem(int index){return array[index];}
    shared_ptr<Iterator> createIterator();
    int size() {return currentIndex;}

private:
    int array[100];
    int currentIndex;
};

class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(shared_ptr<ConcreteAggregate> a): aggregate(a), aggregateSize(a->size()), currentIndex(0){}
    ~ConcreteIterator(){}

    int first(){return aggregate->getItem(0);}
    int next(){return aggregate->getItem(currentIndex++);}
    bool isDone(){return currentIndex >= aggregateSize;}
    int currentItem(){return aggregate->getItem(currentIndex);}

private:
    shared_ptr<ConcreteAggregate> aggregate;
    int aggregateSize;
    int currentIndex;
};


shared_ptr<Iterator> ConcreteAggregate::createIterator()
{
    return make_shared<ConcreteIterator>(shared_from_this());
}


#endif
