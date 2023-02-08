cmake_minimum_required(VERSION 3.21)
project(GeometryLibrary)

set(CMAKE_CXX_STANDARD 14)


add_library(GeometryLibrary  Shape.cpp Point/Point.cpp PrimitiveShapes/Circle.cpp Canvas/Canvas.cpp Math/Math.cpp)
#add_source(GeometryLibrary main.cpp)

add_executable( GeometryExec main.cpp)
target_link_libraries(GeometryExec  GeometryLibrary)

