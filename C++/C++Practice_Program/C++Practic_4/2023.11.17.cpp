#include <iostream>
using namespace std;
#include <set>
#include <queue>
#include <vector>

class Mycompare
{
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        bool b;
        if (p1.first > p2.first)
        {
            b = true;
        }
        else if (p1.first < p2.first)
        {
            b = false;
        }
        else if (p1.first == p2.first)
        {
            b = p1.second < p2.second;
        }
        return b;
    }
};

class sort
{
public:
    void initset();
    void print();
    void test();
    void print_v();
    multiset<pair<int, int>, Mycompare> m;
    vector<pair<int, int>> v;
};

void sort::print_v()
{
    for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it).first << " " << it->second << endl;
    }
}

void sort::initset()
{
    // pair<int, int> p1(4, 4);
    // pair<int, int> p2(5, 0);
    // pair<int, int> p3(5, 2);
    // pair<int, int> p4(6, 1);
    // pair<int, int> p5(7, 1);
    // pair<int, int> p6(7, 0);
    // m.insert(p1);
    // m.insert(p2);
    // m.insert(p3);
    // m.insert(p4);
    // m.insert(p5);
    // m.insert(p6);
    cout << "ÇëÊäÈëpair" << endl;
    while (1)
    {
        int a, b;
        cout << "first:";
        cin >> a;
        cout << "second:";
        cin >> b;
        if ((a == -1) || (b == -1))
            break;
        m.insert(make_pair(a, b));
    }
}

void sort::print()
{
    for (multiset<pair<int, int>, Mycompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " " << it->second << endl;
    }
}

void sort::test()
{
    for (multiset<pair<int, int>, Mycompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        if (v.empty())
        {
            v.push_back(*it);
        }
        int k = 0;
        for (vector<pair<int, int>>::iterator it1 = v.begin(); (it1 != v.end()) && (k != 1); it1++)
        {
            // if (it1->first == it->first)
            // {
            //     if (it1->second > it->second)
            //     {
            //         v.insert(it1++, (*it));
            //         k = 1;
            //     }
            // }
            // else
            // {
            vector<pair<int, int>>::iterator it2 = v.begin();
            for (int i = 0; i < (*it).second; i++)
            {
                it2++;
                if (it2 > v.end())
                {
                    it2 = v.end();
                }
            }
            if ((*it) == (*it2))
                break;
            v.insert(it2, (*it));
            k = 1;
            // }
        }
    }
}

int main()
{
    sort s;
    s.initset();
    // s.print();

    s.test();
    s.print_v();
    return 0;
}