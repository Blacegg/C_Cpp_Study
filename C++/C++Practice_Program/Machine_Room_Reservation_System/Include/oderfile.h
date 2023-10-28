#pragma once
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

#include "../Include/globalfile.h"

class OrderFile
{
public:
    OrderFile();
    ~OrderFile();
    void UpdateOrder();

public:
    map<int, map<string, string>> m_orderdata;
    int m_size;
};