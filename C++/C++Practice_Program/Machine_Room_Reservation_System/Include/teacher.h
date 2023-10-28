#pragma once
#include <iostream>
using namespace std;
#include "../Include/identity.h"

class Teacher : public Identity
{
public:
    Teacher();
    Teacher(int Id, string name, string pwd);
    void Show_OperMeun();
    void Show_ALLOrder();
    void ValidOrder();
    ~Teacher();

public:
    int m_teacher_Id;
};