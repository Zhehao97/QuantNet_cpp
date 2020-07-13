//
//  main.cpp
//  CPP_1.3
//
//  Created by Zhehao Li on 2020/2/9.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    double d1 = 3.1415; double d2 = - 2.0; double d3 = 2.71;
    double d4;
    
    d4 = d1 + d2 / d3; cout << d4 << endl;
    d4 = (d1 + d2) / d3; cout << d4 << endl;
    
    // Combine the arithmetic with assignment operator
    
    d4 += d1; // d4 = d4 + d1
    d3 *= d2; // d3 = d3 * d2
    
    // Prefix/Postfix
    int i = 3;
    int j = ++i; cout << j << "," << i << endl;
    
    i = 3;
    int k = i++; cout << k << "," << i << endl;
    
    // Comma Operator
    int y = 5;
    int c;
    
    c = y += 4, y + 5;
    
    cout << "value of c: " << c << endl; // 9
    
    y = 5; // Reset
    int c2 = (y += 4, y + 5);
    cout << "value of c2: " << c2 << endl; // 14
    
    // Replacing , by ;
    y = 5; // Reset
    int d = y += 4; y + 5;

    cout << "Value of d: " << d << endl; // ??
    
    return 0;
}
