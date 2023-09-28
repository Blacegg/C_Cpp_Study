#include <iostream>
using namespace std;
#include <list>
#include <set>

class Person
{
public:
    Person(string name, int age, int height) : m_Name(name), m_Age(age), m_Height(height)
    {
    }
    string m_Name;
    int m_Age;
    int m_Height;
};

void Print_List(list<Person> &l)
{
    for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << (*it).m_Name << "\t" << (*it).m_Age << "\t" << (*it).m_Height << endl;
    }
}

bool Compared_Person(Person &p1, Person &p2)
{
    if (p1.m_Age == p2.m_Age)
    {
        return p1.m_Height < p2.m_Height;
    }
    else
    {
        return p1.m_Age < p2.m_Age;
    }
}

void test1()
{
    Person p1("p1", 23, 123);
    Person p2("p2", 20, 12);
    Person p3("p3", 45, 128);
    Person p4("p4", 23, 126);

    list<Person> l1;
    l1.push_back(p1);
    l1.push_back(p2);
    l1.push_back(p3);
    l1.push_back(p4);

    Print_List(l1);
    cout << endl;
    l1.sort(Compared_Person);
    Print_List(l1);
}

void Print_Set(set<int> &st)
{
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}

void test2()
{
    set<int> st;

    st.insert(65);
    st.insert(27);
    st.insert(79);
    st.insert(40);
    st.insert(11);
    Print_Set(st);

    cout << endl;
    set<int> st2(st);
    Print_Set(st2);

    set<int> st3;
    st3 = st;
    Print_Set(st2);
}

void test3()
{
    set<int> st;

    st.insert(65);
    st.insert(27);
    st.insert(79);
    st.insert(40);
    st.insert(11);
    Print_Set(st);

    cout << st.size() << endl;
}

// - insert(elem);    // 在容器中插入元素。
// - clear();         // 清除所有元素
// - erase(pos);      // 删除pos迭代器所指的元素，返回下一个元素的迭代器。
// - erase(beg, end); // 删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
// - erase(elem);     // 删除容器中值为elem的元素。

void test4()
{
}

int main()
{
    // test1();
    // test2();
    // test3();
    test4();
}