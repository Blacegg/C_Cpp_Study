/***********************************************************************
 * @file     employee.h
 * @brief
 * @author   blacegg
 * @version  1.0
 * @date     2023-09-07
 ***********************************************************************/
#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Employee : public Worker
{
public:
    Employee(int id, string name, int dId);
    void showInfo();
    string getDeptName();
};