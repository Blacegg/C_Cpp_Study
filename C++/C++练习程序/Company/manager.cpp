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
    cout << "ְ����ţ� " << this->m_Id
         << " \tְ�������� " << this->m_Name
         << " \t��λ��" << this->getDeptName()
         << " \t��λְ������ϰ彻��������,���·������Ա��" << endl;
}

/***********************************************************************
 * @brief    manager::getDeptName
 * @return   string:
 ***********************************************************************/
string Manager::getDeptName()
{
    return string("����");
}
