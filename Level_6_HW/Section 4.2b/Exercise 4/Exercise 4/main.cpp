//
//  main.cpp
//  Exercise 4
//
//  Created by Zhehao Li on 2020/3/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Exercise 4: Stack Class (composition)


#include "Stack.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    namespace CTN = ZhehaoLi::Containers;
    
    CTN::Stack<double> dblStack;            // Initialize with default constructor (default size = 6)
    
    for (int i = 0; i < 6; i++) {
        dblStack.Push(i + 0.6);
    }
    
    for (int i = 0; i < 7; i++) {
        std::cout << dblStack.Pop() << std::endl;
    }
    
    return 0;
}

/*
 Using another class as data member is called composition. In this case the Stack class uses internally an Array class.
 Forwarding functionality to another class is called delegation. Here the Stack class delegates the storage of elements to the Array class.
 */
