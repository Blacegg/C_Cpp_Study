#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Drink
{
public:
    void Make_Drink()
    {
        Boiling_Water();
        Brew();
        Pour_Cup();
        Add_Accessories();
    }
    void Boiling_Water()
    {
        cout << "water is boiling" << endl;
    }
    virtual void Brew() = 0;
    void Pour_Cup()
    {
        cout << "pour into a cup" << endl;
    }
    virtual void Add_Accessories() = 0;
    // {
    //     cout << "add accessories" << endl;
    // }
};

class Tea : public Drink
{
public:
    void Brew()
    {
        cout << "brew tea leaf" << endl;
    }
    void Add_Accessories()
    {
        cout << "Add lemon" << endl;
    }
};
class Coffee : public Drink
{
public:
    void Brew()
    {
        cout << "brew coffee" << endl;
    }
    void Add_Accessories()
    {
        cout << "Add suger and milk" << endl;
    }
};

void test()
{
    Coffee c;
    c.Make_Drink();
}

void test(int)
{
    Tea t;
    t.Make_Drink();
}

void test(Drink &d)
{
    d.Make_Drink();
}

void write()
{
    ofstream ofs;
    ofs.open("./test.txt", ios::out);
    ofs << "name:Tom" << endl;
    ofs << "age:16" << endl;
    ofs << "sex:man" << endl;
    ofs.close();
}

void read(int way)
{
    ifstream ifs;
    ifs.open("./test.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }
    switch (way)
    {
    case 1:
    {
        char str[1024] = {0};
        while (ifs >> str)
        {
            cout << str << endl;
        }
        break;
    }
    case 2:
    {
        char str[1024] = {0};
        while (ifs.getline(str, sizeof(str)))
        {
            cout << str << endl;
        }
        break;
    }
    case 3:
    {
        string str;
        while (getline(ifs, str))
        {
            cout << str << endl;
        }
        break;
    }
    case 4:
    {
        char c;
        while ((c = ifs.get()) != EOF)
        {
            cout << c;
        }
        break;
    }
    }
    ifs.close();
}

void test1()
{
    write();
    read(1);
}
int main()
{
    // test();
    // test(10);
    // Coffee c;
    // test(c);
    test1();
    return 0;
}