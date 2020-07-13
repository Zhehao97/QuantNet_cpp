//
//  Point.hpp
//  Exercise 4
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
    Point();                                            // Default constructor
    Point(double newX, double newY);                    // Constructor passed with values
    Point(const Point &pt);                             // Copy constructor, call by reference
    
    // Destructor
    ~Point();
    
    // Selectors
    double X() const;                                   // Return the value of x-coordinate
    double Y() const;                                   // Return the value of y-coordinate
    std::string ToString() const;                       // Return the descripition of Point object
    double Distance() const;                            // Return the distance to origin (0, 0)
    double Distance(const Point &pt) const;             // Return the distance to p      (function overloading)
    
    // Modifers
    void X(double newX) {m_x = newX;}                   // Set the value of x-coordinate (function overloading)
    void Y(double newY) {m_y = newY;}                   // Set the value of y-coordinate (function overloading)
    
};

inline double Point::X() const {return m_x;}
inline double Point::Y() const {return m_y;}

#endif /* Point_hpp */
