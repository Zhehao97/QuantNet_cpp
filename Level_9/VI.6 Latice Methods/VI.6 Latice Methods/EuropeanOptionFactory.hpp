//
//  EuropeanOptionFactory.hpp
//  VI.6 Latice Methods
//
//  Created by Zhehao Li on 2020/5/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef EuropeanOptionFactory_hpp
#define EuropeanOptionFactory_hpp

#include "Option.hpp"
#include <iostream>

class EuropeanOptionFactory{
    
public:
    EuropeanOptionFactory(){}
    virtual ~EuropeanOptionFactory(){}
    virtual Option * create() const = 0;
};


class ConsoleEuroOptionFactory: public EuropeanOptionFactory{
    
public:
    Option * create() const{
        std::cout << "\n*** Parameters for option object ***\n";
        
        Option * opt = new Option;
        
        std::cout << "Strike: ";
        std::cin >> opt->K;
        
        std::cout << "Volatility([0,1]): ";
        std::cin >> opt->sig;
        
        std::cout << "Interest rate([0,1]): ";
        std::cin >> opt->r;
        
        std::cout << "Expiry date: ";
        std::cin >> opt->T;
        
        std::cout << "1. Call, 2. Put:";
        std::cin >> opt->type;
        
        return opt;
    }
};

#endif /* EuropeanOptionFactory_hpp */
