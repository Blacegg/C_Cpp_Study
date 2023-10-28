#include "../Include/manager.h"

Manager::Manager() {}

Manager::Manager(string name, string pwd) : Identity(name, pwd)
{
    this->Vector_Init();
}

void Manager::Show_OperMeun()
{
    cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
    cout << "\t\t ---------------------------------------\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              1.添加账号               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              2.查看账号               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              3.查看机房               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              4.清空预约               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              0.注销登录               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t ---------------------------------------\n";
    cout << "请选择您的操作：" << endl;
}

void Manager::Add_Person()
{
    cout << "\t\t ---------------------------------------\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              1.学生账号               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              2.教师账号               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t ---------------------------------------\n";
    cout << "请输入添加账号的类型：" << endl;

    string filename;
    string tip;
    string errortip;
    ofstream ofs;

    int select = 0;
    cin >> select;
    if (select == 1)
    {
        filename = Student_File;
        tip = "请输入学生学号：";
        errortip = "学号重复，请重新输入！";
    }
    else
    {
        filename = Teacher_File;
        tip = "请输入教师职工号：";
        errortip = "职工号重复，请重新输入！";
    }

    ofs.open(filename, ios::out | ios::app);
    if (!ofs.is_open())
    {
        cout << "打开文件失败！" << endl;
        ofs.close();
        return;
    }

    int id;
    string name;
    string pwd;

    cout << tip << endl;
    while (true)
    {
        cin >> id;
        bool sign = this->Check_Repeat(id, select);
        if (sign == false)
        {
            break;
        }
        cout << errortip << endl;
    }

    cout << "请输入姓名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功" << endl;

    system("pause");
    system("cls");

    ofs.close();
    this->Vector_Init();
}

void Print_Student(Student &stu)
{
    cout << "学号：" << stu.m_Student_Id << "\t姓名：" << stu.m_Name << "\t密码：" << stu.m_Pwd << endl;
}

void Print_Teacher(Teacher &tea)
{
    cout << "职工号：" << tea.m_teacher_Id << "\t姓名：" << tea.m_Name << "\t密码：" << tea.m_Pwd << endl;
}

void Manager::Show_Person()
{
    cout << "\t\t ---------------------------------------\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              1.学生账号               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              2.教师账号               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t ---------------------------------------\n";
    cout << "请选择查看的内容：" << endl;
    int select = 0;
    cin >> select;

    if (select == 1)
    {
        cout << "所有学生的信息如下：" << endl;
        for_each(this->v_Stu.begin(), this->v_Stu.end(), Print_Student);
    }
    else
    {
        cout << "所有教师的信息如下：" << endl;
        for_each(this->v_Tea.begin(), this->v_Tea.end(), Print_Teacher);
    }
    system("pause");
    system("cls");
}

void Manager::Show_ComputerRoom()
{
    cout << "机房信息如下：" << endl;
    for (vector<ComputerRoom>::iterator it = this->v_Com.begin(); it != this->v_Com.end(); it++)
    {
        cout << "机房编号： " << it->m_ComId << "\t机房最大容量： " << it->m_MaxNum << endl;
    }
    system("pause");
    system("cls");
}

void Manager::Clear_File() 
{
    ofstream ofs(Oder_File, ios::trunc);
    ofs.close();

    cout << "清空成功！" << endl;
    system("pause");
    system("cls");
}

void Manager::Vector_Init()
{
    ifstream ifs;
    ifs.open(Student_File, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }

    this->v_Stu.clear();
    this->v_Tea.clear();

    int id = 0;
    string name;
    string pwd;
    Student tmp_stu;
    while ((ifs >> tmp_stu.m_Student_Id) && (ifs >> tmp_stu.m_Name) && (ifs >> tmp_stu.m_Pwd))
    {
        this->v_Stu.push_back(tmp_stu);
    }
    cout << "当前学生数量是：" << this->v_Stu.size() << endl;
    ifs.close();

    ifs.open(Teacher_File, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }

    Teacher tmp_tea;
    while ((ifs >> tmp_tea.m_teacher_Id) && (ifs >> tmp_tea.m_Name) && (ifs >> tmp_tea.m_Pwd))
    {
        this->v_Tea.push_back(tmp_tea);
    }
    cout << "当前教师数量是：" << this->v_Tea.size() << endl;
    ifs.close();

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
    cout << "当前机房数量是：" << this->v_Com.size() << endl;
    ifs.close();
}

bool Manager::Check_Repeat(int id, int type)
{
    if (type == 1)
    {
        for (vector<Student>::iterator it = v_Stu.begin(); it != v_Stu.end(); it++)
        {
            if (id == it->m_Student_Id)
            {
                return true;
            }
        }
    }
    else
    {
        for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++)
        {
            if (id == it->m_teacher_Id)
            {
                return true;
            }
        }
    }
    return false;
}
