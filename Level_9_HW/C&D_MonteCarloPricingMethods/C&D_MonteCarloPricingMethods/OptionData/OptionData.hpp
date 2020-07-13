//
//  OptionData.hpp
//  VI.4 Monte Carlo Simulation
//
//  Created by Zhehao Li on 2020/5/4.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The declaration of struct OptionData

#ifndef OptionData_hpp
#define OptionData_hpp

#include <algorithm>
#include <cmath>

struct OptionData {
    // Basic data
    double K;           // strike pricee
    double T;           // maturity time
    double r;           // risk-free rate
    double sigma;       // volatitliy
    
    // Extra data
    double H;           // down and out barrier
    double D;           // dividend
    double betaCEV;     // r factor in CEV model
    double scale;       // scale factor ini CEV model
    
    int type;           // call == 1, put == -1
    
    double myPayoff(double S){
        if (type == 1) {
            return std::max(S - K, 0.0);        // call option
        }
        else{
            return std::max(K - S, 0.0);        // put option
        }
    }
    
    // Stochastic Derivative Equations
    // dX = mu(t,X)dt + sigma(t,X)dW
    double drift(double t, double S){
        return r * S;                       // mu_t
    }

    double diffusion(double t, double S){
        double betaCEV = 1.0;
        return sigma * pow(S, betaCEV);     // sigma_t
    }

    double diffusionDerivative(double t, double S){
        double betaCEV = 1.0;
        return 0.5 * sigma * (betaCEV) * pow(S, 2.0 * betaCEV - 1.0);
    }
};

#endif /* OptionData_hpp */
