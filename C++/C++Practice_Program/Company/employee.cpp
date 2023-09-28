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
    cout << "职工编号： " << this->m_Id
         << " \t职工姓名： " << this->m_Name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：完成经理交给的任务" << endl;
}

/***********************************************************************
 * @brief    employee::getDeptName
 * @return   string:
 ***********************************************************************/
string Employee::getDeptName()
{
    return string("员工");
}
