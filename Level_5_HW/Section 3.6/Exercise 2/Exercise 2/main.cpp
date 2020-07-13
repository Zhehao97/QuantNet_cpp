//
//  main.cpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "Point.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    namespace CAD = ZhehaoLi::CAD;
    
    namespace CTD = ZhehaoLi::Containers;
    
    namespace EXP = ZhehaoLi::Exception;
    
    // Create some arrays
    CTD::Array A1(6);                                           // Test Default constructor

    // Modifying the element of array
    for (int i = 0; i < A1.Size(); i++) {                       // Test Size() function
        CAD::Point P1(1.0 + i, 2.0 + i);
        A1.SetElement(P1, i);                                   // Test SetElement() function
    }
    

    // Test GetElement()
    try {
        A1.GetElement(7);
    } catch (EXP::ArrayException & Err) {                       // Pass by reference
        
        std::cout << Err.GetMessage() <<std::endl;
    }
    
    
    // Test SetElement()
    ZhehaoLi::CAD::Point P2(2.2, 3.3);
    
    try {
        A1.SetElement(P2, -2);
    } catch (EXP::ArrayException & Err) {
        std::cout << Err.GetMessage() <<std::endl;
    }

    
    // Test Index operator []
    try {
        std::cout << A1[10] << std::endl;
    } catch (EXP::ArrayException & Err) {
        std::cout << Err.GetMessage() <<std::endl;
    }
    
    return 0;
}
