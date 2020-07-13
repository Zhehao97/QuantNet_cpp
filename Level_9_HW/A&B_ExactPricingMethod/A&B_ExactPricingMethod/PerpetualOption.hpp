//
//  PerpetualOption.hpp
//  A&B_ExactPricingMethod
//
//  Created by Zhehao Li on 2020/5/25.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef PerpetualOption_hpp
#define PerpetualOption_hpp

#include "Option.hpp"
#include "EuropeanOption.hpp"

// Class of European Option
class PerpetualOption: public Option{
    
private:
    // Kernel functions
    double CallPrice(double S) const;
    double PutPrice(double S) const;
    
public:
    // Member data
    double K;                   // strike price
    double r;                   // risk-free interest rate
    double b;                   // carry of cost = r + u - d, u is storage cost, and d is dividend
    double sig;                 // volatility
    

    // Constructors
    PerpetualOption();                                              // Default call option
    PerpetualOption(const PerpetualOption & option2);               // Copy constructor
    
    // Destructors
    virtual ~PerpetualOption();
    
    // Assignment operator
    PerpetualOption & operator = (const PerpetualOption & option2);

    // Accessing functions
    double getValue(optionOutput output, double S) const;               // Get the price and sensitivites of option
    double Value(double S) const;                               // Option price

    // Modifier functions
    void toggle();                                      // Change option type (C/P, P/C)
    void setValue(double val, optionInput input);       // Set the parameters of option
};

#endif /* PerpetualOption_hpp */
