//
//  main.cpp
//  CPP_1.5
//
//  Created by Zhehao Li on 2020/2/10.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Fibonacci Test

#include <iostream>
#include <algorithm>
using namespace std;


long Fibonacci(long n){
// Recursive function
    
    if (n == 0) {
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else{
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}


int main(int argc, const char * argv[]) {
    // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765 . . .

//    int N = 10; // How many Fibonacci numbers to compute
//
//    for (int n = 0; n < N; ++n)
//    {
//        cout << Fibonacci(n) << ",";
//    }
//
    
//    double d1 = 1.004;
//    double d2 = 1.00004e+3;
//    float f1, f2;
//    int i1, i2;
//    f1 = d1;
//    f2 = d2;
//    i1 = d1;
//    i2 = d2;
//    cout << "d1: " << d1 << endl;
//    cout << "d2: " << d2 << endl;
//    printf("Assigning float to 1.004 is %f\n", f1);
//    printf("Assigning float to 1.00004e+3 is %f\n", f2);
//    printf("Assigning int to 1.004 is %d\n", i1);
//    printf("Assigning int to 1.00004e+3 is %d\n", i2);
    
//    int i;        // Left bit (sign bit) equals 1
//    i = -3;
//    printf("i = %d \n", i);
//    i = i >> 1;
//    printf("i >> 1 evaluates to: %d \n" , i);
//
//    if (i < 0){
//        printf("Negative, a 1 was inserted left\n");
//        }
//    else {
//        printf("Positive, a 0 was inserted left\n");
//        }
    
    
    int i, j; i=j=10;
        
    cout << i << j << endl;
    
    return 0;
}
