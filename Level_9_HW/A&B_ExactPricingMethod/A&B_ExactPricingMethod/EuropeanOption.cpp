//
//  EuropeanOption.cpp
//  VI.3 Option Pricing
//
//  Created by Zhehao Li on 2020/4/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "EuropeanOption.hpp"
#include <boost/math/distributions/normal.hpp>


/* Private Memeber Functions */
// Call price
double EuropeanOption::CallPrice(double S) const{                   // S is the price of underlying assets
    double tmp = sig * sqrt(T);
    double d1 = ( log(S / K) + (b + (sig * sig) * 0.5 ) * T ) / tmp;
    double d2 = d1 - tmp;

    boost::math::normal_distribution<double> stdNormal(0.0, 1.0);   // Create a normal dstn object
    
    return ( S * exp((b - r) * T) * cdf(stdNormal, d1) ) - ( K * exp(- r * T) * cdf(stdNormal, d2) );
}

// Put price
double EuropeanOption::PutPrice(double S) const{
    double tmp = sig * sqrt(T);
    double d1 = ( log(S / K) + (b + (sig * sig) * 0.5 ) * T ) / tmp;
    double d2 = d1 - tmp;
    
    boost::math::normal_distribution<double> stdNormal(0.0, 1.0);   // Create a normal dstn object

    return ( K * exp(- r * T) * cdf(stdNormal, -d2) ) - ( S * exp((b - r) * T) * cdf(stdNormal, -d1) );
}

// Call delta
double EuropeanOption::CallDelta(double S) const{
    double tmp = sig * sqrt(T);
    double d1 = ( log(S / K) + (b + (sig * sig) * 0.5 ) * T ) / tmp;

    boost::math::normal_distribution<double> stdNormal(0.0, 1.0);   // Create a normal dstn object
    
    return exp((b - r) * T) * cdf(stdNormal, d1);
}

// Put delta
double EuropeanOption::PutDelta(double S) const{
    double tmp = sig * sqrt(T);
    double d1 = ( log(S / K) + (b + (sig * sig) * 0.5 ) * T ) / tmp;
    
    boost::math::normal_distribution<double> stdNormal(0.0, 1.0);   // Create a normal dstn object

    return exp((b - r) * T) * ( cdf(stdNormal, d1) - 1.0 );
}

// Gamma
double EuropeanOption::CallPutGamma(double S) const{
    double tmp = S * sig * sqrt(T);
    double d1 = ( log(S / K) + (b + (sig * sig) * 0.5 ) * T ) / tmp;
    
    boost::math::normal_distribution<double> stdNormal(0.0, 1.0);
    
    return exp((b - r) * T) * pdf(stdNormal, d1) / tmp;
}



/* Public Memeber Functions */
// Default constructor
EuropeanOption::EuropeanOption(): K(110.0), T(0.5), r(0.05), sig(0.2), b(0.05) {
    //
}

// Copy constructor
EuropeanOption::EuropeanOption(const EuropeanOption & option2) : K(option2.K), T(option2.T), r(option2.r), b(option2.b), sig(option2.sig) {
    //
}



// Destructor
EuropeanOption::~EuropeanOption() {}

// Assignment Operators
EuropeanOption & EuropeanOption::operator = (const EuropeanOption & option2) {
    if (this == &option2) {
        return *this;
    }
    else{
        Option::operator=(option2);
        K   = option2.K;
        T   = option2.T;
        r   = option2.r;
        b   = option2.b;
        sig = option2.sig;
        
        return *this;
    }
}

// Accessing functions
// Get the price of sensitvit of option
double EuropeanOption::getValue(optionOutput output, double S) const{
    
    switch (output) {
        case value:
            return Value(S);
        case delta:
            return Delta(S);
        case gama:
            return Gamma(S);
        default:
            return 0;
    }
}

// Compute the price of option
double EuropeanOption::Value(double S) const{
    if (optType == "C") {
        return CallPrice(S);
    }
    else{
        return PutPrice(S);
    }
}

// Compute the delta of option
double EuropeanOption::Delta(double S) const{
    if (optType == "C") {
        return CallDelta(S);
    }
    else{
        return PutDelta(S);
    }
}

// Compute the gamma of option
double EuropeanOption::Gamma(double S) const{
    return CallPutGamma(S);
}

// Put-Call Parity
double EuropeanOption::PutCallParity(double S){
    
    if (optType == "C") {
        double P = CallPrice(S) + K * exp(- r * T) - S;
        return P;
    }
    else{
        double C = PutPrice(S) + S - K * exp(- r * T);
        return C;
    }
}

// Check if Put-Call Party holds
bool EuropeanOption::PutCallParity(double CP, double S){

    double P = PutCallParity(S);
    
    if (fabs(P - CP) < 1e-4) {
        return true;
    }
    else{
        return false;
    }
}


// Modifier functions
// Change the type of option
void EuropeanOption::toggle(){
    
    if (optType == "C") {
        optType = "P";
    }
    else{
        optType = "C";
    }
}

void EuropeanOption::setValue(double val, optionInput input){
    
    switch (input) {
        case strike:
            K = val;
            break;
        case maturity:
            T = val;
            break;
        case rate:
            r = val;
            break;
        case cost:
            b = val;
            break;
        case volatility:
            sig = val;
            break;
        default:
            break;
    }
}
