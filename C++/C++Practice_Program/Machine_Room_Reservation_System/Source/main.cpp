#include <iostream>
#include <fstream>
#include "../Include/globalfile.h"
#include "../Include/identity.h"
#include "../Include/student.h"
#include "../Include/teacher.h"
#include "../Include/manager.h"
using namespace std;

void LoginIn(string fileName, int type);
void ManagerMenu(Identity *&manager);
void StudentMenu(Identity *&student);

int main()
{
    int choice = 0;
    while (true)
    {
        cout << "=====================    欢迎来到机房预约系统    =====================" << endl;
        cout << "\t\t ---------------------------------------\n";
        cout << "\t\t|                                       |\n";
        cout << "\t\t|              1.学生代表               |\n";
        cout << "\t\t|                                       |\n";
        cout << "\t\t|              2.教师                   |\n";
        cout << "\t\t|                                       |\n";
        cout << "\t\t|              3.管理员                 |\n";
        cout << "\t\t|                                       |\n";
        cout << "\t\t|              4.退出系统               |\n";
        cout << "\t\t|                                       |\n";
        cout << "\t\t ---------------------------------------\n";
        cout << "请选择您的身份：" << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            LoginIn(Student_File, 1);
            break;
        case 2:
            LoginIn(Teacher_File, 2);
            break;
        case 3:
            LoginIn(Manager_File, 3);
            break;
        case 4:
            cout << "欢迎下次使用！" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "输入错误，请重新输入！" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}

void LoginIn(string fileName, int type)
{
    Identity *person = NULL;
    ifstream ifs;
    ifs.open(fileName, ios::in);

    if (!ifs.is_open())
    {
        cout << "文件不存在！" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if (type == 1)
    {
        cout << "请输入你的学号：" << endl;
        cin >> id;
    }
    else if (type == 2)
    {
        cout << "请输入你的职工号：" << endl;
        cin >> id;
    }

    cout << "请输入用户名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> pwd;

    int fid;
    string fname;
    string fpwd;

    switch (type)
    {
    case 1:
        while ((ifs >> fid) && (ifs >> fname) && (ifs >> fpwd))
        {
            if ((fid == id) && (fname == name) && (fpwd == pwd))
            {
                cout << "学生验证登录成功!" << endl;
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);
                StudentMenu(person);
                return;
            }
        }
        break;
    case 2:
        while ((ifs >> fid) && (ifs >> fname) && (ifs >> fpwd))
        {
            if ((fid == id) && (fname == name) && (fpwd == pwd))
            {
                cout << "教师验证登录成功!" << endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);
                return;
            }
        }
        break;
    case 3:
        while ((ifs >> fname) && (ifs >> fpwd))
        {
            if ((fname == name) && (fpwd == pwd))
            {
                cout << "管理员验证登录成功!" << endl;
                system("pause");
                system("cls");
                person = new Manager(name, pwd);
                ManagerMenu(person);
                return;
            }
        }
        break;
    }
    cout << "验证登录失败！" << endl;
    system("pause");
    system("cls");
    return;
}

void ManagerMenu(Identity *&manager)
{
    while (true)
    {
        manager->Show_OperMeun();
        Manager *man = (Manager *)manager;
        int select = 0;

        cin >> select;

        switch (select)
        {
        case 1:
            cout << "添加账号" << endl;
            man->Add_Person();
            break;
        case 2:
            cout << "查看账号" << endl;
            man->Show_Person();
            break;
        case 3:
            cout << "查看机房" << endl;
            man->Show_ComputerRoom();
            break;
        case 4:
            cout << "清空预约" << endl;
            man->Clear_File();
            break;
        default:
            delete manager;
            cout << "注销成功！" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void StudentMenu(Identity *&student)
{
    while (true)
    {
        student->Show_OperMeun();
        Student *stu = (Student *)student;
        int select = 0;

        cin >> select;

        switch (select)
        {
        case 1:
            cout << "申请预约" << endl;
            stu->ApplyOrder();
            break;
        case 2:
            cout << "查看我的预约" << endl;
            stu->Show_MyOrder();
            break;
        case 3:
            cout << "查看所有预约" << endl;
            stu->Show_AllOrder();
            break;
        case 4:
            cout << "取消预约" << endl;
            stu->CancelOrder();
            break;
        default:
            delete student;
            cout << "注销成功！" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}