//
//  Point.hpp
//  1 - Shared Pointers
//
//  Created by Zhehao Li on 2020/4/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Declaration of class 2D-Point

#ifndef Point_hpp
#define Point_hpp

#include <iostream>

class Point{
    
private:
    double x;           // X coordinate
    double y;           // Y coordinate
    
public:
    /* Constructors */
    Point();                            // Defualt constructor
    Point(double xval, double yval);    // Constructor with values
    
    /* Destructor */
    ~Point();
    
    /* Accessing Functions */
    double X() const;
    double Y() const;
    
    /* Modifier Functions */
    void X(double newX);
    void Y(double newY);
    
    /* Operators */
    friend std::ostream & operator << (std::ostream & os, const Point & pt);
    
};

#endif /* Point_hpp */
