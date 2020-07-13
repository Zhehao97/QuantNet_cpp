//
//  OptionData.h
//  CPP_1.9
//
//  Created by Zhehao Li on 2020/2/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef OptionData_h
#define OptionData_h

#include <iostream>
using namespace std;

// Encapsulate all data in one placee
struct OptionData{
    
    // option data + behaviour
    double K;
    double T;
    double r;
    double sig;
    
    // Extra data
    double D;       // dividend
    double beta;    // elasticity factor (CEV model)
    
    int type;       // 1 == call option, -1 = put optiion
    
    // Not C, strictly speaking. This is a destructor that gats called automatically when an object's memory is freed.
    
    ~OptionData(){                      // destructor
        cout << "Bye Option Data..\n";
    }
};

void print(OptionData data){        // Call by value
    
    cout << "Strike: " << data.K << endl;
    cout << "Expiry: " << data.T << endl;
    cout << "Interest: " << data.r << endl;
    cout << "Volatility: " << data.sig << endl;
    cout << "Dividend: " << data.D << endl;
    cout << "Elasticity factor (beta): " << data.beta << endl;
    cout << "Call or Put: " << data.type << endl;
}

void print2(OptionData* data){      // Call by value
    
    cout << "Strike: " << data->K << endl;
    cout << "Expiry: " << data->T << endl;
    cout << "Interest: " << data->r << endl;
    cout << "Volatility: " << data->sig << endl;
    cout << "Dividend: " << data->D << endl;
    cout << "Elasticity factor (beta): " << data->beta << endl;
    cout << "Call or Put: " << data->type << endl;
    
}

#endif /* OptionData_h */
