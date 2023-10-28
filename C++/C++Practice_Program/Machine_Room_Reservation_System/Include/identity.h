#pragma once
#include <iostream>
using namespace std;

class Identity
{
public:
    Identity(){};
    Identity(string name, string pwd) : m_Name(name), m_Pwd(pwd){};
    virtual void Show_OperMeun() = 0;

public:
    string m_Name;
    string m_Pwd;
};