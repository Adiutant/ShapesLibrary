//
// Created by rlego on 08.02.2023.
//

#include "Math.h"
namespace Math {
    double get_continuous_from_discrete_coordinate(
            std::size_t discrete_coordinate,
            std::size_t discrete_range,
            double continuous_range,
            double continuous_minimum
    ) {
        const double ratio =
                static_cast<double>(discrete_coordinate) /
                static_cast<double>(discrete_range);

        return continuous_range * ratio + continuous_minimum;
    }

    signed long long int get_discrete_from_continuous_coordinate(
            double continuous_coordinate,
            std::size_t discrete_range,
            double continuous_range,
            double continuous_minimum
    ) {
        const double shifted = continuous_coordinate - continuous_minimum;
        const double ratio = shifted / continuous_range;

        return std::llround(static_cast<double>(discrete_range) * ratio);
    }
    double get_delta(double range_x, std::size_t length_x, double range_y, std::size_t length_y) {
        const double dx = range_x / static_cast<double>(length_x);
        const double dy = range_y / static_cast<double>(length_y);
        return get_distance(Point(dx, dy), Point(0.0, 0.0));
    }
    double get_distance(const Point& a, const Point& b) {
        return std::sqrt((a.x() - b.x()) * (a.x() - b.x()) + (a.y() - b.y()) * (a.y() - b.y()));
    }
}