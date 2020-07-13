//
//  main.cpp
//  3 - Union
//
//  Created by Zhehao Li on 2020/4/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test Union

#include <iostream>
#include <string>
using namespace std;

union NumericDataType{                                  // union with three members
    int         i;
    float       f;
    double      d;
};

int main(int argc, const char * argv[]) {
    NumericDataType Values;
    
    Values.i = 10;
    cout << "Integer: " << Values.i << endl;            // Prints 10

    Values.f =1.098f;
    cout << "Float: " << Values.f << endl;              // Prints 1.098

    Values.d = 3.1415;
    cout << "Correct double: " << Values.d << endl;

    // The variables i and f will not have correct values
    // because the 'd' field is active.
    cout << "Incorrect float: " << Values.f << endl;
    cout << "Incorrect integer: " << Values.i << endl;

    NumericDataType Values2 = { 2 };
//    NumericDataType Values3 = { 2.71 };

    return 0;
}

/*  {} -> initializer for struct or union
    for union, there should be single value in {}
    for struct, there may be mutiple value in {}
 */
