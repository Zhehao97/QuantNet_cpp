//
//  Circle.hpp
//  Exercise 6
//
//  Created by Zhehao Li on 2020/2/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include "Point.hpp"
#include <string>

class Circle{
    
private:
    Point centerPoint;
    double radius;
    
public:
    // Constructor
    Circle();                                           // Default constructor
    Circle(const Point &cp, const double &r);           // Consturctor with two arguments
    Circle(const Circle &c);                            // Copy constructor

    // Destructor
    ~Circle();
    
    // Selectors
    Point CentralPoint() const;
    double Radius() const;
    double Diameter() const;
    double Area() const;
    double Circumference() const;
    std::string ToString() const;
    
    // Modifiers
    void CentralPoint(const Point &cp);
    void Radius(const double &r);
    
};

#endif /* Circle_hpp */
