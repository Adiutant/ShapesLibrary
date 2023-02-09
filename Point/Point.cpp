//
// Created by rlego on 21.01.2023.
//

#include "Point.h"

Point::Point(const double x, const double y) : m_x(x), m_y(y){

}

Point::Point() : m_x(0.), m_y(0.) {

}

double Point::x() const {
    return m_x;
}

double Point::y() const {
    return m_y;
}

double Point::GetDistance(const Point &point) const {
    return sqrt(pow(point.x() - m_x, 2)+pow(point.y() - m_y, 2));
}

Point::Point(const Point &another) {
    m_y = another.m_y;
    m_x = another.m_x;
}

