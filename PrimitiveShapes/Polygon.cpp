//
// Created by rlego on 09.02.2023.
//

#include "Polygon.h"


Polygon::Polygon(const std::vector<Point>& points){

    if (points.size() ==2){
        initializeLine(points);
    }
    if (points.size() > 2){
        initializePolygon(points);
    }


}

void Polygon::initializeLine(const std::vector<Point>& points) {


    Matrix matrixA(2,2);
    matrixA[0][0] = points[0].x();
    matrixA[0][1] = 1;
    matrixA[1][0] = points[1].x();
    matrixA[1][1] = 1;

    Matrix matrixB(2,1);
    matrixB[0][0] = points[0].y();
    matrixB[1][0] = points[1].y();
    auto equation = Math::solveSoLE(matrixA,matrixB);
    if (points[0].x() == points[1].x() ){
        equation.b = points[0].x();
        equation.isForX = false;
    }
    equation.leftEdge = points[0];
    equation.rightEdge = points[1];
    mEquations.emplace_back(equation);


}
void Polygon::initializePolygon(const std::vector<Point>& points){
    for (size_t pointIndex = 0; pointIndex < points.size(); pointIndex++) {

        Matrix matrixA(2,2);
        matrixA[0][0] = points[pointIndex].x();
        matrixA[0][1] = 1;
        matrixA[1][0] = points[(pointIndex + 1) % points.size()].x();
        matrixA[1][1] = 1;

        Matrix matrixB(2,1);
        matrixB[0][0] = points[pointIndex].y();
        matrixB[1][0] = points[(pointIndex + 1) % points.size()].y();

        auto equation = Math::solveSoLE(matrixA,matrixB);
        if (points[pointIndex].x() == points[(pointIndex + 1) % points.size()].x() ){
            equation.b = points[pointIndex].x();
            equation.isForX = false;
        }
        equation.leftEdge = points[pointIndex];
        equation.rightEdge = points[(pointIndex + 1) % points.size()];
        mEquations.emplace_back(equation);
    }
}

Polygon::~Polygon() {

}

bool Polygon::isPointBelongToShape(const Point &point, double delta) const {
    if (mEquations.size() == 1){}
    for (const auto &equation: mEquations) {
        double count;
        if (equation.isForX)
        {
            count = equation.countForX(point.x());
            if ((count > point.y() - delta / 4 &&
                 count < point.y() + delta / 4) &&
                Math::isBetweenPoints(point, equation.leftEdge, equation.rightEdge)) {
//            if (equation.countForX(point.x()) == point.y() ) {
                return true;
            }
        } else{
            count = equation.countForY(point.y());
            if ((count > point.x() - delta / 4 &&
                 count < point.x() + delta / 4) &&
                Math::isBetweenPoints(point, equation.leftEdge, equation.rightEdge)) {
//            if (equation.countForX(point.x()) == point.y() ) {
                return true;
            }
        }

    }

    return false;
}
