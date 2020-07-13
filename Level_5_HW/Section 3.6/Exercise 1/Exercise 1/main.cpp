//
//  main.cpp
//  Exercise 1
//
//  Created by Zhehao Li on 2020/3/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "Array.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    using namespace ZhehaoLi::Containers;                       // Directives for a complete namespace (Containers).
    
    // Create some arrays
    Array A1(6);                                                // Test Default constructor

    // Modifying the element of array
    for (int i = 0; i < A1.Size(); i++) {                       // Test Size() function
        ZhehaoLi::CAD::Point P1(1.0 + i, 2.0 + i);
        A1.SetElement(P1, i);                                   // Test SetElement() function
    }
    

    // Test GetElement()
    try {
        A1.GetElement(7);
    } catch (int err) {
        if (err == -1){
            std::cout << "out of bounds error!" << std::endl;
        }
    }
    
    
    // Test SetElement()
    ZhehaoLi::CAD::Point P2(2.2, 3.3);
    
    try {
        A1.SetElement(P2, 8);
    } catch (int err) {
        if (err == -1){
            std::cout << "out of bounds error!" << std::endl;
        }
    }

    
    // Test Index operator []
    try {
        std::cout << A1[10] << std::endl;
    } catch (int err) {
        if (err == -1){
            std::cout << "out of bounds error!" << std::endl;
        }
    }
    
    
    return 0;
}
