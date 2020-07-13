//
//  Point.hpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/2/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The declaratioin of class Point

#ifndef Point_hpp
#define Point_hpp

#include <string>

class Point{
  
private:
    double m_x;
    double m_y;
    
public:
    // Constructor
    Point();                                    // Default constructor
    Point(double newX, double newY);            // Constructor passed with values
    Point(const Point &pt);                     // Copy constructor, call by reference
    
    // Destructor
    ~Point();
    
    // Selectors
    double X();                                 // Return the value of x-coordinate
    double Y();                                 // Return the value of y-coordinate
    std::string ToString();                     // Return the descripition of Point object
    double Distance();                          // Return the distance to origin (0, 0)
    double Distance(const Point &pt);           // Return the distance to p      (function overloading)
    
    // Modifers
    void X(double newX);                        // Set the value of x-coordinate (function overloading)
    void Y(double newY);                        // Set the value of y-coordinate (function overloading)
    
};

#endif /* Point_hpp */
