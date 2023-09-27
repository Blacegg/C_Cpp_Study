#include <iostream>
using namespace std;

class people
{
public:
    int age;
    int no;
    // people operator+(people &p)
    // {
    //     people *temp = new people;
    //     temp->age = this->age + p.age;
    //     temp->no = this->no + p.no;
    //     cout << p.age << "\t" << p.no << endl;
    //     return *temp;
    // }

    // void operator<<(people &p)
    // {
    //     cout <<
    // }

    people(int a, int b)
    {
        age = a;
        no = b;
    }
};

// void test01(void)
// {
//     people p;
//     p.age = 10;
//     p.no = 10;
//     people p2;
//     p2 = p + p;
//     people p3;
//     p3 = p + p2;
//     // cout << "p2.age = " << p2.age << endl;
//     // cout << "p2.no = " << p2.no << endl;
// }

people operator+(people &a, people &b)
{
    people temp(0, 0);
    temp.age = a.age + b.age;
    temp.no = a.no + b.no;
    cout << "a.age = " << a.age << endl;
    cout << "b.age = " << b.age << endl;
    return temp;
}
void test02(void)
{
    people p(10, 10);
    people p2(20, 20);
    people p3(0, 0);
    p3 = p2 + p;
    cout << "p3.age = " << p3.age << endl;
    cout << "p3.no = " << p3.no << endl;
}
void test03(void)
{
    people p = people(10, 20);
    // cout << p << endl;
    cout << p.age << "\t" << p.no << endl;
}
int main()
{
    test03();
    return 0;
}