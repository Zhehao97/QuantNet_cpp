//
//  CallPayoff.cpp
//  CPP_3.5
//
//  Created by Zhehao Li on 2020/3/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Defintion of derived class CallPayoff from base class Payoff


#include "CallPayoff.hpp"


// Constructors
CallPayoff::CallPayoff(){                               // Default Constructor
    K = 100.0;                                          // Prototype value
}

CallPayoff::CallPayoff(double strike){                  // Constructor with value
    K = strike;                                         // Assgin new value
}

CallPayoff::CallPayoff(const CallPayoff & source){      // Copy Constructor
    K = source.K;
}


// Destructors
CallPayoff::~CallPayoff(){
    // Bye Bye
}


// Accessing Functions
double CallPayoff::Strike() const{
    return K;
}

double CallPayoff::payoff(double S) const{
    if (S > K) {
        return (S - K);
    }
    else{
        return 0.0;
    }
}


// Assignment Functions
void CallPayoff::Strike(double newK){                   // Strike() function overloading with diff return type and arguments type
    K = newK;
}

CallPayoff & CallPayoff::operator = (const CallPayoff & source){
    if (this == &source) {
        return *this;
    }
    else{
        Payoff::operator = (source);                    // Call the base class assignment operator to copy the states of it
        K = source.K;                                   // Copy the states of CallPayoff class
        return *this;
    }
}
