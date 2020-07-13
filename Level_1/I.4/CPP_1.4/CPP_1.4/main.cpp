//
//  main.cpp
//  CPP_1.4
//
//  Created by Zhehao Li on 2020/2/9.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  TestLoops.cpp

#include <iostream>
#include <math.h>
using namespace std;

double f(double x){
    return exp(-x);
}


double ftp_I(double x0, double tol, long maxiter){
    
    double xcurrent;
    long counter = 0;
    
L1:
    xcurrent = f(x0);
    
    if (counter >= maxiter){
        cout << "Max iterations exceed, method not converge \n";
        return xcurrent;
    }
    
    if (fabs(xcurrent - x0) >= tol) {
        x0 = xcurrent;
        counter++;
        goto L1;
    }
    
    cout << "Method I has converged in" << counter << "iterations\n";
    
    return xcurrent;
}


double ftp_II(double x0, double tol, long maxiter){
    
    double xcurrent = 0;
    long counter;
    
    for (counter = 0; counter < maxiter; ++counter) {
        xcurrent = f(x0);
        
        if (fabs(xcurrent - x0) < tol) {
            break;
        }
        
        x0 = xcurrent;
    }
    
    // Broke out
    
    if (counter < maxiter) {
        cout << "Method II has converged in" << counter << "iterations\n";
    }
    else{
        cout << "Method II has NOT converged in" << counter << "iterations\n";
    }
    
    return xcurrent;
}


double ftp_III(double x0, double tol, long maxiter){
    
    double xcurrent;
    long counter = 0;
    
    while (true) {
        xcurrent = f(x0); counter++;
        
        if (counter > maxiter) {
            cout << "Method III has NOT converged in" << counter << "iterations\n";
            break;
        }
        
        if (fabs(xcurrent - x0) < tol) {
            cout << "Method III has converged in " << counter << "iterations\n";
            break;
        }
        
        x0 = xcurrent;
        
    }
    
    return xcurrent;
}



int main(int argc, const char * argv[]) {
    
    // Input parameters
    double x_init = 0.5;
    long max_iter = 10000;
    double tol = 1.0e-5;
    
    // The implementations of the solvers
    cout << "Fixed point (method I) is: " << ftp_I(x_init, tol, max_iter) << endl;
    cout << "Fixed point (method II) is: " << ftp_II(x_init, tol, max_iter) << endl;
    cout << "Fixed point (method III) is: " << ftp_III(x_init, tol, max_iter) << endl;
    
//    // Testing scope of a variable
//    {
//        int j = 10;
//        cout << "j: " << j << endl;
//    }
//
//    // j does not exist anymore
//    cout << "j: " << j << endl;
//
    return 0;
}
