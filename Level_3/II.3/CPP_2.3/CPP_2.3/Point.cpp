//
//  Point.cpp
//  CPP_2.3
//
//  Created by Zhehao Li on 2020/2/26.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "Point.hpp"
#include <cmath>
using namespace std;


//Point::Point() : x(0), y(0)                     // Colon syntax
//Point::Point(double newx, double newy) : x(newx), y(newy)               

Point::Point(){                                 // Default constructor
    x = y = 0.0;
}

Point::Point(double newx, double newy){         // Initializing using newx and newy
    x = newx;
    y = newy;
}

Point::~Point(){                                // Destructor
    cout << "Bye my point..." << endl;
}

double Point::get_X() const{
    return x;
}

double Point::get_Y() const{
    return y;
}

void Point::set_X(double newx){
    x = newx;
}

void Point::set_Y(double newy){
    x = newy;
}

