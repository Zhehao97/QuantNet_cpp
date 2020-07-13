//
//  Point.hpp
//  Exercise 1
//
//  Created by Zhehao Li on 2020/2/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  This file is the declaration of class Point

#ifndef Point_hpp
#define Point_hpp

#include <iostream>
#include <string>

class Point{
  
private:
    double m_x;
    double m_y;
    
public:
    // Constructor
    Point();                    // Default constructor
    
    // Destructor
    ~Point();
    
    // Selectors
    double GetX();
    double GetY();
    std::string ToString();
    
    // Modifers
    void SetX(double newX);
    void SetY(double newY);
    
    
    
};

#endif /* Point_hpp */
