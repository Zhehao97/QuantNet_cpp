//
//  main.cpp
//  F_FiniteDifferenceMethods
//
//  Created by Zhehao Li on 2020/5/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  F. Finite Difference Methods (Introduction)

#include "FDMDirector.hpp"

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Black Scholes namespace
namespace BS{

    double sig = 0.3;                   // Volaitility
    double K = 65.0;                    // Strike
    double r = 0.08;                    // Risk-free rate
    double D = 0.0;                     // Dividend
    double Tmax = 0.25;                 // Max Time
    double Smax = 3.0 * K;              // Max price
    int NS = static_cast<int>(Smax);    // Length of price space
    int NT = 10000 - 1;                 // Length of time space

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

    // Boundary condition at the bottom of matrix, S = 0
    double myBCL (double t, string optType){
        
        if (optType == "C") {
            return 0.0;                         // Call
        }
        else{
            return K * exp(-r * t);             // Put
        }
    }

    // Boundary condition at the top of matrix, S = Smax
    double myBCR (double t, string optType){
            
        if (optType == "C") {
            return (Smax - K) * exp(-r * t);    // Call
        }
        else{
            return 0.0;                         // Put
        }
    }

    // Payoff at t = T
    double myIC (double x, string optType){
    
        if (optType == "C") {
            return fmax(x - K, 0.0);            // Call
        }
        else{
            return fmax(K - x, 0.0);            // Put
        }

    }
}


int main(int argc, const char * argv[]) {

    // 0. Assignment of functions
    ParabolicIBVP::sigma = BS::mySigma;
    ParabolicIBVP::mu    = BS::myMu;
    ParabolicIBVP::bb    = BS::myB;
    ParabolicIBVP::ff    = BS::myF;
    ParabolicIBVP::BCL   = BS::myBCL;
    ParabolicIBVP::BCR   = BS::myBCR;
    ParabolicIBVP::IC    = BS::myIC;
    
    
    //  Test Examples:
    //    Batch 1: T = 0.25, K = 65, sig = 0.30, r = 0.08, S = 60 (C = 2.13337, P = 5.84628)

    // -------------------------------------
    // ------------- Batch 1 ---------------
    // -------------------------------------
    // 1. Initialize parameters
    BS::sig = 0.4;                          // Volatility
    BS::K = 120.0;                          // Strike
    BS::r = 0.04;                           // Risk-free rate
    BS::D = 0.0;                            // Dividend
    BS::Tmax = 1.00;                        // Max time
    BS::Smax = 3.0 * BS::K;                 // Max price
    BS::NS = static_cast<int>(BS::Smax);    // Length of price space
    BS::NT = 100000 - 1;                     // Length of time space
    
    // 2.0 Call option
    double S0 = 100.0;                       // Initial Price
    string optionType = "C";                // Option Type

    // 2.1 Implement the Finite Different Methods (Explicit Euler)
    FDMDirector fdir(BS::Smax, BS::Tmax, BS::NS, BS::NT, optionType);
    fdir.doIt();

    // 2.2 Get the option price vector at t = 0
    std::vector<double> currArray = fdir.current();
    
    // 2.3 Output the result at t = 0
    cout << "Stock Price | Call Price  \n";
//    for (int i = 0; i < currArray.size(); i++) {
//        cout << fdir.sarr[i] << "   |   " << currArray[i] << endl;
//    }
    cout << "Batch 1: " << S0 << " |  " << currArray[int(S0)] << endl;

    
    // 3.0 Put option
    optionType = "P";
    
    // 3.1 Implement the Finite Different Methods (Explicit Euler)
    fdir = FDMDirector(BS::Smax, BS::Tmax, BS::NS, BS::NT, optionType);
    fdir.doIt();

    // 3.2 Get the option price vector at t = 0
    currArray = fdir.current();
    
    // 3.3 Output the result at t = 0
    cout << "Stock Price | Put Price  \n";
//    for (int i = 0; i < currArray.size(); i++) {
//        cout << fdir.sarr[i] << "   |   " << currArray[i] << endl;
//    }
    cout << "Batch 1: " << S0 << " |  " << currArray[int(S0)] << "\n\n";
    
    

    //    Batch 2: T = 1.0, K = 100, sig = 0.2, r = 0.0, S = 100 (C = 7.96557, P = 7.96557)
    // -------------------------------------
    // ------------- Batch 2 ---------------
    // -------------------------------------
    // 1. Initialize parameters
    BS::sig = 0.2;                          // Volatility
    BS::K = 100.0;                          // Strike
    BS::r = 0.00;                           // Risk-free rate
    BS::D = 0.0;                            // Dividend
    BS::Tmax = 1.0;                         // Max time
    BS::Smax = 3.0 * BS::K;                 // Max price
    BS::NS = static_cast<int>(BS::Smax);    // Length of price space
    BS::NT = 10000 - 1;                     // Length of time space
    
    // 2.0 Call option
    S0 = 100.0;                             // Initial Price
    optionType = "C";                       // Option Type

    // 2.1 Implement the Finite Different Methods (Explicit Euler)
    fdir = FDMDirector(BS::Smax, BS::Tmax, BS::NS, BS::NT, optionType);
    fdir.doIt();

    // 2.2 Get the option price vector at t = 0
    currArray = fdir.current();
    
    // 2.3 Output the result at t = 0
    cout << "Stock Price | Call Price  \n";
//    for (int i = 0; i < currArray.size(); i++) {
//        cout << fdir.sarr[i] << "   |   " << currArray[i] << endl;
//    }
    cout << "Batch 2: " << S0 << " |  " << currArray[int(S0)] << endl;
    
    
    // 3.0 Put option
    optionType = "P";
    
    // 3.1 Implement the Finite Different Methods (Explicit Euler)
    fdir = FDMDirector(BS::Smax, BS::Tmax, BS::NS, BS::NT, optionType);
    fdir.doIt();

    // 3.2 Get the option price vector at t = 0
    currArray = fdir.current();
    
    // 3.3 Output the result at t = 0
    cout << "Stock Price | Put Price  \n";
//    for (int i = 0; i < currArray.size(); i++) {
//        cout << fdir.sarr[i] << "   |   " << currArray[i] << endl;
//    }
    cout << "Batch 2: " << S0 << " |  " << currArray[int(S0)] << "\n\n";
    
    
    
    //    Batch 3: T = 1.0, K = 10, sig = 0.50, r = 0.12, S = 5 (C = 0.204058, P = 4.07326)
    // -------------------------------------
    // ------------- Batch 3 ---------------
    // -------------------------------------
    
    // 1. Initialize parameters
    BS::sig = 0.50;                         // Volatility
    BS::K = 10.0;                           // Strike
    BS::r = 0.12;                           // Risk-free rate
    BS::D = 0.0;                            // Dividend
    BS::Tmax = 1.0;                         // Max time
    BS::Smax = 3.0 * BS::K;                 // Max price
    BS::NS = static_cast<int>(BS::Smax);    // Length of price space
    BS::NT = 10000 - 1;                     // Length of time space
    
    // 2.0 Call option
    S0 = 5.0;                               // Initial Price
    optionType = "C";                       // Option Type

    // 2.1 Implement the Finite Different Methods (Explicit Euler)
    fdir = FDMDirector(BS::Smax, BS::Tmax, BS::NS, BS::NT, optionType);
    fdir.doIt();

    // 2.2 Get the option price vector at t = 0
    currArray = fdir.current();
    
    // 2.3 Output the result at t = 0
    cout << "Stock Price | Call Price  \n";
//    for (int i = 0; i < currArray.size(); i++) {
//        cout << fdir.sarr[i] << "   |   " << currArray[i] << endl;
//    }
    cout << "Batch 3: " << S0 << " |  " << currArray[int(S0)] << endl;
    
    
    // 3.0 Put option
    optionType = "P";
    
    // 3.1 Implement the Finite Different Methods (Explicit Euler)
    fdir = FDMDirector(BS::Smax, BS::Tmax, BS::NS, BS::NT, optionType);
    fdir.doIt();

    // 3.2 Get the option price vector at t = 0
    currArray = fdir.current();
    
    // 3.3 Output the result at t = 0
    cout << "Stock Price | Put Price  \n";
//    for (int i = 0; i < currArray.size(); i++) {
//        cout << fdir.sarr[i] << "   |   " << currArray[i] << endl;
//    }
    cout << "Batch 3: " << S0 << " |  " << currArray[int(S0)] << "\n\n";
    
    
    
    //    Batch 4: T = 30.0, K = 100.0, sig = 0.30, r = 0.08, S = 100.0 (C = 92.17570, P = 1.24750)
    // -------------------------------------
    // ------------- Batch 4 ---------------
    // -------------------------------------
    
    // 1. Initialize parameters
    BS::sig = 0.30;                         // Volatility
    BS::K = 100.0;                          // Strike
    BS::r = 0.08;                           // Risk-free rate
    BS::D = 0.0;                            // Dividend
    BS::Tmax = 30.0;                        // Max time
    BS::Smax = 6.0 * BS::K;                 // Max price
    BS::NS = static_cast<int>(BS::Smax);    // Length of price space
    BS::NT = 1000000;                       // Length of time space
    
    // 2.0 Call option
    S0 = 100.0;                             // Initial Price
    optionType = "C";                       // Option Type

    // 2.1 Implement the Finite Different Methods (Explicit Euler)
    fdir = FDMDirector(BS::Smax, BS::Tmax, BS::NS, BS::NT, optionType);
    fdir.doIt();

    // 2.2 Get the option price vector at t = 0
    currArray = fdir.current();
    
    // 2.3 Output the result at t = 0
    cout << "Stock Price | Call Price  \n";
//    for (int i = 0; i < currArray.size(); i++) {
//        cout << fdir.sarr[i] << "   |   " << currArray[i] << endl;
//    }
    cout << "Batch 4: " << S0 << " |  " << currArray[int(S0)] << endl;
    
    
    // 3.0 Put option
    optionType = "P";
    
    // 3.1 Implement the Finite Different Methods (Explicit Euler)
    fdir = FDMDirector(BS::Smax, BS::Tmax, BS::NS, BS::NT, optionType);
    fdir.doIt();

    // 3.2 Get the option price vector at t = 0
    currArray = fdir.current();
    
    // 3.3 Output the result at t = 0
    cout << "Stock Price | Put Price  \n";
//    for (int i = 0; i < currArray.size(); i++) {
//        cout << fdir.sarr[i] << "   |   " << currArray[i] << endl;
//    }
    cout << "Batch 4: " << S0 << " |  " << currArray[int(S0)] << "\n\n";

    return 0;
}
