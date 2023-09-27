#include <iostream>
#include <string>
using namespace std;

class Student
{
public: // 公共权限
    // 类中的属性和行为统一称为成员
    // 属性      成员属性    成员变量
    // 行为      成员函数    成员方法

    // 属性
    // 姓名
    string m_name;
    // 学号
    int m_NO;

    // 行为
    // 显示姓名和学号
    void Print()
    {
        cout << "姓名： " << m_name << "\t学号： " << m_NO << endl;
    }

    // 设置姓名
    void setName(string name)
    {
        m_name = name;
    }
};

class person
{
public:
    string m_name;

protected:
    string m_car;

private:
    int m_password;

public:
    void set()
    {
        m_name = "张三";
        m_car = "拖拉机";
        m_password = 123456;
    }
};

class Person
{
private:
    string m_name;  // 设置名字只可读
    int m_age;      // 设置年龄只可读可写
    string m_lover; // 设置爱人只可写
public:
    // 设置接口访问
    string getName()
    {
        return m_name;
    }
    void setAge(int age)
    {
        // 对写权限进行数据检测
        if (age < 0 || age > 150)
        {
            cout << "输入错误" << endl;
            return;
        }
        m_age = age;
    }
    int getage()
    {
        return m_age;
    }
    void setlover(string lover)
    {
        m_lover = lover;
    }
};

class Cube1
{
public:
    int m_l;
    int m_w;
    int m_h;
    int get_area()
    {
        return (m_l * m_w + m_l * m_h + m_h * m_w) * 2;
    }
    int get_volume()
    {
        return m_h * m_w * m_l;
    }
    void if_or_no_equal(int x, int y, int z)
    {
        int area = (x * y + x * z + y * z) * 2;
        int volume = x * y * z;
        if (get_area() == area && get_volume() == volume)
        {
            if ((x == m_l && y == m_h) || (x == m_h && y == m_l))
            {
                cout << "相等" << endl;
            }
        }
        else
        {
            cout << "不相等" << endl;
        }
        return;
    }
};

void isornoequal(int x, int y, int z, int a, int b, int c)
{
    int area1 = (x * y + x * z + y * z) * 2;
    int volume1 = x * y * z;
    int area2 = (a * b + a * c + b * c) * 2;
    int volume2 = a * b * c;
    if (area1 == area2 && volume1 == volume2)
    {
        if ((x == a && y == b) || (x == b && y == a))
        {
            cout << "相等" << endl;
        }
    }
    else
    {
        cout << "不相等" << endl;
    }
    return;
}

class Cube2
{
private:
    int m_l;
    int m_w;
    int m_h;

public:
    void setlength(int length)
    {
        m_l = length;
    }
    int getlength()
    {
        return m_l;
    }

    void setwidth(int width)
    {
        m_w = width;
    }
    int getwidth()
    {
        return m_w;
    }

    void setheight(int height)
    {
        m_h = height;
    }
    int getheight()
    {
        return m_h;
    }

    int get_area()
    {
        return (m_l * m_w + m_l * m_h + m_h * m_w) * 2;
    }

    int get_volume()
    {
        return m_h * m_w * m_l;
    }

    bool is_same(Cube2 &c)
    {
        if (m_l == c.getlength() && m_w == c.getwidth() && m_h == c.getheight())
        {
            cout << "成员函数判断：相同" << endl;
            return true;
        }
        return false;
    }
};

bool is_same_cube(Cube2 &c1, Cube2 &c2)
{
    if (c1.getlength() == c2.getlength() && c1.getwidth() == c2.getwidth() && c1.getheight() == c2.getheight())
    {
        cout << "成员函数判断：相同" << endl;
        return true;
    }
    return false;
}

class Cube
{
public:
    int m_l;
    int m_w;
    int m_h;

    int get_area()
    {
        return (m_l * m_w + m_l * m_h + m_h * m_w) * 2;
    }

    int get_volume()
    {
        return m_h * m_w * m_l;
    }

    bool is_same(Cube &c)
    {
        if (m_l == c.m_l && m_w == c.m_w && m_h == c.m_h)
        {
            cout << "成员函数判断：相同" << endl;
            return true;
        }
        return false;
    }
};

bool is_same_cube(Cube &c1, Cube &c2)
{
    if (c1.m_l == c2.m_l && c1.m_w == c2.m_w && c1.m_h == c2.m_h)
    {
        cout << "成员函数判断：相同" << endl;
        return true;
    }
    return false;
}

int main()
{
    // // 创建一个具体的学生   实例化对象
    // Student S;

    // S.setName("张三");
    // S.m_NO = 123;

    // // 显示学生姓名学号
    // S.Print();

    person one;
    one.m_name = "李四";
    // one.m_car = "奔驰";   // 错误，不可访问
    // one.m_password = 123; // 错误，不可访问

    return 0;
}