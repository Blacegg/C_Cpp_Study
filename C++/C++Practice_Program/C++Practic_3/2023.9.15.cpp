#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void MyPrint(int val)
{
    cout << val << endl;
}

void test1(int way)
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    vector<int>::iterator pBegin = v.begin();
    vector<int>::iterator pEnd = v.end();

    switch (way)
    {
    case 1:
        cout << "����һ" << endl;
        while (pBegin != pEnd)
        {
            cout << *pBegin << endl;
            pBegin++;
        }
        break;

    case 2:
        cout << "������" << endl;
        for (vector<int>::iterator it = pBegin; it != pEnd; it++)
        {
            cout << *it << endl;
        }
        break;

    case 3:
        cout << "������" << endl;
        for_each(v.begin(), v.end(), MyPrint);
        break;
    default:
        break;
    }
}

class people
{
public:
    string m_Name;
    int m_Age;
    people(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
};

void MyPrintPeople(const people &p)
{
    cout << p.m_Name << "\t" << p.m_Age << endl;
}

void test2(int way)
{
    vector<people> p;
    people p1("�����", 30);
    people p2("����", 20);
    people p3("槼�", 18);
    people p4("���Ѿ�", 15);
    people p5("����", 24);

    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    p.push_back(p5);

    vector<people>::iterator pBegin = p.begin();
    vector<people>::iterator pEnd = p.end();

    switch (way)
    {
    case 1:
        cout << "����һ" << endl;
        while (pBegin != pEnd)
        {
            MyPrintPeople(*pBegin);
            pBegin++;
        }
        break;
    case 2:
        cout << "������" << endl;
        for (vector<people>::iterator it = p.begin(); it != p.end(); it++)
        {
            MyPrintPeople(*it);
        }
        break;
    case 3:
        cout << "������" << endl;
        for_each(p.begin(), p.end(), MyPrintPeople);
        break;
    default:
        break;
    }
}

void test3()
{
    vector<vector<int>> v;
    vector<int> p1;
    vector<int> p2;
    vector<int> p3;

    for (int i = 0; i < 3; i++)
    {
        p1.push_back(i + 1);
        p2.push_back(i + 2);
        p3.push_back(i + 3);
    }

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    for (vector<vector<int>>::iterator it1 = v.begin(); it1 != v.end(); it1++)
    {
        for (vector<int>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
        {
            cout << (*it2) << " ";
        }
        cout << endl;
    }
}

// string();                        ����һ���յ��ַ��� ����: string str;
// string(const char *s);           ʹ���ַ���s��ʼ��
// string(const string &str);       ʹ��һ��string�����ʼ����һ��string����
// string(int n, char c);           ʹ��n���ַ�c��ʼ��

void test4()
{
    string str1;
    cout << "str1 = " << str1 << endl;

    const char *str = "hello world";
    string str2(str);
    cout << "str2 = " << str2 << endl;

    string str3(str2);
    cout << "str3 = " << str3 << endl;

    string str4(5, 'c');
    cout << "str4 = " << str4 << endl;
}

// string &operator=(const char *s);        char*�����ַ��� ��ֵ����ǰ���ַ���
// string &operator=(const string &s);      ���ַ���s������ǰ���ַ���
// string &operator=(char c);               �ַ���ֵ����ǰ���ַ���
// string &assign(const char *s);           ���ַ���s������ǰ���ַ���
// string &assign(const char *s, int n);    ���ַ���s��ǰn���ַ�������ǰ���ַ���
// string &assign(const string &s);         ���ַ���s������ǰ�ַ���
// string &assign(int n, char c);           ��n���ַ�c������ǰ�ַ���

void test5()
{
    char a = '1';
    cout << a + 1 << endl;
    cout << sizeof(a + 1) << endl;

    char b = 5;
    char c = 126;
    int e = b + c;
    char d = b + c;
    cout << (int)d << endl;
    cout << "eΪ��" << e << endl;
}

int main()
{
    // test1(3);
    // test2(3);
    // test3();
    // test4();
    // test5();
}