//
//  main.cpp
//  CPP_1.7
//
//  Created by Zhehao Li on 2020/2/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  TestArrays.cpp
//  Some mathematical operations on fixed-sixed arrays and matrices.
//


#include <iostream>
#include <math.h>
#include "TestFunctionPointers.hpp"
using namespace std;

// Preprocessor directives
# define NX 4
# define NY 3

// Handy shorthand notation
typedef double Vector[NX];                 // fixed dimensions vector
typedef double NumericMatrix[NX][NY];      // fixed dimensions matrix

double innerProduct(Vector v1, Vector v2){
    // Call by value! copies of v1 and v2 created in code body
    
    double result = v1[0] * v2[0];
    
    for (int j = 1; j < NX; ++j) {
        result += v1[j] * v2[j];
    }
    return result;
}

void print(NumericMatrix m){
    // Print elements of a matrix
    
    for (int i = 0; i < NX; ++i) {
        cout << endl << "(";
        for (int j = 0; j < NY; ++j) {
            cout << m[i][j] << ",";
        }
        cout << ")";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    //* Test Array *//
    Vector v1, v2;
    for (int i = 0; i < NX; ++i) {
        v1[i] = i;
        v2[i] = NX - i;
    }
    
    cout << "Inner product: " << innerProduct(v1, v2) << endl;
    
    NumericMatrix m1, m2, result;
    for (int i = 0; i < NX; ++i) {
        for (int j = 0; j < NY; ++j) {
            m1[i][j] = i; m2[i][j] = j;
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    
    print(m1); print(m2); print(result);
    
    //* Test Function Pointers *//
    
    // 'cos' is a system delivered function
    cout << "Cosine fixed point solver: " << FPSolver(cos, 0.12, 1.0e-2) << endl;
    
    // square roots
    double x0 = 100.0;
    double tol = 1.0e-10;
    cout << "Root of Square equation: " << cout.precision(16) << FPSolver(SquareRoot, x0, tol) << endl;
    
    
    // Extra level of indirection
    double (*myFunc)(double x);   // function pointer
    myFunc = SquareRoot;
    
    cout << "Square root, again: " << cout.precision(16) << FPSolver(myFunc, x0, tol) << endl;
    
    
    // leonardo-pisa
    x0 = 31.2;
    tol = 1.0e-3;
    cout << "Root of Cubic equation: " << cout.precision(16) << FPSolver(LeonardoPisa, x0, tol) << endl;

    
    // 'sin', C library function
    myFunc = ::sin;
    cout << "Sine fixed point solver: " << FPSolver(myFunc, 0.12, 1.0e-2) << endl;
    
    return 0;
}
