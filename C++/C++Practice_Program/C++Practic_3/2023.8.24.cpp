#include <iostream>
using namespace std;

class people
{
public:
    int age;
    people()
    {
    }
    people(int age) : age(age)
    {
    }
    people(people &p)
    {
        age = p.age;
        cout << this->age << endl;
    }
    people& ageadd(people &p)
    {
        this->age += p.age;
        return *this;
    }
};

int main()
{
    people p1(10);
    cout << "p1ÄêÁä£º" << p1.age << endl;
    people p2(10);

    people p3 = p2.ageadd(p1).ageadd(p1).ageadd(p1);
    cout << "p2ÄêÁä£º" << p2.age << endl;
    cout << "p3ÄêÁä£º" << p3.age << endl;

    return 0;
}