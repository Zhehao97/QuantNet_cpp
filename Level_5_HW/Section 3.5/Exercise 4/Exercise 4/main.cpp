//
//  main.cpp
//  Exercise 4
//
//  Created by Zhehao Li on 2020/3/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Abstract Functions

#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    namespace CAD = ZhehaoLi::CAD;
    
//    CAD::Shape s;                               // Shape cannot be instanialized
    
    CAD::Shape * shapes[3];
    
    shapes[0] = new CAD::Line;
    shapes[1] = new CAD::Point;
    shapes[2] = new CAD::Circle;
    
    for (int i = 0; i < 3; i++){
        shapes[i]->Draw();
    }
        
    for (int i = 0; i < 3; i++){
        delete shapes[i];
    }
    
    return 0;
}
