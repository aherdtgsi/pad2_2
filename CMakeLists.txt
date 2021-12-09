cmake_minimum_required(VERSION 3.20)
project(pad2_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(pad2_2 main.cpp parkplatz.h parkhaus.h parkhaus.cpp parkplatz.cpp myarray.hpp myVector.hpp Tracer.hpp test_functions.h p3/frame.cpp p3/frame.h p3/tests.h p3/line.cpp p3/line.h p3/point.cpp p3/point.h p3/shape.cpp p3/shape.h p3/triangle.cpp p3/triangle.h p3/quadrilateral.cpp p3/quadrilateral.h myRangeVec.hpp)