#ifndef GEOMETRYLIBRARY_SHAPE_H
#define GEOMETRYLIBRARY_SHAPE_H
#include "Point/Point.h"
#include "Math/Math.h"
class Shape {




public:
    virtual bool isPointBelongToShape(const Point& point, double delta) const =0;
    virtual Point getCenter() const = 0;
    virtual void setCenter(const Point &center) = 0;
    virtual ~Shape();
};

#endif //GEOMETRYLIBRARY_SHAPE_H
