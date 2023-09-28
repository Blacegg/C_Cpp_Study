#pragma once
#include <iostream>
#include "point.hpp"
using namespace std;

class Circle
{
private:
    int m_radius;
    Point m_center;

public:
    int get_m_radius();
    Point get_m_center();

    void set_m_radius(int radius);
    void set_m_center(Point &center);

    string connect(Point &point);
};