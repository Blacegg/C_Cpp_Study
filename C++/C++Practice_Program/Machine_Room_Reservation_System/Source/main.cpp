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
        cout << "=====================    ��ӭ��������ԤԼϵͳ    =====================" << endl;
        cout << "\t\t ---------------------------------------\n";
        cout << "\t\t|                                       |\n";
        cout << "\t\t|              1.ѧ������               |\n";
        cout << "\t\t|                                       |\n";
        cout << "\t\t|              2.��ʦ                   |\n";
        cout << "\t\t|                                       |\n";
        cout << "\t\t|              3.����Ա                 |\n";
        cout << "\t\t|                                       |\n";
        cout << "\t\t|              4.�˳�ϵͳ               |\n";
        cout << "\t\t|                                       |\n";
        cout << "\t\t ---------------------------------------\n";
        cout << "��ѡ��������ݣ�" << endl;

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
            cout << "��ӭ�´�ʹ�ã�" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "����������������룡" << endl;
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
        cout << "�ļ������ڣ�" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if (type == 1)
    {
        cout << "���������ѧ�ţ�" << endl;
        cin >> id;
    }
    else if (type == 2)
    {
        cout << "���������ְ���ţ�" << endl;
        cin >> id;
    }

    cout << "�������û�����" << endl;
    cin >> name;
    cout << "���������룺" << endl;
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
                cout << "ѧ����֤��¼�ɹ�!" << endl;
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
                cout << "��ʦ��֤��¼�ɹ�!" << endl;
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
                cout << "����Ա��֤��¼�ɹ�!" << endl;
                system("pause");
                system("cls");
                person = new Manager(name, pwd);
                ManagerMenu(person);
                return;
            }
        }
        break;
    }
    cout << "��֤��¼ʧ�ܣ�" << endl;
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
            cout << "����˺�" << endl;
            man->Add_Person();
            break;
        case 2:
            cout << "�鿴�˺�" << endl;
            man->Show_Person();
            break;
        case 3:
            cout << "�鿴����" << endl;
            man->Show_ComputerRoom();
            break;
        case 4:
            cout << "���ԤԼ" << endl;
            man->Clear_File();
            break;
        default:
            delete manager;
            cout << "ע���ɹ���" << endl;
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
            cout << "����ԤԼ" << endl;
            stu->ApplyOrder();
            break;
        case 2:
            cout << "�鿴�ҵ�ԤԼ" << endl;
            stu->Show_MyOrder();
            break;
        case 3:
            cout << "�鿴����ԤԼ" << endl;
            stu->Show_AllOrder();
            break;
        case 4:
            cout << "ȡ��ԤԼ" << endl;
            stu->CancelOrder();
            break;
        default:
            delete student;
            cout << "ע���ɹ���" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}