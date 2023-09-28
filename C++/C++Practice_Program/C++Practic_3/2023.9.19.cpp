#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>

// - push_back(elem);  // ������β�����һ������
// - push_front(elem); // ������ͷ������һ������
// - pop_back();       // ɾ���������һ������
// - pop_front();      // ɾ��������һ������

// ָ��λ�ò�����

// - insert(pos, elem);     // ��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
// - insert(pos, n, elem);  // ��posλ�ò���n��elem���ݣ��޷���ֵ��
// - insert(pos, beg, end); // ��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
// - clear();               // �����������������
// - erase(beg, end);       // ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
// - erase(pos);            // ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�

void test1()
{
    deque<int> d1;
    bool isempty = d1.empty();
    cout << ((isempty == true) ? "d1 Ϊ��" : "d1 ��Ϊ��") << endl;
    int dsize = d1.size();
    cout << "d1 �Ĵ�СΪ��" << dsize << endl;

    cout << "push_back�����" << endl;
    for (int i = 0; i < 10; i++)
    {
        d1.push_front(i);
    }
    isempty = d1.empty();
    cout << ((isempty == true) ? "d1 Ϊ��" : "d1 ��Ϊ��") << endl;
    dsize = d1.size();
    cout << "d1 �Ĵ�СΪ��" << dsize << endl;
}

void PrintDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test2()
{
    deque<int> d1;
    d1.push_back(100);
    d1.push_back(20);
    d1.push_back(80);
    d1.push_back(0);
    d1.push_back(40);
    PrintDeque(d1);

    sort(d1.begin(), d1.end());
    PrintDeque(d1);
}

class people
{
public:
    string m_Name;
    int m_Age;
    deque<int> score;
    float m_average_score;
    people() {}
    people(string name, int age) : m_average_score(0)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
};

void get_people_info(vector<people> &v1)
{
    cout << "������ѡ����Ϣ��" << endl;
    cout << "������ѡ��������" << endl;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        people temp;
        cout << "������� " << i + 1 << " λѡ��������" << endl;
        cin >> temp.m_Name;
        cout << "������� " << i + 1 << "λѡ�����䣺" << endl;
        cin >> temp.m_Age;
        v1.push_back(temp);
        cout << endl;
    }
    cout << "ѡ����Ϣ������" << endl;
}

void set_score(vector<people> &v1)
{
    for (vector<people>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        for (int i = 0; i < 10; i++)
        {
            int temp_score;
            cout << "������� " << i + 1 << " �����֣�";
            cin >> temp_score;
            (*it).score.push_back(temp_score);
            cout << endl;
        }
        cout << endl;
    }
    cout << "��ֽ�����" << endl;
}

void calculate_score(vector<people> &v)
{
    int sum = 0;
    float average_score = 0;
    for (vector<people>::iterator it = v.begin(); it != v.end(); it++)
    {
        sort((*it).score.begin(), (*it).score.end());
        for (deque<int>::iterator qit = (*it).score.begin() + 1; qit != (*it).score.end() - 1; qit++)
        {
            sum += *qit;
        }
        average_score = sum / 8.0;
        (*it).m_average_score = average_score;
    }
}
void print_score_info(vector<people> &v)
{
    cout << endl;
    for (vector<people>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "������" << (*it).m_Name << "\t"
             << "���䣺" << (*it).m_Age << "     "
             << "�÷֣�" << (*it).m_average_score << endl;
    }
    cout << endl;
}

void test3()
{
    vector<people> v;
    get_people_info(v);
    set_score(v);
    calculate_score(v);
    print_score_info(v);
}

// ���캯����

// - stack<T> stk;            // stack����ģ����ʵ�֣� stack�����Ĭ�Ϲ�����ʽ
// - stack(const stack &stk); // �������캯��

// ��ֵ������

// - stack &operator=(const stack &stk); // ���صȺŲ�����

// ���ݴ�ȡ��

// - push(elem); // ��ջ�����Ԫ��
// - pop();      // ��ջ���Ƴ���һ��Ԫ��
// - top();      // ����ջ��Ԫ��

// ��С������

// - empty(); // �ж϶�ջ�Ƿ�Ϊ��
// - size();  // ����ջ�Ĵ�С

void test4()
{
    stack<int> stk;
    bool stk_isempty = stk.empty();
    int stk_size = stk.size();
    cout << ((stk_isempty == true) ? "stkΪ��" : "stk��Ϊ��") << endl;
    cout << "stk�Ĵ�С:" << stk_size << endl;
    for (int i = 0; i < 10; i++)
    {
        stk.push(i);
    }
    stk_isempty = stk.empty();
    stk_size = stk.size();
    cout << ((stk_isempty == true) ? "stkΪ��" : "stk��Ϊ��") << endl;
    cout << "stk�Ĵ�С:" << stk_size << endl;
    stack<int> stk1(stk);
    stk_isempty = stk1.empty();
    stk_size = stk1.size();
    cout << ((stk_isempty == true) ? "stk1Ϊ��" : "stk1��Ϊ��") << endl;
    cout << "stk1�Ĵ�С:" << stk_size << endl;
    int stk_top = stk1.top();
    cout << "stk1��ջ����" << stk_top << endl;
    stk_isempty = stk1.empty();
    stk_size = stk1.size();
    cout << ((stk_isempty == true) ? "stkΪ��" : "stk��Ϊ��") << endl;
    cout << "stk�Ĵ�С:" << stk_size << endl;
    stk1.pop();
    cout << "stk1�ĳ�ջ" << endl;
    stk_isempty = stk1.empty();
    stk_size = stk1.size();
    cout << ((stk_isempty == true) ? "stkΪ��" : "stk��Ϊ��") << endl;
    cout << "stk�Ĵ�С:" << stk_size << endl;
}

// ���캯����

// - queue<T> que;            // queue����ģ����ʵ�֣�queue�����Ĭ�Ϲ�����ʽ
// - queue(const queue &que); // �������캯��

// ��ֵ������

// - queue &operator=(const queue &que); // ���صȺŲ�����

// ���ݴ�ȡ��

// - push(elem); // ����β���Ԫ��
// - pop();      // �Ӷ�ͷ�Ƴ���һ��Ԫ��
// - back();     // �������һ��Ԫ��
// - front();    // ���ص�һ��Ԫ��

// ��С������

// - empty(); // �ж϶�ջ�Ƿ�Ϊ��
// - size();  // ����ջ�Ĵ�С

void test5()
{
    queue<int> que1;
    queue<int> que2;
    que1.swap(que2);

    vector<int> v1;
    vector<int> v2;
    v1.swap(v2);

    string s1;
    string s2;
    s1.swap(s2);

    deque<int> deq1;
    deque<int> deq2;
    deq1.swap(deq2);

    list<int> l1;
    list<int> l2;
    l1.swap(l2);
}

// - push_back(elem);       // ������β������һ��Ԫ��
// - pop_back();            // ɾ�����������һ��Ԫ��
// - push_front(elem);      // ��������ͷ����һ��Ԫ��
// - pop_front();           // ��������ͷ�Ƴ���һ��Ԫ��
// - insert(pos, elem);     // ��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
// - insert(pos, n, elem);  // ��posλ�ò���n��elem���ݣ��޷���ֵ��
// - insert(pos, beg, end); // ��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
// - clear();               // �Ƴ���������������
// - erase(beg, end);       // ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
// - erase(pos);            // ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
// - remove(elem);          // ɾ��������������elemֵƥ���Ԫ�ء�

void print_list(list<int> &l)
{
    for (list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}

void test6()
{
    list<int> list1;
    for (int i = 0; i < 10; i++)
    {
        list1.push_back(i);
    }
    list1.push_front(-1);
    print_list(list1);

    list1.pop_front();
    list1.pop_back();
    print_list(list1);

    list1.insert(++list1.begin(), 20);
    int i = 0;
    int j = i++ + i;
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();
    return 0;
}