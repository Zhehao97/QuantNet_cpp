//
//  main.cpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test Inheritance


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
    
    std::cout << "Shape ID: " << s.ID() << std::endl;               // ID of the Shape
    std::cout << "Point ID: " << p.ID() << std::endl;               // ID of the Point -->  Does this work?     -- Yes!
    std::cout << "Line ID: " << l.ID() << std::endl;                // ID of the Line  -->  Does this work?     -- Yes!
    std::cout << "Circle ID: " << c.ID() << std::endl;              // ID of the Circle --> Does this work?     -- Yes!
    
    CAD::Shape * sp;                                                // Create pointer to a shape variable
    sp = &p;                                                        // Point in a shape variable, Possible?     -- Yes!
    std::cout << sp->ToString() << std::endl;                       // What is printed?                         -- The ID of a Shape obj
    
    CAD::Point p2;                                                  // Create and copy p to new point
    p2 = p;
    std::cout << p2 << ", " << p2.ID() << std::endl;                // << global operator over loading in Point class
                                                                    // Is the ID copied if you do not call the base class assginment in point? -- No!
    
    return 0;
}
