//
// Created by rlego on 28.01.2023.
//

#ifndef GEOMETRYLIBRARY_CIRCLE_H
#define GEOMETRYLIBRARY_CIRCLE_H


#include "../Point/Point.h"
#include "../Shape.h"

class Circle :public Shape {
public:
    Circle();
    Circle(const Point& center, double radius);
    ~Circle() override;
    double radius() const;
    bool isPointBelongToShape(const Point& point,double delta) const override;
//    Point getCenter() const override;
//    void setCenter(const Point &center) override;
private:
    double m_radius;
    Point m_center;


};


#endif //GEOMETRYLIBRARY_CIRCLE_H
