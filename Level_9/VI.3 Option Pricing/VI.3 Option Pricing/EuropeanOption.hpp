//
//  EuropeanOption.hpp
//  VI.3 Option Pricing
//
//  Created by Zhehao Li on 2020/4/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp

#include <string>
#include <cmath>

class EuropeanOption{
    
private:
    /* Private memeber functions */    
    // Kernel functions
    double CallPrice(double U) const;
    double PutPrice(double U) const;
    double CallDelta(double U) const;
    double PutDelta(double U) const;
    
public:
    /* Public memeber */
    double r;                   // Interest rate
    double sig;                 // Volatility
    double K;                   // Strike price
    double T;                   // Expiry date
    double b;                   // Cost of carry
    std::string optType;        // Option type (call, put)
    
    /* Public memeber functions */
    // Constructors
    EuropeanOption();                                           // Default call option
    EuropeanOption(const EuropeanOption & option2);             // Copy constructor
    EuropeanOption(const std::string & optionType);             // Create option type
    
    // Destructors
    virtual ~EuropeanOption();
    
    // Assignment operator
    EuropeanOption & operator = (const EuropeanOption & option2);

    // Accessing functions
    double Price(double U) const;                           // option price
    double Delta(double U) const;                           // option sensitivities

    // Modifier functions
    void toggle();                                          // Change option type (C/P, P/C)
};

#endif /* EuropeanOption_hpp */
