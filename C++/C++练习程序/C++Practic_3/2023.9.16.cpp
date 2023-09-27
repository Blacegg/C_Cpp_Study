#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
// string &operator+=(const char *str);             重载+=操作符
// string &operator+=(const char c);                重载+=操作符
// string &operator+=(const string &str);           重载+=操作符
// string &append(const char *s);                   把字符串s连接到当前字符串结尾
// string &append(const char *s, int n);            把字符串s的前n个字符连接到当前字符串结尾
// string &append(const string &s);                 同operator+=(const string& str)
// string &append(const string &s，int pos，int n); 字符串s中从pos开始的n个字符连接到字符串结尾

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

// - int find(const string &str, int pos = 0)const;      // 查找str第一次出现位置,从pos开始查找
// - int find(const char *s, int pos = 0)const;          // 查找s第一次出现位置,从pos开始查找
// - int find(const char *s, int pos, int n)const;       // 从pos位置查找s的前n个字符第一次位置
// - int find(const char c, int pos = 0)const;           // 查找字符c第一次出现位置
// - int rfind(const string &str, int pos = npos)const;  // 查找str最后一次位置,从pos开始查找
// - int rfind(const char *s, int pos = npos)const;      // 查找s最后一次出现位置,从pos开始查找
// - int rfind(const char *s, int pos, int n)const;      // 从pos查找s的前n个字符最后一次位置
// - int rfind(const char c, int pos = 0)const;          // 查找字符c最后一次出现位置
// - string &replace(int pos, int n, const string &str); // 替换从pos开始n个字符为字符串str
// - string &replace(int pos, int n, const char *s);     // 替换从pos开始的n个字符为字符串s

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

// - int compare(const string &s)const; // 与字符串s比较
// - int compare(const char *s)const;   // 与字符串s比较

void test3()
{
    string str4 = "asdfg";
    string str5 = "asdfg";
    int t = str4.compare(str5);
    cout << t << endl;
}

// - char &operator[](int n); // 通过[]方式取字符
// - char &at(int n);         // 通过at方法获取字符

// - string &insert(int pos, const char *s);     // 插入字符串
// - string &insert(int pos, const string &str); // 插入字符串
// - string &insert(int pos, int n, char c);     // 在指定位置插入n个字符c
// - string &erase(int pos, int n = npos);       // 删除从Pos开始的n个字符

// - string substr(int pos = 0, int n = npos) const; // 返回由pos开始的n个字符组成的字符串

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

// - vector<T> v;                // 采用模板实现类实现，默认构造函数
// - vector(v.begin(), v.end()); // 将v[begin(), end())区间中的元素拷贝给本身。
// - vector(n, elem);            // 构造函数将n个elem拷贝给本身。
// - vector(const vector &vec);  // 拷贝构造函数。

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

// - vector &operator=(const vector &vec); // 重载等号操作符
// - assign(beg, end); // 将[beg, end)区间中的数据拷贝赋值给本身。
// - assign(n, elem);  // 将n个elem拷贝赋值给本身。

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

// - empty();         // 判断容器是否为空
// - capacity();      // 容器的容量
// - size();          // 返回容器中元素的个数
// - resize(int num); // 重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
//                    // 如果容器变短，则末尾超出容器长度的元素被删除。
// - resize(int num, elem); // 重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
//                          // 如果容器变短，则末尾超出容器长度的元素被删除

void test7()
{
    vector<int> v1;
    bool b = v1.empty();
    cout << b << endl;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    cout << "原本：" << endl;
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;
    b = v1.empty();
    cout << "v1是否为空：" << b << endl;
    int cap = v1.capacity();
    cout << "v1的容量：" << cap << endl;
    int size = v1.size();
    cout << "v1的大小：" << size << endl
         << endl;

    cout << "方法1增长：" << endl;
    v1.resize(17);
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;
    cap = v1.capacity();
    cout << "v1的容量：" << cap << endl;
    size = v1.size();
    cout << "v1的大小：" << size << endl
         << endl;

    cout << "方法1缩短：" << endl;
    v1.resize(9);
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;
    cap = v1.capacity();
    cout << "v1的容量：" << cap << endl;
    size = v1.size();
    cout << "v1的大小：" << size << endl
         << endl;

    cout << "方法2增长：" << endl;
    v1.resize(17, 6);
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;
    cap = v1.capacity();
    cout << "v1的容量：" << cap << endl;
    size = v1.size();
    cout << "v1的大小：" << size << endl
         << endl;

    cout << "方法2缩短：" << endl;
    v1.resize(9, 6);
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;
    cap = v1.capacity();
    cout << "v1的容量：" << cap << endl;
    size = v1.size();
    cout << "v1的大小：" << size << endl
         << endl;
}

// - push_back(ele);                                  // 尾部插入元素ele
// - pop_back();                                      // 删除最后一个元素
// - insert(const_iterator pos, ele);                 // 迭代器指向位置pos插入元素ele
// - insert(const_iterator pos, int count, ele);      // 迭代器指向位置pos插入count个元素ele
// - erase(const_iterator pos);                       // 删除迭代器指向的元素
// - erase(const_iterator start, const_iterator end); // 删除迭代器从start到end之间的元素
// - clear();                                         // 删除容器中所有元素

void test8()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "原本：" << endl;
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

// - at(int idx); // 返回索引idx所指的数据
// - operator[];  // 返回索引idx所指的数据
// - front();     // 返回容器中第一个数据元素
// - back();      // 返回容器中最后一个数据元素
void test9()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "原本：" << endl;
    for_each(v1.begin(), v1.end(), MyPrint);
    cout << endl;

    cout << v1.at(3) << endl;
    cout << v1[4] << endl;

    cout << v1.front() << " " << v1.back() << endl;
}

// - swap(vec); // 将vec与本身的元素互换
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