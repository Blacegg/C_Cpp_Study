#include <iostream>
using namespace std;
#include <set>
#include <vector>
#include <string>
#include <map>
#include <ctime>

template <typename T>
void Print_Set(T &st)
{
    for (typename T::iterator it = st.begin(); it != st.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test1()
{
    set<int> st;
    st.insert(10);
    st.insert(65);
    st.insert(27);
    st.insert(79);
    st.insert(40);
    st.insert(11);
    Print_Set(st);
    cout << endl;

    set<int, MyCompare> st2;
    st2.insert(10);
    st2.insert(65);
    st2.insert(27);
    st2.insert(79);
    st2.insert(40);
    st2.insert(11);
    Print_Set(st2);
    cout << endl;
}

class Compared_mt
{
public:
    bool operator()(pair<string, int> v1, pair<string, int> v2)
    {
        return v1.second > v2.second;
    }
};

void test2()
{
    set<pair<string, int>, Compared_mt> st;
    pair<string, int> p1("�����", 100);
    pair<string, int> p2("��˽�", 623);
    pair<string, int> p3("��ɮ", 30);
    pair<string, int> p4("ɳ��", 456);
    pair<string, int> p5("������", 143);
    st.insert(p5);
    st.insert(p2);
    st.insert(p3);
    st.insert(p1);
    st.insert(p4);

    for (set<pair<string, int>>::iterator it = st.begin(); it != st.end(); it++)
    {
        cout << (*it).first << "\t" << (*it).second << endl;
    }
}

#define Research_and_Development 1
#define ART 2
#define Plan 3

class Worker
{
public:
    Worker(string name, int salary) : m_Name(name), m_Salary(salary)
    {
    }
    string m_Name;
    int m_Salary;
};

void Creat_worker(vector<Worker> &v)
{
    srand((unsigned int)time(NULL));
    string worker_name = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker w((((string)"Ա��") + worker_name[i]), rand() % 10000 + 10000);
        v.push_back(w);
    }
}

void Set_Group(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        m.insert(pair<int, Worker>(1 + rand() % 3, (*it)));
    }
}

void Show_Worker(multimap<int, Worker> &m)
{
    cout << "�з����ţ�" << endl;
    multimap<int, Worker>::iterator pos = m.find(Research_and_Development);
    int num = m.count(Research_and_Development);
    int index = 0;
    for (; (pos != m.end()) && (index < num); (pos++), (index++))
    {
        cout << "������" << (*pos).second.m_Name << "\t"
             << "н�ʣ�" << (*pos).second.m_Salary << endl;
    }
    cout << "-------------------------------" << endl;

    cout << "�������ţ�" << endl;
    pos = m.find(ART);
    num = m.count(ART);
    index = 0;
    for (; (pos != m.end()) && (index < num); (pos++), (index++))
    {
        cout << "������" << (*pos).second.m_Name << "\t"
             << "н�ʣ�" << (*pos).second.m_Salary << endl;
    }
    cout << "-------------------------------" << endl;

    cout << "�߻����ţ�" << endl;
    pos = m.find(Plan);
    num = m.count(Plan);
    index = 0;
    for (; (pos != m.end()) && (index < num); (pos++), (index++))
    {
        cout << "������" << (*pos).second.m_Name << "\t"
             << "н�ʣ�" << (*pos).second.m_Salary << endl;
    }
    cout << "-------------------------------" << endl;
}

void test3()
{
    vector<Worker> v;
    multimap<int, Worker> m;
    Creat_worker(v);
    Set_Group(v, m);
    Show_Worker(m);
    system("pause");
}

void test4()
{
    string worker_name = "ABCDEFGHIJ";
    cout << worker_name << endl;
    cout << worker_name[1] << endl;
    for (int i = 0; i < 10; i++)
    {
         cout << ((string)"Ա��" + worker_name[i]) << endl;
        //cout << "Ա��" << worker_name[i] << endl;
    }
}

void test5()
{
    int num = 6;
    int d = (num++) % 6;
    cout << d << endl;
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
     test5();
     return 0;
}