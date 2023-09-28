/***********************************************************************
 * @file     employee.cpp
 * @brief
 * @author   blacegg
 * @version  1.0
 * @date     2023-09-07
 ***********************************************************************/
#include "employee.h"

/***********************************************************************
 * @brief    Construct a new employee::employee object
 * @param    id:
 * @param    name:
 * @param    dId:
 ***********************************************************************/
Employee::Employee(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

/***********************************************************************
 * @brief    employee::showInfo
 ***********************************************************************/
void Employee::showInfo()
{
    cout << "ְ����ţ� " << this->m_Id
         << " \tְ�������� " << this->m_Name
         << " \t��λ��" << this->getDeptName()
         << " \t��λְ����ɾ�����������" << endl;
}

/***********************************************************************
 * @brief    employee::getDeptName
 * @return   string:
 ***********************************************************************/
string Employee::getDeptName()
{
    return string("Ա��");
}
