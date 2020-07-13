//
//  main.cpp
//  Exercise 5
//
//  Created by Zhehao Li on 2020/3/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Template Method Pattern


#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    namespace CAD = ZhehaoLi::CAD;
    
    CAD::Point p;
    CAD::Line l;
    CAD::Circle c;
    
    /* Template Method Pattern */
    p.Print();                                  // Print() is a member function inherited from abstrac base class
    l.Print();                                  // Only part of Print() that is different for each derived class  (ToString())
    c.Print();                                  // It is delegated to a polymorphic function ToString() inside the function
    
    return 0;
}
