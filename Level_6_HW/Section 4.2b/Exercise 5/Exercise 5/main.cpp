//
//  main.cpp
//  Exercise 5
//
//  Created by Zhehao Li on 2020/3/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Exercise 5: Layering Exceptions

#include "Stack.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    namespace CTN = ZhehaoLi::Containers;
    
    CTN::Stack<double> dblStack;            // Initialize with default constructor (default size = 6)
    
    for (int i = 0; i < 6; i++) {
        dblStack.Push(i + 0.6);
    }
    
    for (int i = 0; i < 8; i++) {
        std::cout << dblStack.Pop() << std::endl;
    }
    return 0;
}
