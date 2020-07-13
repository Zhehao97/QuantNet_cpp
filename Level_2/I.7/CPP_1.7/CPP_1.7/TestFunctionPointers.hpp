//
//  TestFunctionPointers.hpp
//  CPP_1.7
//
//  Created by Zhehao Li on 2020/2/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//



#ifndef TestFunctionPointers_hpp
#define TestFunctionPointers_hpp

#include <stdio.h>

double LeonardoPisa(double x);
double SquareRoot(double x);
double FPSolver(double (*f) (double x), double x0, double TOL);

#endif /* TestFunctionPointers_hpp */
