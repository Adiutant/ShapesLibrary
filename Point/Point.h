//
// Created by rlego on 21.01.2023.
//

#ifndef GEOMETRYLIBRARY_POINT_H
#define GEOMETRYLIBRARY_POINT_H
#include <cmath>


class Point {
public:
    Point();
    Point(const Point& another);
    Point(double x, double y);
    double x() const;
    double y() const;
    double GetDistance(const Point& point) const;
private:
    double m_x, m_y;
};


#endif //GEOMETRYLIBRARY_POINT_H
