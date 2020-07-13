//
//  CIR.hpp
//  VI.3 Option Pricing
//
//  Created by Zhehao Li on 2020/4/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Declartion of Cox–Ingersoll–Ross model -- interest rate derivatives

#ifndef CIR_hpp
#define CIR_hpp

#include <vector>
#include <cmath>
#include <iostream>

namespace AffineModel{

// dr = kappa( theta - r )dt + sigma (r_t)^1/2 dW
struct paraCIR{
    double theta;                       // Long term level or rate
    double kappa;                       // The speed of adjustment to theta
    double sigma;                       // Volatility
    double T;                           // Maturity time
};

double priceCIR(double r, double t, paraCIR myPara){                       // CIR Model of a zero-coupon bond pricing

    double theta = myPara.theta;
    double kappa = myPara.kappa;
    double sigma = myPara.sigma;
    double T = myPara.T;
    double gamma = sqrt( pow(kappa, 2.0) + 2.0 * pow(sigma, 2.0) );
    
    double denominator = (gamma + kappa) * ( exp(gamma * (T - t)) - 1.0 ) + 2.0 * gamma;
    
    double B = 2.0 * ( exp(gamma * (T - t)) - 1 ) / denominator;

    double Afactor = 2.0 * gamma * exp( 0.5 * (gamma + kappa) * (T - t) ) / denominator;

    double A = pow(Afactor, 2.0 * kappa * theta / pow(sigma, 2.0));

    return A * exp(-B * r);
}


std::vector<double> priceCIR(const std::vector<double> & xarr, double t, paraCIR mypara,
                             double (*affineModel)(double x, double t, paraCIR mypar)          // Function pointer, so flexible
                             ){
    std::vector<double> result(xarr.size());

    for (std::size_t n = 0; n < result.size(); n++){
        result[n] = affineModel(xarr[n], t, mypara);
    }
    return result;
}

    
std::vector<std::vector<double>> priceCIR(const std::vector<double> & xarr,
                                          const std::vector<double> & tarr,
                                          paraCIR mypara,
                                          double (*affineModel)(double x, double t, paraCIR mypar)
                                          ){
//    vector<vector<double> > result(xarr.size(), tarr.size());
    
    std::vector< std::vector<double> > result( xarr.size() );
    
    for (std::size_t m = 0; m < xarr.size(); m++){
        result[m] = std::vector<double>( tarr.size() );
    }

    for (std::size_t n = 0; n < tarr.size(); n++){
        for (std::size_t i = 0; i < xarr.size(); ++i){
            result[i][n] = affineModel( xarr[i], tarr[n], mypara);
        }
    }
    return result;
}

} // end of namespace 'AffineModel'

#endif /* CIR_h */
