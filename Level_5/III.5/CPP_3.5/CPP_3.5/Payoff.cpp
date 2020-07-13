//
//  Payoff.cpp
//  CPP_3.5
//
//  Created by Zhehao Li on 2020/3/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Definiton of base class Payoff

#include "Payoff.hpp"


// Constructors
Payoff::Payoff(){
    // Default Constructors (like a placeholder)
}

Payoff::Payoff(const Payoff & source){
    // Copy Constructors
}


// Destructor
Payoff::~Payoff(){
    // Destructor
}


// Acceessing Functions --> Virtual


// Assginment Functions
Payoff & Payoff::operator = (const Payoff &source){
    if (this == &source) {                                  // The address is the same
        return * this;
    }
    
    /*
    Assgiment operatorns on private data members
    */
    
    return * this;                                          // Returny by reference
}

