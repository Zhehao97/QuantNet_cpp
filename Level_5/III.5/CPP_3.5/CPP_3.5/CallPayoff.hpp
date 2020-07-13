//
//  CallPayoff.hpp
//  CPP_3.5
//
//  Created by Zhehao Li on 2020/3/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Declaration of derived class CallPayoff from base class Payoff

#ifndef CallPayoff_hpp
#define CallPayoff_hpp

#include "Payoff.hpp"
#include <iostream>


class CallPayoff : public Payoff{                           // Colon syntax

private:
    double K;                                               // Strike price
    
public:
    // Consturctors
    CallPayoff();                                           // Default Constructors
    CallPayoff(double strike);                              // Construcotrs with value
    CallPayoff(const CallPayoff & source);                  // Copy Constructor
    
    // Destructor
    ~CallPayoff();                                          // Virtual function is 10x times slower
    
    // Acessing Functions
    double Strike() const;                                  // Return the strike price
    double payoff(double S) const;                          // Implement the pure virtual payoff function from base class
    
    // Assignment Functions
    void Strike(double newK);                               // Function overloading, set new strike price
    CallPayoff & operator = (const CallPayoff & source);    // Assignment operator
    
};


#endif /* CallPayoff_hpp */
