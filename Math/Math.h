//
// Created by rlego on 08.02.2023.
//

#ifndef GEOMETRYLIBRARY_MATH_H
#define GEOMETRYLIBRARY_MATH_H

#include <cmath>

#include "../Point/Point.h"
#include "Matrix.h"

namespace Math {
    struct Equation {
        double k{};
        double b{};
        bool isForX{true};
        Equation(double new_k, double new_b){
            k = new_k; b = new_b;
        };
        double countForX(double x) const{
            return k*x + b;
        }
        double countForY(double y) const{
            return k*y + b;
        }
        Point leftEdge;
        Point rightEdge;
    };

    bool isBetweenPoints(const Point& current,const  Point& first, const  Point& second) ;

    double get_continuous_from_discrete_coordinate(
            std::size_t discrete_coordinate,
            std::size_t discrete_range,
            double continuous_range,
            double continuous_shift = 0.0
    );


    signed long long int get_discrete_from_continuous_coordinate(
            double continuous_coordinate,
            std::size_t discrete_range,
            double continuous_range,
            double continuous_minimum = 0.0
    );
    double get_delta(double range_x, std::size_t length_x, double range_y, std::size_t length_y);
    double get_distance(const Point& a, const Point& b);
    Equation solveSoLE(Matrix a, Matrix b);
}


#endif //GEOMETRYLIBRARY_MATH_H
