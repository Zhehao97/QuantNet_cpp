//
//  main.cpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/15.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Testing 1 factor BS model with FDM


#include "ExcelDriverLite.hpp"
#include "FDMDirector.hpp"

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Black Scholes
namespace BS{

    double sig = 0.3;
    double K = 65.0;
    double Tmax = 0.25;
    double r = 0.08;
    double D = 0.0;         // aka q, dividend

    double mySigma (double x, double t){

        double sigmaS = sig * sig;
        
        return 0.5 * sigmaS * x * x;
    }

    double myMu (double x, double t){
        
        return (r - D) * x;
    }

    double myB (double x, double t){
    
        return  -r;
    }

    double myF (double x, double t){
        
        return 0.0;
    }

    double myBCL (double t){
        
        // Put
        return K * exp(-r * t);
    }

    double myBCR (double t){
            
        // Put
        return 0.0; // P
    }

    double myIC (double x){     // Payoff
    
        // Put
        return fmax(K - x, 0.0);
    }
}


int main(int argc, const char * argv[]) {

    // Assignment of functions
    ParabolicIBVP::sigma = BS::mySigma;
    ParabolicIBVP::mu    = BS::myMu;
    ParabolicIBVP::bb    = BS::myB;
    ParabolicIBVP::ff    = BS::myF;
    ParabolicIBVP::BCL   = BS::myBCL;
    ParabolicIBVP::BCR   = BS::myBCR;
    ParabolicIBVP::IC    = BS::myIC;

    int NS = static_cast<int>(5 * BS::K);
    int NT = 10000-1;

    double Smax = 5 * BS::K;            // 5 times of the strike price
    
    cout << "Start FDM:\n";
    
    FDMDirector fdir(Smax, BS::Tmax, NS, NT);
    fdir.doIt();
    
    cout << "Finished\n";

    // Have you Excel installed (ExcelImports.cpp)
    printOneExcel(fdir.sarr, fdir.current(), string("Value"));
    

    return 0;
}
