/***********************************************************************
 * @file     main.cpp
 * @brief
 * @author   blacegg
 * @version  1.0
 * @date     2023-09-07
 ***********************************************************************/

#include "workerManager.h"
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

/***********************************************************************
 * @brief    main
 * @return   int:
 ***********************************************************************/
int main()
{
    WorkManager wm;

    int choice = 0;
    while (true)
    {
        wm.Show_Menu();
        cout << "���������ѡ��" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0: // �˳�ϵͳ
            wm.exitSystem();
            break;
        case 1: // ���ְ��
            wm.Add_Emp();
            break;
        case 2: // ��ʾְ��
            wm.Show_Emp();
            break;
        case 3: // ɾ��ְ��
            wm.Del_Emp();
            break;
        case 4: // �޸�ְ��
            wm.Mod_Emp();
            break;
        case 5: // ����ְ��
            //wm.Find_Emp();
            break;
        case 6: // ����ְ��
            //wm.Sort();
            break;
        case 7: // ����ļ�
            //wm.Clean_File();
            break;
        default:
            //system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}