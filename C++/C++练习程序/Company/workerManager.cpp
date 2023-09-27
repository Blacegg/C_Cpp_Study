/***********************************************************************
 * @file     workerManager.cpp
 * @brief
 * @author   blacegg
 * @version  1.0
 * @date     2023-09-07
 ***********************************************************************/
#include "workerManager.h"

/***********************************************************************
 * @brief    Construct a new Work Manager:: Work Manager object
 ***********************************************************************/
WorkManager::WorkManager()
{
    ifstream ifs(FILENAME, ios::in);
    if (!ifs.is_open())
    {
        cout << "�ļ�������" << endl; // �������
        this->m_EmpNum = 0;           // ��ʼ������
        this->m_FileIsEmpty = true;   // ��ʼ���ļ�Ϊ�ձ�־
        this->m_EmpArray = NULL;      // ��ʼ������
        ifs.close();                  // �ر��ļ�
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "�ļ�Ϊ��!" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    int num = this->get_EmpNum();
    cout << "ְ������Ϊ��" << num << endl; // ���Դ���
    this->m_EmpNum = num;                  // ���³�Ա����
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    init_Emp();
}

/***********************************************************************
 * @brief    Destroy the Work Manager:: Work Manager object
 ***********************************************************************/
WorkManager::~WorkManager()
{
    if (this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
    }
}

/***********************************************************************
 * @brief    WorkManager::Show_Menu
 ***********************************************************************/
void WorkManager::Show_Menu()
{
    cout << "********************************************" << endl;
    cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
    cout << "*************  0.�˳��������  *************" << endl;
    cout << "*************  1.����ְ����Ϣ  *************" << endl;
    cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
    cout << "*************  3.ɾ����ְְ��  *************" << endl;
    cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
    cout << "*************  5.����ְ����Ϣ  *************" << endl;
    cout << "*************  6.���ձ������  *************" << endl;
    cout << "*************  7.��������ĵ�  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

/***********************************************************************
 * @brief    WorkManager::exitSystem
 ***********************************************************************/
void WorkManager::exitSystem()
{
    cout << "��ӭ�´�ʹ�ã�" << endl;
    system("pause");
    exit(0);
}

/***********************************************************************
 * @brief    WorkManager::Add_Emp
 ***********************************************************************/
void WorkManager::Add_Emp()
{
    cout << "����������ְ��������" << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        int newsize = this->m_EmpNum + addNum;
        Worker **newspace = new Worker *[newsize];
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newspace[i] = this->m_EmpArray[i];
            }
        }

        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "������� " << i + 1 << " ����ְ����ţ� " << endl;
            cin >> id;
            cout << "������� " << i + 1 << " ����ְ�������� " << endl;
            cin >> name;

            cout << "��ѡ���ְ���ĸ�λ��" << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 1);
                break;
            case 3:
                worker = new Boss(id, name, 1);
                break;
            default:
                cout << "����ID�������" << endl;
                break;
            }

            newspace[this->m_EmpNum + i] = worker;
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = newspace;
        this->m_EmpNum = newsize;
        this->m_FileIsEmpty = false;
        cout << "�ɹ����" << addNum << "����ְ����" << endl;
        this->Save();
    }
    else
    {
        cout << "��������" << endl;
    }

    system("pause");
    system("cls");
}

/***********************************************************************
 * @brief    WorkManager::Save
 ***********************************************************************/
void WorkManager::Save()
{
    ofstream ofs(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }

    ofs.close();
}

/***********************************************************************
 * @brief    Get the EmpNum object
 * @return   int:
 ***********************************************************************/
int WorkManager::get_EmpNum()
{
    ifstream ifs(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }

    ifs.close();
    return num;
}

/***********************************************************************
 * @brief    WorkManager::init_Emp
 ***********************************************************************/
void WorkManager::init_Emp()
{
    ifstream ifs(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker *worker = NULL;
        if (dId == 1)
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2)
        {
            worker = new Manager(id, name, dId);
        }
        else if (dId == 3)
        {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
}

/***********************************************************************
 * @brief    WorkManager::Show_Emp
 ***********************************************************************/
void WorkManager::Show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

/***********************************************************************
 * @brief    WorkManager::IsExist
 * @param    Id:
 * @return   int:
 ***********************************************************************/
int WorkManager::IsExist(int Id)
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_Id == Id)
        {
            index = i;
            break;
        }
    }
    return index;
}

/***********************************************************************
 * @brief    WorkManager::Del_Emp
 ***********************************************************************/
void WorkManager::Del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
    }
    else
    {
        cout << "��������Ҫɾ����ְ����:" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);
        if (index != -1)
        {
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            this->Save();
            cout << "ɾ���ɹ���" << endl;
        }
        else
        {
            cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
        }
    }
    system("pause");
    system("cls");
}

/***********************************************************************
 * @brief    WorkManager::Mod_Emp
 ***********************************************************************/
void WorkManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
    }
    else
    {
        cout << "������Ҫ�޸ĵ�Ա����ţ�" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "�鵽 " << id << " ��ְ�����������µ�ְ���ţ�" << endl;
            cin >> newId;

            cout << "�������������� " << endl;
            cin >> newName;

            cout << "�������λ�� " << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
            }

            // �������� ��������
            this->m_EmpArray[ret] = worker;

            cout << "�޸ĳɹ���" << endl;

            // ���浽�ļ���
            this->Save();
        }
        else
        {
            cout << "�޸�ʧ�ܣ����޴���" << endl;
        }
    }
    system("pause");
    system("cls");
}

/***********************************************************************
 * @brief    WorkManager::Find_Emp
 ***********************************************************************/
void WorkManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
    }
    else
    {
        cout << "��������ҵķ�ʽ��" << endl;
        cout << "1����ְ����Ų���" << endl;
        cout << "2������������" << endl;

        int select = 0;
        cin >> select;

        if (select == 1) // ��ְ���Ų���
        {
            int id;
            cout << "��������ҵ�ְ����ţ�" << endl;
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "����ʧ�ܣ����޴���" << endl;
            }
        }
        else if (select == 2) // ����������
        {
            string name;
            cout << "��������ҵ�������" << endl;
            cin >> name;

            bool flag = false; // ���ҵ��ı�־
            for (int i = 0; i < m_EmpNum; i++)
            {
                if (m_EmpArray[i]->m_Name == name)
                {
                    cout << "���ҳɹ�,ְ�����Ϊ��"
                         << m_EmpArray[i]->m_Id
                         << " �ŵ���Ϣ���£�" << endl;

                    flag = true;

                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (flag == false)
            {
                // ���޴���
                cout << "����ʧ�ܣ����޴���" << endl;
            }
        }
        else
        {
            cout << "����ѡ������" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkManager::Sort()
{
    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "��ѡ������ʽ�� " << endl;
        cout << "1����ְ���Ž�������" << endl;
        cout << "2����ְ���Ž��н���" << endl;

        int select = 0;
        cin >> select;

        for (int i = 0; i < this->m_EmpNum - 1; i++)
        {
            for (int j = i; j < this->m_EmpNum - i - 1; j++)
            {
                if (select == 1)
                {
                    if (this->m_EmpArray[j] > this->m_EmpArray[j + 1])
                    {
                        Worker *temp = this->m_EmpArray[j];
                        this->m_EmpArray[j] = this->m_EmpArray[j + 1];
                        this->m_EmpArray[j + 1] = temp;
                    }
                }
                else if (select == 2)
                {
                    if (this->m_EmpArray[j] < this->m_EmpArray[j + 1])
                    {
                        Worker *temp = this->m_EmpArray[j];
                        this->m_EmpArray[j] = this->m_EmpArray[j + 1];
                        this->m_EmpArray[j + 1] = temp;
                    }
                }
                else
                {
                    cout << "�������" << endl;
                }
            }
        }
        cout << "����ɹ���������Ϊ��" << endl;
        this->Save();
        this->Show_Emp();
    }
}

/***********************************************************************
 * @brief    WorkManager::Clean_File
 ***********************************************************************/
void WorkManager::Clean_File()
{
    cout << "ȷ����գ�" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        // ��ģʽ ios::trunc �������ɾ���ļ������´���
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL)
                {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout << "��ճɹ���" << endl;
    }

    system("pause");
    system("cls");
}