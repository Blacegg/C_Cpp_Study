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
        cout << "文件不存在" << endl; // 测试输出
        this->m_EmpNum = 0;           // 初始化人数
        this->m_FileIsEmpty = true;   // 初始化文件为空标志
        this->m_EmpArray = NULL;      // 初始化数组
        ifs.close();                  // 关闭文件
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空!" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    int num = this->get_EmpNum();
    cout << "职工个数为：" << num << endl; // 测试代码
    this->m_EmpNum = num;                  // 更新成员属性
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
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

/***********************************************************************
 * @brief    WorkManager::exitSystem
 ***********************************************************************/
void WorkManager::exitSystem()
{
    cout << "欢迎下次使用！" << endl;
    system("pause");
    exit(0);
}

/***********************************************************************
 * @brief    WorkManager::Add_Emp
 ***********************************************************************/
void WorkManager::Add_Emp()
{
    cout << "请输入增加职工数量：" << endl;

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

            cout << "请输入第 " << i + 1 << " 个新职工编号： " << endl;
            cin >> id;
            cout << "请输入第 " << i + 1 << " 个新职工姓名： " << endl;
            cin >> name;

            cout << "请选择该职工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
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
                cout << "部门ID输入错误" << endl;
                break;
            }

            newspace[this->m_EmpNum + i] = worker;
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = newspace;
        this->m_EmpNum = newsize;
        this->m_FileIsEmpty = false;
        cout << "成功添加" << addNum << "名新职工！" << endl;
        this->Save();
    }
    else
    {
        cout << "输入有误" << endl;
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
        cout << "文件不存在或记录为空！" << endl;
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
        cout << "文件不存在或者记录为空！" << endl;
    }
    else
    {
        cout << "请输入想要删除的职工号:" << endl;
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
            cout << "删除成功！" << endl;
        }
        else
        {
            cout << "删除失败，未找到该职工" << endl;
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
        cout << "文件不存在或者记录为空！" << endl;
    }
    else
    {
        cout << "请输入要修改的员工编号：" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "查到 " << id << " 号职工，请输入新的职工号：" << endl;
            cin >> newId;

            cout << "请输入新姓名： " << endl;
            cin >> newName;

            cout << "请输入岗位： " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
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

            // 更改数据 到数组中
            this->m_EmpArray[ret] = worker;

            cout << "修改成功！" << endl;

            // 保存到文件中
            this->Save();
        }
        else
        {
            cout << "修改失败，查无此人" << endl;
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
        cout << "文件不存在或者记录为空！" << endl;
    }
    else
    {
        cout << "请输入查找的方式：" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;

        int select = 0;
        cin >> select;

        if (select == 1) // 按职工号查找
        {
            int id;
            cout << "请输入查找的职工编号：" << endl;
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "查找成功！该职工信息如下：" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        else if (select == 2) // 按姓名查找
        {
            string name;
            cout << "请输入查找的姓名：" << endl;
            cin >> name;

            bool flag = false; // 查找到的标志
            for (int i = 0; i < m_EmpNum; i++)
            {
                if (m_EmpArray[i]->m_Name == name)
                {
                    cout << "查找成功,职工编号为："
                         << m_EmpArray[i]->m_Id
                         << " 号的信息如下：" << endl;

                    flag = true;

                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (flag == false)
            {
                // 查无此人
                cout << "查找失败，查无此人" << endl;
            }
        }
        else
        {
            cout << "输入选项有误" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkManager::Sort()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "请选择排序方式： " << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;

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
                    cout << "输入错误" << endl;
                }
            }
        }
        cout << "排序成功，排序结果为：" << endl;
        this->Save();
        this->Show_Emp();
    }
}

/***********************************************************************
 * @brief    WorkManager::Clean_File
 ***********************************************************************/
void WorkManager::Clean_File()
{
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        // 打开模式 ios::trunc 如果存在删除文件并重新创建
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
        cout << "清空成功！" << endl;
    }

    system("pause");
    system("cls");
}