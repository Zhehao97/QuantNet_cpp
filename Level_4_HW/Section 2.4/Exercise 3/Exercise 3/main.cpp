//
//  main.cpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/3/10.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Constructors as conversion operator

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    Point p(1.0, 1.0);
    /*
     Point constructor with the single double argument is implicitly used to
     convert the number in the if statement to a Point object.
    */
    if (p == 1.0){
        cout << "Equal!" << endl;
    }
    else{
        cout << "Not equal" << endl;
    }
    
    return 0;
}
