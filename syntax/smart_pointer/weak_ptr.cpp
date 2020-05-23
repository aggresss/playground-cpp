#include <memory>
#include <iostream>
using namespace std;

class B;
class A
{
public:
    weak_ptr<B> pb_;
    // shared_ptr<B> pb_;
    ~A()
    {
        cout<<"A delete\n";
    }
};
class B
{
public:
    shared_ptr<A> pa_;
    ~B()
    {
        cout<<"B delete\n";
    }
};

void fun()
{
    shared_ptr<B> pb(new B());
    shared_ptr<A> pa(new A());
    pb->pa_ = pa;
    pa->pb_ = pb;
    cout<<pb.use_count()<<endl;
    cout<<pa.use_count()<<endl;
}

int main()
{
    fun();
    return 0;
}
