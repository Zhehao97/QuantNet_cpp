//
//  main.cpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/3/10.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test the Array class

#include "Point.hpp"
#include "Array.hpp"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    // Create some arrays
    Array A1;                                   // Test Default constructor
    Array A2(6);                                // Test constructor with argument
    
    // Modifying the element of array
    for (int i = 0; i < A1.Size(); i++) {       // Test Size() function
        Point P1(1.0 + i, 2.0 + i);
        A1.SetElement(P1, i);                   // Test SetElement() function
        cout << A1.GetElement(i) << endl;        // Test GetElment() function
    }
    
    for (int i = 0; i < A2.Size(); i++) {
        Point P2(-1.0 - i, -2.0 - i);
        A2[i] = P2;                             // Test = and [] operator
        cout << A2[i] << endl;
    }
    
    Array A3(A2);                               // Test Copy consturctor
    for (int i = 0; i < A3.Size(); i++) {
        cout << A3[i] << endl;                  // Test const [] operator
    }
    
    
    return 0;
}
