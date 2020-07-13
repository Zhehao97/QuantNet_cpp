//
//  Point.cpp
//  1 - Shared Pointers
//
//  Created by Zhehao Li on 2020/4/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Implementation of class 2D-Point


#include "Point.hpp"
#include <cmath>

/* Constructors */
Point::Point() : x(0), y(0){};                                  // Default Constructor
Point::Point(double xval, double yval) : x(xval), y(yval){};    // Constructor with values

/* Destructor */
Point::~Point(){
    std::cout << "Bye My Point..\n";
}

/* Accessing Functions */
double Point::X() const{
    return x;
}
double Point::Y() const{
    return y;
}

/* Modifier Functions */
void Point::X(double newX){
    x = newX;
}
void Point::Y(double newY){
    y = newY;
}

/* Operators */
std::ostream & operator << (std::ostream & os, const Point & pt){
    os << "(" << pt.x << "," << pt.y << ")";
    return os;
}
