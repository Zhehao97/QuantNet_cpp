//
//  EuropeanOption.cpp
//  VI.3 Option Pricing
//
//  Created by Zhehao Li on 2020/4/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "EuropeanOption.hpp"
#include <boost/math/distributions/normal.hpp>
#include <iostream>
#include <cmath>

/* Private Memeber Functions */
double EuropeanOption::CallPrice(double U) const{                   // U is the price of underlying assets
    double tmp = sig * sqrt(T);
    double d1 = ( log(U / K) + (b + (sig * sig) * 0.5 ) * T ) / tmp;
    double d2 = d1 - tmp;

    boost::math::normal_distribution<double> stdNormal(0.0, 1.0);   // Create a normal dstn object
    
    return ( U * exp((b - r) * T) * cdf(stdNormal, d1) ) - ( K * exp(- r * T) * cdf(stdNormal, d2) );
}

double EuropeanOption::PutPrice(double U) const{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U / K) + (b + (sig * sig) * 0.5 ) * T ) / tmp;
    double d2 = d1 - tmp;
    
    boost::math::normal_distribution<double> stdNormal(0.0, 1.0);   // Create a normal dstn object

    return ( K * exp(- r * T) * cdf(stdNormal, -d2) ) - ( U * exp((b - r) * T) * cdf(stdNormal, -d1) );
}

double EuropeanOption::CallDelta(double U) const{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U / K) + (b + (sig * sig) * 0.5 ) * T ) / tmp;

    boost::math::normal_distribution<double> stdNormal(0.0, 1.0);   // Create a normal dstn object
    
    return exp((b - r) * T) * cdf(stdNormal, d1);
}

double EuropeanOption::PutDelta(double U) const{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U / K) + (b + (sig * sig) * 0.5 ) * T ) / tmp;
    
    boost::math::normal_distribution<double> stdNormal(0.0, 1.0);   // Create a normal dstn object

    return exp((b - r) * T) * ( cdf(stdNormal, d1) - 1.0 );
}


/* Public Memeber Functions */
// Default constructor
EuropeanOption::EuropeanOption() : r(0.05), sig(0.2), K(110.0), T(0.5), b(0.05), optType("C") {}

// Copy constructor
EuropeanOption::EuropeanOption(const EuropeanOption & option2) : r(option2.r), sig(option2.sig), K(option2.K), T(option2.T), b(option2.b), optType(option2.optType) {}

// Constructor with values
EuropeanOption::EuropeanOption(const std::string & optionType) : optType(optionType) {
    if (optType == "c"){
        optType = "C";
    }
}

// Destructor
EuropeanOption::~EuropeanOption() {}

// Assignment Operators
EuropeanOption & EuropeanOption::operator=(const EuropeanOption & option2) {
    if (this == &option2) {
        return *this;
    }
    else{
        r   = option2.r;
        sig = option2.sig;
        K   = option2.K;
        T   = option2.T;
        b   = option2.b;
        optType = option2.optType;
        
        return *this;
    }
}

// Accessing functions
double EuropeanOption::Price(double U) const{
    if (optType == "C") {
        std::cout << "Call Price..";
        return CallPrice(U);
    }
    else{
        std::cout << "Put Price..";
        return PutPrice(U);
    }
}

double EuropeanOption::Delta(double U) const{
    if (optType == "C") {
        std::cout << "Call Delta..";
        return CallDelta(U);
    }
    else{
        std::cout << "Put Delta..";
        return PutDelta(U);
    }
}

// Modifier functions
void EuropeanOption::toggle(){
    if (optType == "C") {
        optType = "P";
    }
    else{
        optType = "C";
    }
}
