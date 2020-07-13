//
//  Line.hpp
//  Exercise 5
//
//  Created by Zhehao Li on 2020/2/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The declaration of class Line

#ifndef Line_hpp
#define Line_hpp

#include "Point.hpp"
#include <string>
#include <iostream>

class Line{
  
private:
    Point startPoint;
    Point endPoint;
    
public:
    // Constructor
    Line();                                     // Default consturctor                   (*****)
    Line(const Point &pt1, const Point &pt2);   // Constructor with two arguments
    Line(const Line &l);                        // Copy constructor                      (*****)
    
    // Destructor
    ~Line();                                    // (*****)
    
    // Member operator overloading
    Line & operator = (const Line & source);    // Asignment operator                    (*****)
    
    // Accessing functions
    Point StartPoint() const;                   // Const functions, may not change the value of data members
    Point EndPoint() const;
    std::string ToString() const;
    double Length() const;
    
    // Modifiers
    void StartPoint(const Point &sp);          // Const arguments, may not change the value of object refering to
    void EndPoint(const Point &ep);
    
    // Global Operator overloading
    friend std::ostream & operator << (std::ostream & os, const Line & l);
    
};

// Global operator overloading
//std::ostream & operator << (std::ostream & os, const Line & l);    // Send to ostream

#endif /* Line_hpp */
