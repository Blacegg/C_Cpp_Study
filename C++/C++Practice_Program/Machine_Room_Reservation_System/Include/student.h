#pragma once
#include <vector>
#include <fstream>
#include "../Include/identity.h"
#include "../Include/computerroom.h"
#include "../Include/globalfile.h"

class Student : public Identity
{
public:
    Student();
    Student(int id, string name, string pwd);
    void Show_OperMeun();
    void ApplyOrder();
    void Show_MyOrder();
    void Show_AllOrder();
    void CancelOrder();
    ~Student();

public:
    int m_Student_Id;
    vector<ComputerRoom> v_Com;
};
