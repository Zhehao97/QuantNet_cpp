//
//  main.cpp
//  CPP_1.6
//
//  Created by Zhehao Li on 2020/2/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
// TestPreprocessor.cpp
//
// Comparing the different ways to loop and make decisions in code. We
// take the example of solving a scalar nonlinear equation x = f(x) by the fixed point
// method (contraction mapping):
//
//        x(n+1) = f(x(n)), x(0) given.
//
//    We iterate until either fabs(x(n+1) - x(n)) < TOL or n >= MAXITER. The fixed point method
//  converges if fabs(df/dx) < 1. Variants are Brouwer and Banach fixed point theorems.
//
// In this version we examine x = exp(-x). Later you can generalise the code by defining f(x) using
// function pointers.
//
// In this case we use the preprocessor to define the variables TOL and MAXITER for illustrative purposes. In general we would not advise this approach.
//
// DJD

#include <iostream>
#include <math.h>
using namespace std;


double f(double x){
    return exp(-x);
}

// Preprocessor directives; effectively global variables
#define TOL 1.0e-5
#define MAXITER 1000

double ftp_I(double x_0){
    
    double x_current;
    long counter = 0;
    
L1: // solution using goto
    
    x_current = f(x_0);
    
    if (counter >= MAXITER) {
        cout << "Max iterations exceeded, method not coverging" << endl;
        return x_current;
    }
    if (fabs(x_current - x_0) >= TOL) {
        x_0 = x_current;
        counter++;
        goto L1;
    }
    cout << "Method I has converged in " << counter << " iterations" <<endl;
    return x_current;
}

int main(int argc, const char * argv[]) {
    
    double xInit = 0.5;
    double xResults = ftp_I(xInit);
    cout << "Fixed point (method I) is: " << xResults << endl;
    cout << MAXITER << endl;
    return 0;
}
