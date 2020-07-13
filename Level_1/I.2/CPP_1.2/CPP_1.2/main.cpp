// TestDataTypes
//
//  main.cpp
//  CPP_1.2
//
//  Created by Zhehao Li on 2020/2/8.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include <iostream>
#include <limits.h>      // Least and greatest representation of integer types
#include <float.h>       // Least and greatest representation of floating point types
using namespace std;

int main(int argc, const char * argv[]) {
    
    // Create some variables and values
    int i = 42;
    long index = 0L;
    
    double d1 = 2564.45677;
    double d2 = 3.1415 * d1;
    
    cout << "Values: " << i << ", " << index << ", " << d2 << ", " << d2*i << endl;

    // Some limits of basic data types
    cout << "int characteristics: " << sizeof(int) << ", " << INT_MIN << ", " << INT_MAX << endl;
    cout << "long characteristics: " << sizeof(long) << ", " << LONG_MIN << ", " << LONG_MAX << endl;

    cout << "double characteristics: " << sizeof(double) << ", " << DBL_MIN << ", " << DBL_MAX << endl;
    cout << "Long double characteristics: " << sizeof(double) << ", " << LDBL_MIN << ", " << LDBL_MAX << endl;
    cout << "float characteristics: " << sizeof(float) << ", " << FLT_MIN << ", " << FLT_MAX << endl;

    // What happens here? Put a big number in too small a space..
    float f = FLT_MAX;
    cout << f << endl;
    
    return 0;
}
