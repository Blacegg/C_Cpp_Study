#include "../Include/student.h"

Student::Student(){};
Student::~Student(){};

Student::Student(int id, string name, string pwd) : m_Student_Id(id), Identity(name, pwd)
{
    ifstream ifs;
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

    ifs.close();
}

void Student::Show_OperMeun()
{
    cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
    cout << "\t\t ---------------------------------------\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              1.����ԤԼ               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              2.�鿴�ҵ�ԤԼ           |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              3.�鿴����ԤԼ           |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              4.ȡ��ԤԼ               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              0.ע����¼               |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t ---------------------------------------\n";
    cout << "��ѡ�����Ĳ�����" << endl;
}

void Student::ApplyOrder()
{
    cout << "��������ʱ��Ϊ��һ�����壡" << endl;
    cout << "\t\t ---------------------------------------\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|          1.��һ       2.�ܶ�          |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|          3.����       4.����          |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|          5.����                       |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t ---------------------------------------\n";
    cout << "��ѡ��ԤԼ���ڣ�" << endl;

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
        cout << "�����������������룡" << endl;
    }

    cout << "\t\t ---------------------------------------\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              1.����                   |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t|              2.����                   |\n";
    cout << "\t\t|                                       |\n";
    cout << "\t\t ---------------------------------------\n";
    cout << "��ѡ��ԤԼʱ��Σ�" << endl;

    while (true)
    {
        cin >> interval;
        if ((interval == 1) || (interval == 2))
        {
            break;
        }
        cout << "�����������������룡" << endl;
    }

    cout << "��ѡ�������" << endl;
    cout << "1�Ż���������" << this->v_Com[0].m_MaxNum << endl;
    cout << "2�Ż���������" << this->v_Com[1].m_MaxNum << endl;
    cout << "3�Ż���������" << this->v_Com[2].m_MaxNum << endl;

    while (true)
    {
        cin >> room;
        if ((room >= 0) && (room <= 3))
        {
            break;
        }
        cout << "�����������������룡" << endl;
    }

    cout << "ԤԼ�ɹ��������......" << endl;

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