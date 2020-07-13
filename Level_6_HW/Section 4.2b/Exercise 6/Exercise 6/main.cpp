//
//  main.cpp
//  Exercise 6
//
//  Created by Zhehao Li on 2020/3/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Exercise 6: Value Template Arguments

#include "Stack.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    namespace CTN = ZhehaoLi::Containers;
    
    const int size = 8;
    
    CTN::Stack<double, size> dblStack;              // Size must be const object
    
    for (int i = 0; i < 8; i++) {
        dblStack.Push(i + 0.6);
    }
    
    CTN::Stack<double, size> dblStack_2 = dblStack;
    
    for (int i = 0; i < 8; i++) {
        std::cout << dblStack_2.Pop() << std::endl;
    }
    
    return 0;
}
