#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
    int m_x;
    int m_y;

public:
    int get_m_x();
    int get_m_y();

    void set_m_x(int x);
    void set_m_y(int y);
};