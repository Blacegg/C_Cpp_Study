#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>

// - push_back(elem);  // 在容器尾部添加一个数据
// - push_front(elem); // 在容器头部插入一个数据
// - pop_back();       // 删除容器最后一个数据
// - pop_front();      // 删除容器第一个数据

// 指定位置操作：

// - insert(pos, elem);     // 在pos位置插入一个elem元素的拷贝，返回新数据的位置。
// - insert(pos, n, elem);  // 在pos位置插入n个elem数据，无返回值。
// - insert(pos, beg, end); // 在pos位置插入[beg,end)区间的数据，无返回值。
// - clear();               // 清空容器的所有数据
// - erase(beg, end);       // 删除[beg,end)区间的数据，返回下一个数据的位置。
// - erase(pos);            // 删除pos位置的数据，返回下一个数据的位置。

void test1()
{
    deque<int> d1;
    bool isempty = d1.empty();
    cout << ((isempty == true) ? "d1 为空" : "d1 不为空") << endl;
    int dsize = d1.size();
    cout << "d1 的大小为：" << dsize << endl;

    cout << "push_back结果：" << endl;
    for (int i = 0; i < 10; i++)
    {
        d1.push_front(i);
    }
    isempty = d1.empty();
    cout << ((isempty == true) ? "d1 为空" : "d1 不为空") << endl;
    dsize = d1.size();
    cout << "d1 的大小为：" << dsize << endl;
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
    cout << "请输入选手信息：" << endl;
    cout << "请输入选手人数：" << endl;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        people temp;
        cout << "请输入第 " << i + 1 << " 位选手姓名：" << endl;
        cin >> temp.m_Name;
        cout << "请输入第 " << i + 1 << "位选手年龄：" << endl;
        cin >> temp.m_Age;
        v1.push_back(temp);
        cout << endl;
    }
    cout << "选手信息已输完" << endl;
}

void set_score(vector<people> &v1)
{
    for (vector<people>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        for (int i = 0; i < 10; i++)
        {
            int temp_score;
            cout << "请给出第 " << i + 1 << " 个评分：";
            cin >> temp_score;
            (*it).score.push_back(temp_score);
            cout << endl;
        }
        cout << endl;
    }
    cout << "打分结束！" << endl;
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
        cout << "姓名：" << (*it).m_Name << "\t"
             << "年龄：" << (*it).m_Age << "     "
             << "得分：" << (*it).m_average_score << endl;
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

// 构造函数：

// - stack<T> stk;            // stack采用模板类实现， stack对象的默认构造形式
// - stack(const stack &stk); // 拷贝构造函数

// 赋值操作：

// - stack &operator=(const stack &stk); // 重载等号操作符

// 数据存取：

// - push(elem); // 向栈顶添加元素
// - pop();      // 从栈顶移除第一个元素
// - top();      // 返回栈顶元素

// 大小操作：

// - empty(); // 判断堆栈是否为空
// - size();  // 返回栈的大小

void test4()
{
    stack<int> stk;
    bool stk_isempty = stk.empty();
    int stk_size = stk.size();
    cout << ((stk_isempty == true) ? "stk为空" : "stk不为空") << endl;
    cout << "stk的大小:" << stk_size << endl;
    for (int i = 0; i < 10; i++)
    {
        stk.push(i);
    }
    stk_isempty = stk.empty();
    stk_size = stk.size();
    cout << ((stk_isempty == true) ? "stk为空" : "stk不为空") << endl;
    cout << "stk的大小:" << stk_size << endl;
    stack<int> stk1(stk);
    stk_isempty = stk1.empty();
    stk_size = stk1.size();
    cout << ((stk_isempty == true) ? "stk1为空" : "stk1不为空") << endl;
    cout << "stk1的大小:" << stk_size << endl;
    int stk_top = stk1.top();
    cout << "stk1的栈顶：" << stk_top << endl;
    stk_isempty = stk1.empty();
    stk_size = stk1.size();
    cout << ((stk_isempty == true) ? "stk为空" : "stk不为空") << endl;
    cout << "stk的大小:" << stk_size << endl;
    stk1.pop();
    cout << "stk1的出栈" << endl;
    stk_isempty = stk1.empty();
    stk_size = stk1.size();
    cout << ((stk_isempty == true) ? "stk为空" : "stk不为空") << endl;
    cout << "stk的大小:" << stk_size << endl;
}

// 构造函数：

// - queue<T> que;            // queue采用模板类实现，queue对象的默认构造形式
// - queue(const queue &que); // 拷贝构造函数

// 赋值操作：

// - queue &operator=(const queue &que); // 重载等号操作符

// 数据存取：

// - push(elem); // 往队尾添加元素
// - pop();      // 从队头移除第一个元素
// - back();     // 返回最后一个元素
// - front();    // 返回第一个元素

// 大小操作：

// - empty(); // 判断堆栈是否为空
// - size();  // 返回栈的大小

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

// - push_back(elem);       // 在容器尾部加入一个元素
// - pop_back();            // 删除容器中最后一个元素
// - push_front(elem);      // 在容器开头插入一个元素
// - pop_front();           // 从容器开头移除第一个元素
// - insert(pos, elem);     // 在pos位置插elem元素的拷贝，返回新数据的位置。
// - insert(pos, n, elem);  // 在pos位置插入n个elem数据，无返回值。
// - insert(pos, beg, end); // 在pos位置插入[beg,end)区间的数据，无返回值。
// - clear();               // 移除容器的所有数据
// - erase(beg, end);       // 删除[beg,end)区间的数据，返回下一个数据的位置。
// - erase(pos);            // 删除pos位置的数据，返回下一个数据的位置。
// - remove(elem);          // 删除容器中所有与elem值匹配的元素。

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