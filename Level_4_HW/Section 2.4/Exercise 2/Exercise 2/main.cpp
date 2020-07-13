//
//  main.cpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/10.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Add Ostream << Operator

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    // Testing operators of Point class
    Point P1;
    Point P2(8, 10);
    Point P3(16, 9);
    
    cout << P1 << endl;
    P1 = P2;
    cout << P1 << endl;
    
    
    // Testing operators of Line class
    Line L1;
    Line L2(P2, P3);
    
    cout << L1 << endl;
    L1 = L2;
    cout << L1 << endl;
    
    
    // Testing operators of Circle class
    Circle C1;
    Circle C2(P2, 3.0);
    
    cout << C1 << endl;
    C1 = C2;
    cout << C1 << endl;
    
    return 0;
}
