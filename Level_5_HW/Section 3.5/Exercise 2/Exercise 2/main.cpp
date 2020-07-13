//
//  main.cpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Calling Base Class Functionality


#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    namespace CAD = ZhehaoLi::CAD;
     
    CAD::Shape s;                                                   // Create Shape
    CAD::Point p(10, 20);                                           // Create Point
    CAD::Line l(CAD::Point(1, 2), CAD::Point(3, 4));                // Create Line
    CAD::Circle c(CAD::Point(5, 6), 3.0);                           // Create Circle
    
    std::cout << s.ToString() << std::endl;                         // Print Shape
    std::cout << p.ToString() << std::endl;                         // Print Point
    std::cout << l.ToString() << std::endl;                         // Print Line
    std::cout << c.ToString() << std::endl;                         // Print Circle
    
    
    std::cout << "----------" << std::endl;
    
    CAD::Shape * sp;                                                // Create pointer to a shape variable
    
    sp = &p;
    std::cout << sp->ToString() << std::endl;
    
    sp = &l;
    std::cout << sp->ToString() << std::endl;
    
    sp = &c;
    std::cout << sp->ToString() << std::endl;
    
    return 0;
}
