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
        cout << "方法一" << endl;
        while (pBegin != pEnd)
        {
            cout << *pBegin << endl;
            pBegin++;
        }
        break;

    case 2:
        cout << "方法二" << endl;
        for (vector<int>::iterator it = pBegin; it != pEnd; it++)
        {
            cout << *it << endl;
        }
        break;

    case 3:
        cout << "方法三" << endl;
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
    people p1("孙悟空", 30);
    people p2("韩信", 20);
    people p3("妲己", 18);
    people p4("王昭君", 15);
    people p5("赵云", 24);

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
        cout << "方法一" << endl;
        while (pBegin != pEnd)
        {
            MyPrintPeople(*pBegin);
            pBegin++;
        }
        break;
    case 2:
        cout << "方法二" << endl;
        for (vector<people>::iterator it = p.begin(); it != p.end(); it++)
        {
            MyPrintPeople(*it);
        }
        break;
    case 3:
        cout << "方法三" << endl;
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

// string();                        创建一个空的字符串 例如: string str;
// string(const char *s);           使用字符串s初始化
// string(const string &str);       使用一个string对象初始化另一个string对象
// string(int n, char c);           使用n个字符c初始化

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

// string &operator=(const char *s);        char*类型字符串 赋值给当前的字符串
// string &operator=(const string &s);      把字符串s赋给当前的字符串
// string &operator=(char c);               字符赋值给当前的字符串
// string &assign(const char *s);           把字符串s赋给当前的字符串
// string &assign(const char *s, int n);    把字符串s的前n个字符赋给当前的字符串
// string &assign(const string &s);         把字符串s赋给当前字符串
// string &assign(int n, char c);           用n个字符c赋给当前字符串

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
    cout << "e为：" << e << endl;
}

int main()
{
    // test1(3);
    // test2(3);
    // test3();
    // test4();
    // test5();
}