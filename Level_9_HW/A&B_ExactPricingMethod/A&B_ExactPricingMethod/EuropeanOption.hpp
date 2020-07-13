//
//  EuropeanOption.hpp
//  VI.3 Option Pricing
//
//  Created by Zhehao Li on 2020/4/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp

#include "Option.hpp"

// Class of European Option
class EuropeanOption: public Option{
    
private:
    // Kernel functions
    double CallPrice(double S) const;
    double PutPrice(double S) const;
    double CallDelta(double S) const;
    double PutDelta(double S) const;
    double CallPutGamma(double S) const;
    
public:
    // Member data
    double K;                   // strike price
    double T;                   // maturity
    double r;                   // risk-free interest rate
    double b;                   // carry of cost = r + u - d, u is storage cost, and d is dividend
    double sig;                 // volatility
    

    // Constructors
    EuropeanOption();                                           // Default call option
    EuropeanOption(const EuropeanOption & option2);             // Copy constructor

    
    // Destructors
    virtual ~EuropeanOption();
    
    // Assignment operator
    EuropeanOption & operator = (const EuropeanOption & option2);

    // Accessing functions
    double getValue(optionOutput output, double S) const;                  // Get the price or sensitvities of option
    double Value(double S) const;                               // Option price
    double Delta(double S) const;                               // Option delta
    double Gamma(double S) const;                               // Option gamma
    double PutCallParity(double S);                             // Price using put-call parity
    bool PutCallParity(double CP, double S);                      // check if put call parity holds

    // Modifier functions
    void toggle();                                      // Change option type (C/P, P/C)
    void setValue(double val, optionInput input);
};


#endif /* EuropeanOption_hpp */
