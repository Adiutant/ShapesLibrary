//
// Created by rlego on 08.02.2023.
//

#ifndef GEOMETRYLIBRARY_MATH_H
#define GEOMETRYLIBRARY_MATH_H

#include <cmath>

#include "../Point/Point.h"

namespace Math {


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
}


#endif //GEOMETRYLIBRARY_MATH_H
