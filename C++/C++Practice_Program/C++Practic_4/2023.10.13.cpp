#include <iostream>
using namespace std;
#include <map>

void test1()
{
    multimap<double, int, greater<double>> t;
    t.insert(make_pair(1.2, 5));
    t.insert(make_pair(6.2, 9));
    t.insert(make_pair(1.22, 2));
    t.insert(make_pair(11.2, 6));
    t.insert(make_pair(1.2, 5));
    for (multimap<double, int, greater<int>>::iterator it = t.begin(); it != t.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }
}
void test2()
{
    double a = 1.2;
    double b = 1.8;
    cout << "a = " << (int)a << endl;
    cout << "b = " << (int)b << endl;
}

void test3()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < 12; i++)
    {
        cout << "Ñ¡ÊÖ" + nameSeed[i] << endl;
    }
}

int main()
{
    // test1();
    // test2();
    test3();
    return 0;
}