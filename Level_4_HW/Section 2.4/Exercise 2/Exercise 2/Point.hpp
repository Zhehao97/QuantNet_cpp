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
#include <iostream>

class Point{
  
private:
    double m_x;
    double m_y;
    
public:
    // Constructor
    Point();                                            // Default constructor                   (*****)
    Point(double newX, double newY);                    // Constructor passed with values
    Point(const Point &pt);                             // Copy constructor, call by reference   (*****)
    
    // Destructor
    ~Point();                                           // (*****)
    
    // Member operator overloading
    Point operator - () const;                          // Negate the coordinates
    Point operator * (double factor) const;             // Scale the coordinates
    Point operator + (const Point & p) const;           // Add coordinates
    bool operator == (const Point & p) const;           // Equally compare operator
    Point & operator =  (const Point & source);         // Asignment operator                    (*****)
    Point & operator *= (double factor);                // Scale the coordinates & assign
    
    // Accessing functions
    double X() const;                                   // Return the value of x-coordinate
    double Y() const;                                   // Return the value of y-coordinate
    std::string ToString() const;                       // Return the descripition of Point object
    double Distance() const;                            // Return the distance to origin (0, 0)
    double Distance(const Point & pt) const;            // Return the distance to p      (function overloading)
    
    // Modifers
    void X(double newX);                                // Set the value of x-coordinate (function overloading)
    void Y(double newY);                                // Set the value of y-coordinate (function overloading)
    
};

// Global operator overloading
std::ostream & operator << (std::ostream & os, const Point & p);    // Send to ostream

#endif /* Point_hpp */
