#include <iostream>
using namespace std;
#include <functional>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>

void test1()
{
    plus<int> p;
    cout << p(10, 20) << endl;

    negate<int> n;
    cout << n(50) << endl;

    equal_to<int> eq;
    cout << eq(1, 1) << endl;
}

// - for_each       // ��������
// - transform      // ������������һ��������

void Print1(int val)
{
    cout << val << " ";
}

class Print2
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test2()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    for_each(v1.begin(), v1.end(), Print1);
    cout << endl;
    for_each(v1.begin(), v1.end(), Print2());
}

int MyAdd(int a)
{
    return a + 10;
}

void test3()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    for_each(v1.begin(), v1.end(), Print1);
    cout << endl;
    vector<int> v2;
    v2.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), MyAdd);
    for_each(v2.begin(), v2.end(), Print1);
}

// - find              // ����Ԫ��
// - find_if           // ����������Ԫ��
// - adjacent_find     // ���������ظ�Ԫ��
// - binary_search     // ���ֲ��ҷ�
// - count             // ͳ��Ԫ�ظ���
// - count_if          // ������ͳ��Ԫ�ظ���

bool my_compared(int val)
{
    return val > 5;
}
void test4()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    vector<int>::iterator it1 = find(v1.begin(), v1.end(), 67);
    cout << ((it1 == v1.end()) ? ("û�ҵ�") : ("�ҵ���")) << endl;
    vector<int>::iterator it2 = find_if(v1.begin(), v1.end(), my_compared);
    cout << ((it2 == v1.end()) ? ("û�ҵ�") : ("�ҵ���")) << endl;
    vector<int>::iterator it3 = adjacent_find(v1.begin(), v1.end());
    cout << ((it3 == v1.end()) ? ("û�ҵ�") : ("�ҵ���")) << endl;
    cout << "Ԫ�ظ�����" << count(v1.begin(), v1.end(), 7) << endl;
    cout << "����5��Ԫ�ظ�����" << count_if(v1.begin(), v1.end(), my_compared) << endl;
}

// - sort               // ��������Ԫ�ؽ�������
// - random_shuffle    // ϴ��   ָ����Χ�ڵ�Ԫ�������������
// - merge             // ����Ԫ�غϲ������洢����һ������
// - reverse           // ��תָ����Χ��Ԫ��

void test5()
{
    vector<int> v1;
    v1.push_back(5);
    v1.push_back(7);
    v1.push_back(2);
    v1.push_back(8);
    v1.push_back(0);
    v1.push_back(66);
    v1.push_back(3);

    srand((unsigned int)time(NULL));

    sort(v1.begin(), v1.end());
    cout << "first v1: "
         << "\t";
    for_each(v1.begin(), v1.end(), Print2());
    cout << endl;

    random_shuffle(v1.begin(), v1.end());
    cout << "first v1: "
         << "\t";
    for_each(v1.begin(), v1.end(), Print2());
    cout << endl;

    vector<int> v2;
    v2.push_back(34);
    v2.push_back(4);
    v2.push_back(6);
    v2.push_back(9);
    v2.push_back(11);
    v2.push_back(14);
    v2.push_back(21);

    vector<int> v3;
    v3.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << " v3 :"
         << "\t";
    for_each(v3.begin(), v3.end(), Print2());
    cout << endl;

    reverse(v3.begin(), v3.end());
    cout << " v3 :"
         << "\t";
    for_each(v3.begin(), v3.end(), Print2());
    cout << endl;
}

void test6()
{
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(5);
    cout << " v1 :"
         << "\t";
    for_each(v1.begin(), v1.end(), Print2());
    cout << endl;

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);
    cout << " v2 :"
         << "\t";
    for_each(v2.begin(), v2.end(), Print2());
    cout << endl;

    vector<int> v3;
    v3.resize(v1.size() + v2.size());
    vector<int>::iterator End = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << " v3 :"
         << "\t";
    for_each(v3.begin(), v3.end(), Print2());
    cout << endl;
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