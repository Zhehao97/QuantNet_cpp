//
//  main.cpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/26.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Exercise 2: Numeric Array (generic inheritance)


#include "Array.hpp"
#include "NumericArray.hpp"
#include "Point.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    namespace CTN = ZhehaoLi::Containers;
    namespace CAD = ZhehaoLi::CAD;
    
    CTN::NumericArray<double> dblArray_1;                                                               // Test default constructor
    CTN::NumericArray<double> dblArray_2(10);                                                           // Test constructor with values
    
    for (int i = 0; i < dblArray_1.Size(); i++) {
        dblArray_1.SetElement(1.23 + i, i);
    }
    
    for (int i = 0; i < dblArray_2.Size(); i++) {
        dblArray_2.GetElement(i) = 9.87 - i;
    }
    
    CTN::NumericArray<double> dblArray_3(dblArray_2);                                                   // Test copy constructor
    
    CTN::NumericArray<double> dblArray_4 = dblArray_1 * 3;                                              // Test assginment and multipication operator
    
    for (int i = 0; i < dblArray_4.Size(); i++) {
        std::cout << dblArray_4.GetElement(i) << std::endl;
    }
    
    CTN::NumericArray<double> dblArray_5 = dblArray_2 + dblArray_3;                                     // Test addition operator
    
    std::cout << "Dot product of double vector: " << dblArray_5.DotProduct(dblArray_3) << std::endl;    // Test Dot Product
    
    return 0;
}
