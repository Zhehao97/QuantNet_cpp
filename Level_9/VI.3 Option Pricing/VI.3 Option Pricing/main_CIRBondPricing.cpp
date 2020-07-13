//
//  main_CIRBondPricing.cpp
//  VI.3 Option Pricing
//
//  Created by Zhehao Li on 2020/4/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Testing the exact solution of bond pricing with CIR model

#include "CIR.hpp"
#include <vector>
#include <iostream>
using namespace std;

/* Utility functions */
void print(const vector<double> & vec){
    cout << endl;
    for (std::size_t i = 0; i < vec.size(); ++i){
        cout << vec[i] << ", ";
    }
    cout << endl;
}

void print(const vector< vector<double> > & matrix){
    cout << endl;
    for (std::size_t i = 0; i < matrix.size(); ++i){
        print(matrix[i]);
    }
    cout << endl;
}


int main(int argc, const char * argv[]) {
    
    using namespace AffineModel;
    
    // 0. Create a function pointer
    double (*affineModel) (double x, double t, paraCIR);
    affineModel = priceCIR;
    
    
    // 1. Price bond with single rate
    paraCIR mypara;
    mypara.theta = 0.0025;
    mypara.kappa = 0.05;
    mypara.theta = sqrt(0.01);
    mypara.T = 2.5;

    double r = 0.49;
    double t = 0.0;
    double d = priceCIR(r, t, mypara);
    cout << "Bond price: " << d << endl;
    

    // 2. An array of different interest rates
    long NR = 6;
    double rMin  = 0.0;
    double rMax  = 1.0;
    double rStep = (rMax - rMin)/NR;
    
    vector<double> xarr(NR);
    xarr[0] = rMin;
    xarr[xarr.size()-1] = rMax;
    
    for (std::size_t n = 1; n < xarr.size()-1; ++n){
        xarr[n] = xarr[n-1] + rStep;
    }

    vector<double> bondArray = priceCIR(xarr, t, mypara, affineModel);
    print(bondArray);

    
    // 3. An matrix of diff rates and diff time
    long NT = 5;
    double tStep = (mypara.T - t) / NT;
    
    vector<double> tarr(NT);
    tarr[0] = t;
    tarr[tarr.size()-1] = mypara.T;
    
    for (std::size_t n = 1; n < tarr.size()-1; ++n){
        tarr[n] = tarr[n-1] + tStep;
    }

    vector< vector<double> > result = priceCIR(xarr, tarr, mypara, affineModel);
    print(result);
    
    
    return 0;
}
