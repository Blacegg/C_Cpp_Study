/***********************************************************************
 * @file     manager.cpp
 * @brief
 * @author   blacegg
 * @version  1.0
 * @date     2023-09-07
 ***********************************************************************/
#include "manager.h"

/***********************************************************************
 * @brief    Construct a new manager::manager object
 * @param    id:
 * @param    name:
 * @param    dId:
 ***********************************************************************/
Manager::Manager(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

/***********************************************************************
 * @brief    manager::showInfo
 ***********************************************************************/
void Manager::showInfo()
{
    cout << "职工编号： " << this->m_Id
         << " \t职工姓名： " << this->m_Name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
}

/***********************************************************************
 * @brief    manager::getDeptName
 * @return   string:
 ***********************************************************************/
string Manager::getDeptName()
{
    return string("经理");
}
