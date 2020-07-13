//
//  main.cpp
//  CPP_3.5
//
//  Created by Zhehao Li on 2020/3/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test Payoff Class

#include "CallPayoff.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    Payoff * myPayoff = new CallPayoff(10);                 // Create a Payoff Pointer to CallPayoff objects (initialized with value)

    std::cout << myPayoff->payoff(20) << std::endl;         // Call the member function of CallPayoff with Payoff type Pointer

    delete myPayoff;

    myPayoff = new CallPayoff(20);                          // Strike price K = 20
    std::cout << myPayoff->payoff(20) << std::endl;         // Price S = 20

    delete myPayoff;
    
    return 0;
}
