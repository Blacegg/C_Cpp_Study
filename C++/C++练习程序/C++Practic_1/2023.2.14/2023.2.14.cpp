#include <iostream>
#include <string>
#include "point.hpp"
#include "circle.hpp"
using namespace std;

// class Point
// {
// public:
//     int m_x, m_y;
// };

// class Circle
// {
// public:
//     int m_radius;
//     Point m_center;

//     string connect(Point &point)
//     {
//         int m = point.m_x ^ 2 + point.m_y ^ 2;
//         if (m > m_radius ^ 2)
//         {
//             return "1:点在圆外";
//         }
//         else if (m < m_radius)
//         {
//             return "2:点在圆内";
//         }
//         else
//         {
//             return "3:点在圆上";
//         }
//     }
// };

int main()
{
    Point center1;
    center1.set_m_x(5);
    center1.set_m_y(5);

    Point center2;
    center2.set_m_x(0);
    center2.set_m_y(0);

    Circle circle;
    circle.set_m_center(center2);
    circle.set_m_radius(3);

    cout << circle.connect(center1) << endl;

    return 0;
}