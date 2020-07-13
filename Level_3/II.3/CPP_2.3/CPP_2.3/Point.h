//
//  Point.h
//  CPP_2.3
//
//  Created by Zhehao Li on 2020/2/26.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef Point_h
#define Point_h

#include <iostream>

class Point {

private:
    double x;
    double y;
    
public:
    // Constructor
    Point();                                    // Default constructor
    Point(double xval, double yval);            // Initialize with x and y value
    
    // Destructor
    ~Point();
    
    // Accessing Functions
    double get_X() const;                       // function may not change the member data
    double get_Y() const;                       // function may not change the member data
    
    double set_X(double newX);
    double set_Y(double newY);
    
    double Distance(const Point &pt) const;     // function may not change the member data and change Point pt, call by reference
    Point Add(const Point &pt) const;
};

#endif /* Point_h */
