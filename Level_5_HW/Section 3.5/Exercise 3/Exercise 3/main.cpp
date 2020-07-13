//
//  main.cpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/3/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Virtual Destructors

#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    namespace CAD = ZhehaoLi::CAD;
    
    CAD::Shape * shapes[4];
    
    shapes[0] = new CAD::Shape;
    shapes[1] = new CAD::Point;
    shapes[2] = new CAD::Line;
    shapes[3] = new CAD::Circle;
    
    for (int i = 0; i < 4; i++) {
        delete shapes[i];
        std::cout << "---------" << std::endl;
    }
    
    return 0;
}
