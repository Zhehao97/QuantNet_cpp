//
//  Point.hpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/2/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The declaration of class Point

#ifndef Point_hpp
#define Point_hpp

#include <string>

class Point{
  
private:
    double m_x;
    double m_y;
    
public:
    // Constructor
    Point();                            // Default constructor
    
    // Destructor
    ~Point();
    
    // Selectors
    double GetX();                      // Return the value of x-coordinate
    double GetY();                      // Return the value of y-coordinate
    
    std::string ToString();             // Return the descripition of Point object
    
    double DistanceOrigin();            // Return the distance to origin (0, 0)
    double Distance(Point p);           // Return the distance to p
    
    
    // Modifers
    void SetX(double newX);             // Set the value of x-coordinate
    void SetY(double newY);             // Set the value of y-coordinate
    
};

#endif /* Point_hpp */
