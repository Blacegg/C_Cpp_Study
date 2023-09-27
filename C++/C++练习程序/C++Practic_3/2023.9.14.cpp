#include <iostream>
#include "2023.9.13.hpp"
using namespace std;

void printInAarray(MyArray<int> &array1)
{
    for (int i = 0; i < array1.GetSize(); i++)
    {
        cout << array1[i] << " ";
    }
    cout << endl;
}

void test1()
{
    MyArray<int> array1(10);
    for (int i = 0; i < array1.GetCapacity(); i++)
    {
        array1.Push_back(i);
    }
    cout << "array1�Ĵ�ӡ�����" << endl;
    printInAarray(array1);
    cout << "array1�Ĵ�С" << array1.GetSize() << endl;
    cout << "array1������" << array1.GetCapacity() << endl;

    cout << "________________________________" << endl;

    MyArray<int> array2(array1);
    array2.Pop_back();
    printInAarray(array2);
    cout << "array2�Ĵ�С" << array2.GetSize() << endl;
    cout << "array2������" << array2.GetCapacity() << endl;
}

class people
{
    friend void printPersonArray(MyArray<people> &personArr);

public:
    people()
    {
    }
    people(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

private:
    string m_Name;
    int m_Age;
};

void printPersonArray(MyArray<people> &personArr)
{
    for (int i = 0; i < personArr.GetSize(); i++)
    {
        cout << "������" << personArr[i].m_Name << " ���䣺 " << personArr[i].m_Age << endl;
    }
}

void test2()
{
    MyArray<people> pArray(10);
    people p1("�����", 30);
    people p2("����", 20);
    people p3("槼�", 18);
    people p4("���Ѿ�", 15);
    people p5("����", 24);

    pArray.Push_back(p1);
    pArray.Push_back(p2);
    pArray.Push_back(p3);
    pArray.Push_back(p4);
    pArray.Push_back(p5);

    printPersonArray(pArray);

    cout << "pArray�Ĵ�С��" << pArray.GetSize() << endl;
    cout << "pArray��������" << pArray.GetCapacity() << endl;
}

int main()
{
    // test1();
    test2();
}