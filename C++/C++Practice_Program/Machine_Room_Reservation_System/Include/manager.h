/***********************************************************************
 * @file     manager.h
 * @brief
 * @author   blacegg
 * @version  1.0
 * @date     2023-10-16
 ***********************************************************************/
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

#include "../Include/identity.h"
#include "../Include/globalfile.h"
#include "../Include/student.h"
#include "../Include/teacher.h"
#include "../Include/computerroom.h"

class Manager : public Identity
{
public:
    Manager();
    Manager(string name, string pwd);
    void Show_OperMeun();
    void Add_Person();
    void Show_Person();
    void Show_ComputerRoom();
    void Clear_File();
    void Vector_Init();
    bool Check_Repeat(int id, int type);

public:
    vector<Student> v_Stu;
    vector<Teacher> v_Tea;
    vector<ComputerRoom> v_Com;
};