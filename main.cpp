//
// Created by rlego on 28.01.2023.
//


#include "Canvas/Canvas.h"
#include "PrimitiveShapes/Circle.h"

#include <iostream>
#include <memory>

int main(){
    Canvas canvas(60,20);
    Circle c(
            Point(5, 0),
            2
    );
    canvas.draw(c);
    canvas.printCanvas();
}