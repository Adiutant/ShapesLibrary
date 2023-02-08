//
// Created by rlego on 28.01.2023.
//

#ifndef GEOMETRYLIBRARY_CANVAS_H
#define GEOMETRYLIBRARY_CANVAS_H
#include <vector>
#include <iostream>
#include "../Shape.h"
#include "../Math/Math.h"

class Canvas {
public:
    Canvas(int width, int height);
    Canvas();
    void draw(Shape &shape);
    void printCanvas();
    ~Canvas();
private:
    int m_width, m_height;
    double m_xAxisRange, m_yAxisRange;
    std::vector<double> m_axisX, m_axisY;
    std::vector<std::vector<bool>> m_matrix;

    size_t get_row_from_y(double y) const;

    size_t get_column_from_x(double x) const;

    double get_y_from_row(size_t row) const;

    double get_x_from_column(size_t column) const;
};


#endif //GEOMETRYLIBRARY_CANVAS_H
