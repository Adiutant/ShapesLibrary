//
// Created by rlego on 08.02.2023.
//

#include "Math.h"
namespace Math {

    Equation solveSoLE(Matrix a, Matrix b){
        double determinant = a[0][0] * a[1][1] - a[0][1] * a[1][0];
        auto minor  =  a.GetMinorMatrix();
        minor[0][1] *= -1;
        minor[1][0] *= -1;
        minor.Transpose();
        auto  reverseMatrix = minor.getReverseMatrix(determinant);
        Matrix x = reverseMatrix * b;
        if (std::isnan(x.At(0,0))){
            x[0][0]= 0.;
        }
        if (std::isnan(x.At(1,0))){
            x[1][0]= 0.;
        }
        return Equation{x.At(0, 0), x.At(1, 0)};

    }
    bool isBetweenPoints(const Point& current, const  Point& first, const  Point& second) {
       // auto dxc = current.x() - first.x();
        //auto dyc = current.y() - first.y();

        auto dxl = second.x() - first.x();
        auto dyl = second.y() - first.y();
        if (std::abs(dxl) >= std::abs(dyl))
            return dxl > 0 ?
                   first.x() <= current.x() && current.x() <= second.x() :
                   second.x() <= current.x() && current.x() <= first.x();
        else
            return dyl > 0 ?
                   first.y() <= current.y() && current.y() <= second.y() :
                   second.y() <= current.y() && current.y() <= first.y();
    }

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