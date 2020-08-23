class Parents
{
public:
    virtual ~Parents() {}
    /*codes here*/
};

class Children : public Parents
{
    /*codes here*/
};

int main()
{
    Children *daughter = new Children();
    Parents *mother = static_cast<Parents *>(daughter); //right, cast with polymorphism

    Parents *father = new Parents();
    Children *son = static_cast<Children *>(father); //no error, but not safe
}