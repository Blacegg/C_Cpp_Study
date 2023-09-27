/***********************************************************************
 * @file     workerManager.h
 * @brief
 * @author   blacegg
 * @version  1.0
 * @date     2023-09-07
 ***********************************************************************/

#pragma once
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

#define FILENAME "empFile.txt"

class WorkManager
{
public:
    WorkManager();

    void Show_Menu();
    void exitSystem();
    Worker **m_EmpArray;
    void Add_Emp();
    void Save();
    int get_EmpNum();
    void init_Emp();
    void Show_Emp();
    void Del_Emp();
    void Mod_Emp();
    void Find_Emp();
    void Sort();
    void Clean_File();
    int IsExist(int Id);

    ~WorkManager();

    int m_EmpNum;
    bool m_FileIsEmpty;
};