//
//  main.cpp
//  CPP_2.3
//
//  Created by Zhehao Li on 2020/2/26.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test Point

#include "Point.hpp"
#include "LineSegment.hpp"
#include <iostream>
using namespace std;


void print(const Point &pt){                    // Call by reference
    cout << "(" << pt.get_X() << "," << pt.get_Y() << ")" << endl;
//    pt.set_X(123.0);                              // Member functions should be const, if we call by reference const
}

int main(int argc, const char * argv[]) {
    
    Point p1;                                   // Create a point with default initialization
    
    double d = p1.get_X();
    cout << d << endl;
    
    Point p2(1.0, 2.0);                         // Create a point with specific initialization
    print(p2);                                  // Call by value -> make a copy of original point, thus a new object was created
    
    LineSegment L1(p1, p2);                     // Creat a line segemeent with 2 points
    
    return 0;
}
