#include "../Include/manager.h"

Manager::Manager() {}

Manager::Manager(string name, string pwd) : Identity(name, pwd)
{
    this->Vector_Init();
}

void Manager::Show_OperMeun()
{
    cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
    cout << "\t\t ---------------------------------------\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              1.����˺�               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              2.�鿴�˺�               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              3.�鿴����               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              4.���ԤԼ               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              0.ע����¼               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t ---------------------------------------\n";
    cout << "��ѡ�����Ĳ�����" << endl;
}

void Manager::Add_Person()
{
    cout << "\t\t ---------------------------------------\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              1.ѧ���˺�               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              2.��ʦ�˺�               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t ---------------------------------------\n";
    cout << "����������˺ŵ����ͣ�" << endl;

    string filename;
    string tip;
    string errortip;
    ofstream ofs;

    int select = 0;
    cin >> select;
    if (select == 1)
    {
        filename = Student_File;
        tip = "������ѧ��ѧ�ţ�";
        errortip = "ѧ���ظ������������룡";
    }
    else
    {
        filename = Teacher_File;
        tip = "�������ʦְ���ţ�";
        errortip = "ְ�����ظ������������룡";
    }

    ofs.open(filename, ios::out | ios::app);
    if (!ofs.is_open())
    {
        cout << "���ļ�ʧ�ܣ�" << endl;
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

    cout << "������������" << endl;
    cin >> name;
    cout << "���������룺" << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "��ӳɹ�" << endl;

    system("pause");
    system("cls");

    ofs.close();
    this->Vector_Init();
}

void Print_Student(Student &stu)
{
    cout << "ѧ�ţ�" << stu.m_Student_Id << "\t������" << stu.m_Name << "\t���룺" << stu.m_Pwd << endl;
}

void Print_Teacher(Teacher &tea)
{
    cout << "ְ���ţ�" << tea.m_teacher_Id << "\t������" << tea.m_Name << "\t���룺" << tea.m_Pwd << endl;
}

void Manager::Show_Person()
{
    cout << "\t\t ---------------------------------------\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              1.ѧ���˺�               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              2.��ʦ�˺�               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t ---------------------------------------\n";
    cout << "��ѡ��鿴�����ݣ�" << endl;
    int select = 0;
    cin >> select;

    if (select == 1)
    {
        cout << "����ѧ������Ϣ���£�" << endl;
        for_each(this->v_Stu.begin(), this->v_Stu.end(), Print_Student);
    }
    else
    {
        cout << "���н�ʦ����Ϣ���£�" << endl;
        for_each(this->v_Tea.begin(), this->v_Tea.end(), Print_Teacher);
    }
    system("pause");
    system("cls");
}

void Manager::Show_ComputerRoom()
{
    cout << "������Ϣ���£�" << endl;
    for (vector<ComputerRoom>::iterator it = this->v_Com.begin(); it != this->v_Com.end(); it++)
    {
        cout << "������ţ� " << it->m_ComId << "\t������������� " << it->m_MaxNum << endl;
    }
    system("pause");
    system("cls");
}

void Manager::Clear_File() 
{
    ofstream ofs(Oder_File, ios::trunc);
    ofs.close();

    cout << "��ճɹ���" << endl;
    system("pause");
    system("cls");
}

void Manager::Vector_Init()
{
    ifstream ifs;
    ifs.open(Student_File, ios::in);
    if (!ifs.is_open())
    {
        cout << "�ļ���ȡʧ��" << endl;
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
    cout << "��ǰѧ�������ǣ�" << this->v_Stu.size() << endl;
    ifs.close();

    ifs.open(Teacher_File, ios::in);
    if (!ifs.is_open())
    {
        cout << "�ļ���ȡʧ��" << endl;
        return;
    }

    Teacher tmp_tea;
    while ((ifs >> tmp_tea.m_teacher_Id) && (ifs >> tmp_tea.m_Name) && (ifs >> tmp_tea.m_Pwd))
    {
        this->v_Tea.push_back(tmp_tea);
    }
    cout << "��ǰ��ʦ�����ǣ�" << this->v_Tea.size() << endl;
    ifs.close();

    ifs.open(ComputerRoom_File, ios::in);
    if (!ifs.is_open())
    {
        cout << "�ļ���ȡʧ��" << endl;
        return;
    }

    ComputerRoom tmp_com;
    while ((ifs >> tmp_com.m_ComId) && (ifs >> tmp_com.m_MaxNum))
    {
        this->v_Com.push_back(tmp_com);
    }
    cout << "��ǰ���������ǣ�" << this->v_Com.size() << endl;
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
