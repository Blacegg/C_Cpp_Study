#include <iostream>
#include <string>
using namespace std;

class person1
{
public:
    void Show1()
    {
        cout << "person1 调用" << endl;
    }
};

class person2
{
public:
    void Show2()
    {
        cout << "person2 调用" << endl;
    }
};

template <class T>
class Mycalss
{
public:
    T obj;

    void fun1()
    {
        obj.Show1();
    }

    void fun2()
    {
        obj.Show2();
    }
};

void test1()
{
    Mycalss<person1> m;
    m.fun1();
    // m.fun2();
}

void SHOW1(Mycalss<person1> &m)
{
    m.fun1();
}

template <class T>
void SHOW2(Mycalss<T> &m)
{
    m.fun1();
}

template <typename T>
void SHOW3(T &m)
{
    m.fun1();
}

void test2()
{
    Mycalss<person1> m;
    SHOW3(m);
}

class cat
{
public:
    string name;
    int age;
};

template <class T1, class T2>
class animals
{
public:
    T1 name;
    T2 age;
    animals(T1, T2);
    void show_animals();
};

template <class T1, class T2>
animals<T1, T2>::animals(T1 name, T2 age)
{
    this->name = name;
    this->age = age;
}

template <class T1, class T2>
void animals<T1, T2>::show_animals()
{
    cout << this->name << "\t" << this->age << endl;
}

void test3()
{
    animals<string, int> c("zjp", 100);
    c.show_animals();
}

template <class T>
class room;

template <class T>
void printfroom(room<T> &d)
{
    cout << d.badroom << endl;
}

template <class T>
class room
{
public:
    room(T a)
    {
        this->badroom = a;
    }

    friend void printfroom<>(room<T> &d);
    // {
    //     cout << d.badroom << endl;
    // }
private:
    string badroom;
};



void test4()
{
    room<string> m("xiao");
    printfroom(m);
}

int main()
{
    // test2();
    // test3();
    test4();
    return 0;
}