#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
// string &operator+=(const char *str);             ����+=������
// string &operator+=(const char c);                ����+=������
// string &operator+=(const string &str);           ����+=������
// string &append(const char *s);                   ���ַ���s���ӵ���ǰ�ַ�����β
// string &append(const char *s, int n);            ���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
// string &append(const string &s);                 ͬoperator+=(const string& str)
// string &append(const string &s��int pos��int n); �ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β

string str1 = "hello";
string str2 = " wor";
string str3 = "ld";

void test1()
{
    str1 += str2;
    cout << str1 << endl;

    str1 += 'c';
    cout << str1 << endl;

    str1.append("hello world", 4);
    cout << str1 << endl;

    str1.append("hello world", 4, 10);
    cout << str1 << endl;
}

// - int find(const string &str, int pos = 0)const;      // ����str��һ�γ���λ��,��pos��ʼ����
// - int find(const char *s, int pos = 0)const;          // ����s��һ�γ���λ��,��pos��ʼ����
// - int find(const char *s, int pos, int n)const;       // ��posλ�ò���s��ǰn���ַ���һ��λ��
// - int find(const char c, int pos = 0)const;           // �����ַ�c��һ�γ���λ��
// - int rfind(const string &str, int pos = npos)const;  // ����str���һ��λ��,��pos��ʼ����
// - int rfind(const char *s, int pos = npos)const;      // ����s���һ�γ���λ��,��pos��ʼ����
// - int rfind(const char *s, int pos, int n)const;      // ��pos����s��ǰn���ַ����һ��λ��
// - int rfind(const char c, int pos = 0)const;          // �����ַ�c���һ�γ���λ��
// - string &replace(int pos, int n, const string &str); // �滻��pos��ʼn���ַ�Ϊ�ַ���str
// - string &replace(int pos, int n, const char *s);     // �滻��pos��ʼ��n���ַ�Ϊ�ַ���s

void test2()
{
    string str4 = str1 + str2 + str3;
    cout << str4 << endl;
    int index = str4.find("ll");
    cout << index << endl;
    index = str4.rfind("ll");
    cout << index << endl;
    str4.append("ll");
    cout << str4 << endl;
}

// - int compare(const string &s)const; // ���ַ���s�Ƚ�
// - int compare(const char *s)const;   // ���ַ���s�Ƚ�

void test3()
{
    string str4 = "asdfg";
    string str5 = "asdfg";
    int t = str4.compare(str5);
    cout << t << endl;
}

// - char &operator[](int n); // ͨ��[]��ʽȡ�ַ�
// - char &at(int n);         // ͨ��at������ȡ�ַ�

// - string &insert(int pos, const char *s);     // �����ַ���
// - string &insert(int pos, const string &str); // �����ַ���
// - string &insert(int pos, int n, char c);     // ��ָ��λ�ò���n���ַ�c
// - string &erase(int pos, int n = npos);       // ɾ����Pos��ʼ��n���ַ�

// - string substr(int pos = 0, int n = npos) const; // ������pos��ʼ��n���ַ���ɵ��ַ���

void test4()
{
    string str4 = "hello world";
    cout << str4[5] << str4.at(7) << endl;
    str4.insert(2, "sdfgh");
    cout << str4 << endl;
    str4.erase(5, 2);
    cout << str4 << endl;
    cout << str4.substr(2, 2) << endl;
}

// - vector<T> v;                // ����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
// - vector(v.begin(), v.end()); // ��v[begin(), end())�����е�Ԫ�ؿ���������
// - vector(n, elem);            // ���캯����n��elem����������
// - vector(const vector &vec);  // �������캯����

void MyPrint(int val)
{
    cout << val << " ";
}

void test5()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;

    vector<int> v2(v1.begin(), v1.end());
    for_each(v2.begin(), v2.end(), MyPrint);
    cout << endl;

    vector<int> v3(10, 100);
    for_each(v3.begin(), v3.end(), MyPrint);
    cout << endl;

    vector<int> v4(v3);
    for_each(v4.begin(), v4.end(), MyPrint);
    cout << endl;
}

// - vector &operator=(const vector &vec); // ���صȺŲ�����
// - assign(beg, end); // ��[beg, end)�����е����ݿ�����ֵ������
// - assign(n, elem);  // ��n��elem������ֵ������

void test6()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;

    vector<int> v2 = v1;
    for_each(v2.begin(), v2.end(), MyPrint);
    cout << endl;
}

// - empty();         // �ж������Ƿ�Ϊ��
// - capacity();      // ����������
// - size();          // ����������Ԫ�صĸ���
// - resize(int num); // ����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�
//                    // ���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
// - resize(int num, elem); // ����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á�
//                          // ���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��

void test7()
{
    vector<int> v1;
    bool b = v1.empty();
    cout << b << endl;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    cout << "ԭ����" << endl;
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;
    b = v1.empty();
    cout << "v1�Ƿ�Ϊ�գ�" << b << endl;
    int cap = v1.capacity();
    cout << "v1��������" << cap << endl;
    int size = v1.size();
    cout << "v1�Ĵ�С��" << size << endl
         << endl;

    cout << "����1������" << endl;
    v1.resize(17);
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;
    cap = v1.capacity();
    cout << "v1��������" << cap << endl;
    size = v1.size();
    cout << "v1�Ĵ�С��" << size << endl
         << endl;

    cout << "����1���̣�" << endl;
    v1.resize(9);
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;
    cap = v1.capacity();
    cout << "v1��������" << cap << endl;
    size = v1.size();
    cout << "v1�Ĵ�С��" << size << endl
         << endl;

    cout << "����2������" << endl;
    v1.resize(17, 6);
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;
    cap = v1.capacity();
    cout << "v1��������" << cap << endl;
    size = v1.size();
    cout << "v1�Ĵ�С��" << size << endl
         << endl;

    cout << "����2���̣�" << endl;
    v1.resize(9, 6);
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;
    cap = v1.capacity();
    cout << "v1��������" << cap << endl;
    size = v1.size();
    cout << "v1�Ĵ�С��" << size << endl
         << endl;
}

// - push_back(ele);                                  // β������Ԫ��ele
// - pop_back();                                      // ɾ�����һ��Ԫ��
// - insert(const_iterator pos, ele);                 // ������ָ��λ��pos����Ԫ��ele
// - insert(const_iterator pos, int count, ele);      // ������ָ��λ��pos����count��Ԫ��ele
// - erase(const_iterator pos);                       // ɾ��������ָ���Ԫ��
// - erase(const_iterator start, const_iterator end); // ɾ����������start��end֮���Ԫ��
// - clear();                                         // ɾ������������Ԫ��

void test8()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "ԭ����" << endl;
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;

    v1.insert(v1.begin() + 2, 8);
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;

    v1.insert(v1.begin() + 2, 3, 6);
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;

    v1.erase(v1.begin() + 2, v1.begin() + 5);
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;

    v1.erase(v1.begin() + 2);
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;

    v1.clear();
    bool b = v1.empty();
    cout << b << endl;
}

// - at(int idx); // ��������idx��ָ������
// - operator[];  // ��������idx��ָ������
// - front();     // ���������е�һ������Ԫ��
// - back();      // �������������һ������Ԫ��
void test9()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "ԭ����" << endl;
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;

    cout << v1.at(3) << endl;
    cout << v1[4] << endl;

    cout << v1.front() << " " << v1.back() << endl;
}

// - swap(vec); // ��vec�뱾���Ԫ�ػ���
void test10()
{
    vector<int> v1(3, 8);
    vector<int> v2(5, 6);
    v1.swap(v2);
    cout << "v1:" << endl;
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;

    cout << "v2:" << endl;
    for_each(v2.begin(), v2.end(), MyPrint);
    cout << endl;
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    // test8();
    // test9();
    test10();
    return 0;
}