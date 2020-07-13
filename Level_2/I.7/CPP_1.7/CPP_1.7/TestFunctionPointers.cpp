//
//  TestFunctionPointers.cpp
//  CPP_1.7
//
//  Created by Zhehao Li on 2020/2/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  TestFunctionPointers.cpp
//
//  Sample code to show the use of function pointer syntax to promote reusability and flexibility.

#include "TestFunctionPointers.hpp"
#include <math.h>
#include <iostream>
using namespace std;

double LeonardoPisa(double x){
    // x = F(x), this is a contraction
    // Solve x^3 + 2 x^2 + 10x = 20 by rewriting in the form x = f(x)
    return 20.0 / (x * x + 2.0 * x + 10.0);
}

double SquareRoot(double x){
    // Square root of 2
    return 0.5 * (x + 2.0/x);
}

// doublee (*f) (double x) is a function pointer
double FPSolver(double (*f) (double x), double x0, double TOL){
    // General 1 solver for a contraction mapping f in form x = f(x)
    
    double xnp1;
    double diff = 10.0 * TOL;
    
    while (diff >= TOL) {
        xnp1 = (*f)(x0);          // call a function
        diff = fabs(xnp1 - x0);
        x0 = xnp1;
    }
    
    return x0;
}

