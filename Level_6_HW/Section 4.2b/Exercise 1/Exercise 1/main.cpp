//
//  main.cpp
//  Exercise 1
//
//  Created by Zhehao Li on 2020/3/26.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Exercise1: Static Variable for Array Default Size

#include "Shape.hpp"
#include "Point.hpp"
#include "Array.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    namespace CTD = ZhehaoLi::Containers;
    namespace CAD = ZhehaoLi::CAD;
    
    CTD::Array<int> intArray1;
    CTD::Array<int> intArray2;
    CTD::Array<double> doubleArray;
    
    std::cout << intArray1.DefaultSize() << std::endl;
    std::cout << intArray2.DefaultSize() << std::endl;
    std::cout << doubleArray.DefaultSize() << std::endl;
    
    intArray1.DefaultSize(15);
    
    std::cout << intArray1.DefaultSize() << std::endl;
    std::cout << intArray2.DefaultSize() << std::endl;
    std::cout << doubleArray.DefaultSize() << std::endl;
    
    return 0;
}

/*
    Static variables are only shared between all template class with same type, e.g.
    static m_def_size, which are shared between all instances of Array<int>
*/
