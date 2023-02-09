//
// Created by rlego on 28.01.2023.
//

#include "Canvas.h"

Canvas::Canvas(int width, int height) : m_width{width}, m_height{height},
m_xAxisRange{static_cast<double>(width) * 0.45 },
m_yAxisRange{static_cast<double>(height) }
{

    m_matrix.resize(m_height);
    for (auto &line: m_matrix) {
        line.resize(m_width, false);
    }

    m_axisX.resize(m_width);

    const double dx  = m_xAxisRange / static_cast<double>(m_width);
    double current_x = 0.0;
    for (std::size_t column = 0ull; column < m_width; ++column) {
        m_axisX[column] = current_x;
        current_x += dx;
    }

    m_axisY.resize(m_width);


    const double dy  = m_yAxisRange / static_cast<double>(m_height);
    double current_y = 0.0;
    for (std::size_t row = 0ull; row < m_height; ++row) {
        m_axisY[row] = current_y;
        current_y += dy;
    }

    for (std::size_t row = 0ull; row < m_height; ++row) {
        m_matrix[row][m_width-1] = true;
    }
    for (std::size_t row = 0ull; row < m_height; ++row) {
        m_matrix[row][0] = true;
    }
    for (std::size_t column = 0ull; column < m_width; ++column) {
        m_matrix[m_height-1][column] = true;
    }
    for (std::size_t column = 0ull; column < m_width; ++column) {
        m_matrix[0][column] = true;
    }



}
double Canvas::get_x_from_column(std::size_t column) const {
    return Math::get_continuous_from_discrete_coordinate(
            column,
            m_width,
            m_xAxisRange,
            0.0
    );
}

double Canvas::get_y_from_row(std::size_t row) const {
    return Math::get_continuous_from_discrete_coordinate(
            row,
            m_height,
            m_yAxisRange,
            0.0
    );
}

std::size_t Canvas::get_column_from_x(double x) const {
    const signed long long int column = Math::get_discrete_from_continuous_coordinate(
            x,
            m_width,
            m_xAxisRange,
            0.0
    );
    if (column < 0)
        return 0ull;
    if (column >= static_cast<signed long long>(m_width))
        return m_width - 1ull;

    return column;
}

std::size_t Canvas::get_row_from_y(double y) const {
    const signed long long int row = Math::get_discrete_from_continuous_coordinate(
            y,
            m_height,
            m_yAxisRange,
            0.0
    );
    if (row < 0)
        return 0ull;
    if (row >= static_cast<signed long long>(m_height))
        return m_height - 1ull;

    return row;
}

Canvas::Canvas() : m_height{0}, m_width{0}{

}

Canvas::~Canvas() {

}

void Canvas::draw(Shape &shape) {
    const double delta = Math::get_delta(m_xAxisRange, m_width, m_yAxisRange, m_height);
    for (std::size_t i = 0u; i < m_height; i++) {
        double y = get_y_from_row(i);
        for (std::size_t j = 0u; j < m_width; j++) {
            double x = get_x_from_column(j);
            int test = get_column_from_x(x);
            if (shape.isPointBelongToShape(Point(x ,y),delta)){
                m_matrix[i][j] = true;
            }
        }
    }
}

void Canvas::printCanvas() {
    for (auto &line : m_matrix) {
        for (auto &&point: line){
            if (point){
                std::cout << '.';
            } else {
                std::cout << " ";
            }
        }
        std::cout << '\n';
    }

}


