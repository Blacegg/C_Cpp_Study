#include <iostream>
using namespace std;

template <typename T>
void sort(T *arr, T size)
{
    cout << "ÅÅÐò³É¹¦" << endl;
    cout << arr << endl;
    cout << size << endl;
}

class people
{
public:
    string name;
    int age;
};

template <typename Q>
void Compared(Q &t1, Q &t2)
{
    if (t1 == t2)
    {
        cout << "t1 == t2" << endl;
    }
    else
    {
        cout << "t1 != t2" << endl;
    }
}

template <>
void Compared(people &p1, people &p2)
{
    if (p1.name == p2.name && p1.age == p2.age)
    {
        cout << "p1 == p2" << endl;
        return;
    }
    cout << "p1 != p2" << endl;
    return;
} 

void test01()
{
    // int a = 10;
    // int b = 10;
    // Compared(a, b);
    people p1;
    p1.name = "1";
    p1.age = 10;
    people p2;
    p2.name = "1";
    p2.age = 10;
    Compared(p1, p2);
}

// bool operator==(people &p1, people &p2)
// {
//     if (p1.name == p2.name && p1.age == p2.age)
//     {
//         return true;
//     }
//     return false;
// }

int main()
{
    // int arr[10] = {1};
    // int size = 2;
    // sort(arr, size);
    // char arr1[10] = {'a'};
    // float a = 1.2;
    // sort(arr1, a);
    test01();

    return 0;
}