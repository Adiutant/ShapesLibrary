//
// Created by rlego on 28.01.2023.
//


#include "Canvas/Canvas.h"
#include "PrimitiveShapes/Circle.h"

#include <iostream>
#include <memory>
#include "PrimitiveShapes/Polygon.h"

int main(){
    Canvas canvas(60,20);
    Circle c(
            Point(5, 7),
            3
    );

    auto a = Matrix(2,2);
    a[0][0] = -5;
    a[0][1] = 1;
    a[1][0] = 7;
    a[1][1] = 1;
    auto b = Matrix(2,1);
    b[0][0] = 1;
    b[1][0] = -4;
    auto polygon = Polygon({{1,1},{11,1},{25,10}, {8,10}});
    canvas.draw(polygon);
    canvas.draw(c);
    canvas.printCanvas();

}