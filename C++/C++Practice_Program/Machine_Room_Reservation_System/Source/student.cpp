#include "../Include/student.h"

Student::Student(){};
Student::~Student(){};

Student::Student(int id, string name, string pwd) : m_Student_Id(id), Identity(name, pwd)
{
    ifstream ifs;
    ifs.open(ComputerRoom_File, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }

    ComputerRoom tmp_com;
    while ((ifs >> tmp_com.m_ComId) && (ifs >> tmp_com.m_MaxNum))
    {
        this->v_Com.push_back(tmp_com);
    }

    ifs.close();
}

void Student::Show_OperMeun()
{
    cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
    cout << "\t\t ---------------------------------------\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              1.申请预约               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              2.查看我的预约           |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              3.查看所有预约           |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              4.取消预约               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              0.注销登录               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t ---------------------------------------\n";
    cout << "请选择您的操作：" << endl;
}

void Student::ApplyOrder()
{
    cout << "机房开放时间为周一至周五！" << endl;
    cout << "\t\t ---------------------------------------\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|          1.周一       2.周二          |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|          3.周三       4.周四          |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|          5.周五                       |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t ---------------------------------------\n";
    cout << "请选择预约日期：" << endl;

    int date = 0;
    int interval = 0;
    int room = 0;

    while (true)
    {
        cin >> date;
        if ((date > 0) && (date < 6))
        {
            break;
        }
        cout << "输入有误！请重新输入！" << endl;
    }

    cout << "\t\t ---------------------------------------\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              1.上午                   |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              2.下午                   |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t ---------------------------------------\n";
    cout << "请选择预约时间段：" << endl;

    while (true)
    {
        cin >> interval;
        if ((interval == 1) || (interval == 2))
        {
            break;
        }
        cout << "输入有误！请重新输入！" << endl;
    }

    cout << "请选择机房：" << endl;
    cout << "1号机房容量：" << this->v_Com[0].m_MaxNum << endl;
    cout << "2号机房容量：" << this->v_Com[1].m_MaxNum << endl;
    cout << "3号机房容量：" << this->v_Com[2].m_MaxNum << endl;

    while (true)
    {
        cin >> room;
        if ((room >= 0) && (room <= 3))
        {
            break;
        }
        cout << "输入有误！请重新输入！" << endl;
    }

    cout << "预约成功！审核中......" << endl;

    ofstream ofs(Oder_File, ios::out);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "Stu_Id:" << this->m_Student_Id << " ";
    ofs << "Stu_Name:" << this->m_Name << " ";
    ofs << "Room_Id:" << room << " ";
    ofs << "Status:" << 1 << endl;
    ofs.close();

    system("pause");
    system("cls");
}

void Student::Show_MyOrder() {}
void Student::Show_AllOrder() {}
void Student::CancelOrder() {}