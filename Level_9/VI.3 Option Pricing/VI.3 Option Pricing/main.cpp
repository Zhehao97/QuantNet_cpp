//
//  main.cpp
//  VI.3 Option Pricing
//
//  Created by Zhehao Li on 2020/4/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Testing all kind of options

#include "EuropeanOption.hpp"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    /* All options are European option */
    double S;                                               // Underling Assset Price
    
    // 1. Options on a Stock
    EuropeanOption stockOption;
    stockOption.optType = "C";
    stockOption.K   = 99.0;
    stockOption.T   = 1.0;
    stockOption.r   = 0.0;
    stockOption.sig = 0.10;
    stockOption.b   = 0.0;
    
    cout << "Stock price S: ";
    cin >> S;
    
    cout << stockOption.optType << " option Price on a stock: " << stockOption.Price(S) << endl;
    cout << stockOption.optType << " option Delta on a stock: " << stockOption.Delta(S) << endl;
    stockOption.toggle();
    cout << stockOption.optType << " option Price on a stock: " << stockOption.Price(S) << endl;
    cout << stockOption.optType << " option Delta on a stock: " << stockOption.Delta(S) << endl;
    cout << endl;
    
    // 2. Options on a Stock Index
    EuropeanOption indexOption;
    indexOption.optType = "C";
    indexOption.K   = 50.0;
    indexOption.T   = 0.41667;
    indexOption.r   = 0.1;
    indexOption.sig = 0.00;

    double q = 0.0;                                         // Dividend yield
    indexOption.b = indexOption.r - q;

    cout << "Index price S: ";
    cin >> S;

    cout << indexOption.optType << " option Price on a index: " << indexOption.Price(S) << endl;
    cout << indexOption.optType << " option Delta on a index: " << indexOption.Delta(S) << endl;
    indexOption.toggle();
    cout << indexOption.optType << " option Price on a index: " << indexOption.Price(S) << endl;
    cout << indexOption.optType << " option Delta on a index: " << indexOption.Delta(S) << endl;
    cout << endl;
    
    // 3. Options on a Future
    EuropeanOption futureOption;
    futureOption.optType = "C";
    futureOption.K   = 19.0;
    futureOption.T   = 0.75;
    futureOption.r   = 0.10;
    futureOption.sig = 0.28;
    futureOption.b = 0.0;
    
    cout << "Future price S: ";
    cin >> S;
    
    cout << futureOption.optType << " option Price on a future: " << futureOption.Price(S) << endl;
    cout << futureOption.optType << " option Delta on a future: " << futureOption.Delta(S) << endl;
    futureOption.toggle();
    cout << futureOption.optType << " option Price on a future: " << futureOption.Price(S) << endl;
    cout << futureOption.optType << " option Delta on a future: " << futureOption.Delta(S) << endl;
    cout << endl;

    // 4. Options on a Currency
    EuropeanOption currencyOption;
    currencyOption.optType = "C";
    currencyOption.K = 1.60;
    currencyOption.T = 0.5;
    currencyOption.r = 0.06;
    currencyOption.sig = 0.12;

    double rf = 0.08;                               // risk-free rate of foreign currency
    currencyOption.b = currencyOption.r - rf;

    cout << "Currency price S: ";
    cin >> S;
    
    cout << currencyOption.optType << " option Price on a currency: " << currencyOption.Price(S) << endl;
    cout << currencyOption.optType << " option Delta on a currency: " << currencyOption.Delta(S) << endl;
    futureOption.toggle();
    cout << currencyOption.optType << " option Price on a currency: " << currencyOption.Price(S) << endl;
    cout << currencyOption.optType << " option Delta on a currency: " << currencyOption.Delta(S) << endl;
    cout << endl;
    
    return 0;
}
