//
//  main.cpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/3/26.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Exercise 3: Point Array (concrete inheritance)

#include "Point.hpp"
#include "PointArray.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    namespace CAD = ZhehaoLi::CAD;
    namespace CTN = ZhehaoLi::Containers;
    
    /* Test constructors */
    CTN::PointArray pArr_1;             // Default constructor
    CTN::PointArray pArr_2(8);          // Constructor with arguments
    
    /* Set the value of Point Array */
    for (int i = 0; i < pArr_1.Size(); i++) {
        pArr_1.SetElement(CAD::Point(3 * i, -4 * i), i);
    }
    
    for (int i = 0; i < pArr_2.Size(); i++) {
        pArr_2.GetElement(i) = CAD::Point(-0.3 * i, 0.4 * i);   // Assignment operator
    }
    
    CTN::PointArray pArr_3(pArr_2);     // Copy consturctor
    
    std::cout << "Length of point array 1: " << pArr_1.Length() << std::endl;
    std::cout << "Length of point array 3: " << pArr_3.Length() << std::endl;
    
    return 0;
}
