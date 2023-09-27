#include <iostream>
#include "circle.hpp"
using namespace std;

int Circle::get_m_radius()
{
    return m_radius;
}

Point Circle::get_m_center()
{
    return m_center;
}

void Circle::set_m_radius(int radius)
{
    m_radius = radius;
}
void Circle::set_m_center(Point &center)
{
    m_center = center;
}

string Circle::connect(Point &point)
{
    int m = point.get_m_x() ^ 2 + point.get_m_y() ^ 2;
    if (m > m_radius ^ 2)
    {
        return "1:点在圆外";
    }
    else if (m < m_radius)
    {
        return "2:点在圆内";
    }
    else
    {
        return "3:点在圆上";
    }
}