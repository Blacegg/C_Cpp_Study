#include "Contacts.hpp"

int main()
{
    int select = 0;
    Contact contact;

    Contact_Init(&contact);

    while (1)
    {
        menu();

        cin >> select;

        switch (select)
        {
        case 1: // 添加联系人
        {
            Add_People(&contact);
            break;
        }

        case 2: // 显示联系人
        {
            Print_Contact(&contact);
            break;
        }

        case 3: // 删除联系人
        {
            Delect_People(&contact);
            break;
        }

        case 4: // 查找联系人
        {
            Find_People(&contact);
            break;
        }

        case 5: // 修改联系人
        {
            Revise_People(&contact);
            break;
        }

        case 6: // 清空联系人
        {
            Empty_Contact(&contact);
            break;
        }

        case 0: // 退出系统
        {
            cout << "欢迎下次使用，谢谢！" << endl;
            system("pause");
            return 0;
            break;
        }

        default:
        {
            cout << "输入错误，请重新输入" << endl;
            break;
        }
        }
        system("pause"); // 按任意键继续
        system("cls");   // 清屏
    }
    return 0;
}