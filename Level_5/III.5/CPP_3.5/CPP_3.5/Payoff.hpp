//
//  Payoff.hpp
//  CPP_3.5
//
//  Created by Zhehao Li on 2020/3/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Declaration of base class Payoff

#ifndef Payoff_hpp
#define Payoff_hpp

#include <iostream>

class Payoff{
    
public:
    // Constructors
    Payoff();                                       // Default Constructor
    Payoff(const Payoff & source);                  // Copy Constructor
    
    // Destructor
    virtual ~ Payoff();                             // Virtual Destructor
    
    // Acessing Functions
    virtual double payoff(double S) const = 0;      // Pure virtual payoff function for a given price S
    
    // Assginment Functions
    Payoff & operator = (const Payoff & source);    // Return by reference
};


#endif /* Payoff_hpp */


/*
 If you have an abstract class (where virtual function = 0) then all of the functions in the base class need to be over-ridden in order to instantiate an object of the derived class.
 Your compiler error is telling you that you have not over-ridden all of the functions.
 */
