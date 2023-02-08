//
// Created by rlego on 28.01.2023.
//

#include "Circle.h"

Circle::~Circle() {

}

Circle::Circle() : m_center{0.,0.}, m_radius(0.){

}

double Circle::radius() const {
    return m_radius;
}

bool Circle::isPointBelongToShape(const Point &point, const double delta) const {

    double pointSquares = pow(point.x() - m_center.x(),2)+ pow(point.y() -  m_center.y(),2);
    return pointSquares >= pow(m_radius - delta/4,2)  && pointSquares <= pow(m_radius+ delta/4,2)  ;
}

Circle::Circle(const Point &center, const double radius): m_center{center.x(), center.y()}, m_radius(radius) {

}

Point Circle::getCenter() const {
    return m_center;
}
void Circle::setCenter(const Point &center)  {
    m_center = center;
}

