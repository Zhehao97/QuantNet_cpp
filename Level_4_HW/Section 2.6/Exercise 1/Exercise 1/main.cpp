//
//  main.cpp
//  Exercise 1
//
//  Created by Zhehao Li on 2020/3/11.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    /* Test Point class */
    ZhehaoLi::CAD::Point P1;                                // Full namespace for Point class
    ZhehaoLi::CAD::Point P2(8, 10);
    ZhehaoLi::CAD::Point P3(16, 9);
    
    
    /* Test Line Class */
    using ZhehaoLi::CAD::Line;                              // Declaration for using a single class (Line).

    Line L1;
    Line L2(P2, P3);
    
    std::cout << L1 << std::endl;
    L1 = L2;
    std::cout << L1 << std::endl;
    
    
    /* Test Circle class */
    namespace ZLCAD = ZhehaoLi::CAD;                        // Creating a shorter alias for the ZhehaoLi::CAD namespace.
    
    ZLCAD::Circle C1;
    ZLCAD::Circle C2(P2, 3.0);
    
    std::cout << C1 << std::endl;
    C1 = C2;
    std::cout << C1 << std::endl;
    
    
    /* Test Array Class */
    using namespace ZhehaoLi::Containers;                   // Directives for a complete namespace (Containers).
    
    // Create some arrays
    Array A1;                                               // Test Default constructor
    Array A2(6);                                            // Test constructor with argument
    
    // Modifying the element of array
    for (int i = 0; i < A1.Size(); i++) {                   // Test Size() function
        ZhehaoLi::CAD::Point P4(1.0 + i, 2.0 + i);
        A1.SetElement(P4, i);                               // Test SetElement() function
        std::cout << A1.GetElement(i) << std::endl;         // Test GetElment() function
    }
    
    for (int i = 0; i < A2.Size(); i++) {
        ZhehaoLi::CAD::Point P5(-1.0 - i, -2.0 - i);
        A2[i] = P5;                                         // Test = and [] operator
        std::cout << A2[i] << std::endl;
    }
    
    Array A3(A2);                                           // Test Copy consturctor
    
    for (int i = 0; i < A3.Size(); i++) {
        std::cout << A3[i] << std::endl;                    // Test const [] operator
    }
    
    return 0;
}
