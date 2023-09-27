#include "Contacts.hpp"

/*打印通讯录菜单*/
void menu(void)
{
    cout << "***************************************" << endl;
    cout << "********      1.添加联系人      ********" << endl;
    cout << "********      2.显示联系人      ********" << endl;
    cout << "********      3.删除联系人      ********" << endl;
    cout << "********      4.查找联系人      ********" << endl;
    cout << "********      5.修改联系人      ********" << endl;
    cout << "********      6.清空联系人      ********" << endl;
    cout << "********      0.退出联系人      ********" << endl;
    cout << "***************************************" << endl;
}

/*初始化通讯录*/
void Contact_Init(Contact *contact)
{
    // contact->people[MAX] = {0};
    contact->num = 0;
}

/*添加联系人*/
void Add_People(Contact *contact)
{
    if (contact->num == MAX)
    {
        cout << "通讯录已满！无法添加联系人！" << endl;
        return;
    }
    else
    {
        cout << "请输入联系人的姓名：" << endl;
        cin >> contact->people[contact->num].name;

        cout << "请输入联系人的年龄：" << endl;
        cin >> contact->people[contact->num].age;

        int sex = 0;
        while (1)
        {
            cout << "请输入联系人的性别：" << endl;
            cout << "    1-----男    " << endl;
            cout << "    2-----女    " << endl;
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                contact->people[contact->num].sex = sex;
                break;
            }
            else
            {
                cout << "输入错误，请重新输入！" << endl;
            }
        }

        cout << "请输入联系人的电话：" << endl;
        cin >> contact->people[contact->num].Phone;

        cout << "请输入联系人的地址：" << endl;
        cin >> contact->people[contact->num].Address;

        cout << "成功添加联系人！" << endl;
        contact->num++;
    }
}

/*打印通讯录*/
void Print_Contact(Contact *contact)
{
    if (contact->num == 0)
    {
        cout << "当前通讯录为空！" << endl;
        return;
    }
    cout << endl;
    cout << "姓名\t\t年龄\t性别\t电话\t\t\t地址" << endl;
    for (int i = 0; i < contact->num; i++)
    {
        cout << contact->people[i].name << "\t\t"
             << contact->people[i].age << "\t";
        if (contact->people[i].sex == 1)
        {
            cout << "男\t";
        }
        else
        {
            cout << "女\t";
        }
        cout << contact->people[i].Phone << "\t\t\t"
             << contact->people[i].Address << endl;
    }
    cout << endl;
}

/*删除联系人*/
void Delect_People(Contact *contact)
{
    if (contact->num == 0)
    {
        cout << "当前通讯录为空！" << endl;
        return;
    }
    string name;
    cout << "请输入要删除的联系人的姓名：" << endl;
    cin >> name;
    for (int i = 0; i < contact->num; i++)
    {
        if (name == contact->people[i].name)
        {
            for (int j = i; j < contact->num; j++)
            {
                contact->people[j] = contact->people[j + 1];
            }
        }
    }
    contact->num--;
    cout << "成功删除该联系人！" << endl;
}

/*查找联系人*/
void Find_People(Contact *contact)
{
    if (contact->num == 0)
    {
        cout << "当前通讯录为空！" << endl;
        return;
    }
    string name;
    cout << "请输入要查找的联系人的姓名：" << endl;
    cin >> name;
    int i = 0;
    // int k = 0;
    for (i = 0; i < contact->num; i++)
    {
        if (name == contact->people[i].name)
        {
            cout << endl;
            cout << "姓名\t\t年龄\t性别\t电话\t\t\t地址" << endl;
            cout << contact->people[i].name << "\t\t"
                 << contact->people[i].age << "\t"
                 << (contact->people[i].sex == 1 ? "男" : "女") << "\t"
                 << contact->people[i].Phone << "\t\t\t"
                 << contact->people[i].Address << endl;
            cout << endl;
            // k = 0;
            break;
        }
    }
    if (i == contact->num)
    {
        cout << "未找到该联系人！" << endl;
    }
}

/*修改联系人*/
void Revise_People(Contact *contact)
{
    if (contact->num == 0)
    {
        cout << "当前通讯录为空！" << endl;
        return;
    }
    string name;
    cout << "请输入要修改联系人的姓名：" << endl;
    cin >> name;
    for (int i = 0; i < contact->num; i++)
    {
        if (name == contact->people[i].name)
        {
            // cout << "请输入需要修改的选项：" << endl;
            // cout << "      1.姓名      " << endl;
            // cout << "      2.年龄      " << endl;
            // cout << "      3.性别      " << endl;
            // cout << "      4.电话      " << endl;
            // cout << "      5.地址      " << endl;
            // int k = 0;
            // cin >> k;
            // switch(k)
            // {
            //     case 1:
            //     {
            //         cin >> contact->people[i].name;
            //         break;
            //     }
            //     case 2:
            //     {
            //        cin >> contact->people[i].age;
            //        break;
            //     }
            //     case 3:
            //     {
            //         cout << "    1-----男    " << endl;
            //         cout << "    2-----女    " << endl;
            //         cin >> contact->people[i].sex;
            //         break;
            //     }
            //     case 4:
            //     {
            //         cin >> contact->people[i].Phone;
            //         break;
            //     }
            //     case 5:
            //     {
            //         cin >> contact->people[i].Address;
            //         break;
            //     }

            cout << "请输入联系人的姓名：" << endl;
            cin >> contact->people[i].name;

            cout << "请输入联系人的年龄：" << endl;
            cin >> contact->people[i].age;

            int sex = 0;
            while (1)
            {
                cout << "请输入联系人的性别：" << endl;
                cout << "    1-----男    " << endl;
                cout << "    2-----女    " << endl;
                cin >> sex;
                if (sex == 1 || sex == 2)
                {
                    contact->people[i].sex = sex;
                    break;
                }
                else
                {
                    cout << "输入错误，请重新输入！" << endl;
                }
            }

            cout << "请输入联系人的电话：" << endl;
            cin >> contact->people[i].Phone;

            cout << "请输入联系人的地址：" << endl;
            cin >> contact->people[i].Address;
        }
    }
    cout << "修改完成！" << endl;
}

/*清空通讯录*/
void Empty_Contact(Contact *contact)
{
    contact->num = 0;
    cout << "成功清空通讯录！" << endl;
}