//
// Created by rlego on 09.02.2023.
//

#ifndef GEOMETRYLIBRARY_POLYGON_H
#define GEOMETRYLIBRARY_POLYGON_H
#include "../Shape.h"
#include <vector>
#include "../Math/Math.h"
#include "../Math/Matrix.h"

class Polygon : public Shape {
public:
    explicit Polygon(const std::vector<Point> &newPoints);
    ~Polygon() override;
    bool isPointBelongToShape(const Point& point,double delta) const override;

private:
    void initializeLine(const std::vector<Point>& points);
    void initializePolygon(const std::vector<Point>& points);
    std::vector<Math::Equation> mEquations;
};


#endif //GEOMETRYLIBRARY_POLYGON_H
