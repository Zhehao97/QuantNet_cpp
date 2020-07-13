//
//  main.cpp
//  A&B_ExactPricingMethod
//
//  Created by Zhehao Li on 2020/5/23.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Groups A&B: Exact Pricing Methods

#include "EuropeanOption.hpp"
#include "PerpetualOption.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    // -------------------------------------------------
    /* A. Exact Solutions of One-Factor Plain Options */
    // -------------------------------------------------
        
    EuropeanOption stockOption;
    stockOption.T = 1.5;
    stockOption.K = 120.0;
    stockOption.r = 0.04;
    stockOption.b = stockOption.r;
    stockOption.sig = 0.40;
    stockOption.optType = "C";
    
    double S = 100.0;
    double cPrice = stockOption.Value(S);
    double cDelta = stockOption.Delta(S);
    double Gamma = stockOption.Gamma(S);
    
    stockOption.toggle();
    
    double pPrice = stockOption.Value(S);
    double pDelta = stockOption.Delta(S);
    
    std::cout << "Call Price = " << cPrice << ", Call Delta = " << cDelta << "\n";
    std::cout << "Put Price = " << pPrice << ", Put Delta = " << pDelta << "\n";
    std::cout << "Gamma = " << Gamma << "\n";
    
    
    
    // A-I-(b). Apply the put-call parity relationship
    stockOption.optType = "C";
    
    cPrice = stockOption.PutCallParity(S);
    std::cout << "Put-Call Parity, Call Price = " << cPrice << "\n";
    std::cout << "Put-Call Parity Test: " << stockOption.PutCallParity(cPrice) << "\n\n";
    
    stockOption.toggle();
    
    pPrice = stockOption.PutCallParity(S);
    std::cout << "Put-Call Parity, Put Price = " << pPrice << "\n";
    std::cout << "Put-Call Parity Test: " << stockOption.PutCallParity(pPrice) << "\n\n";
    
    
    // A-I-(c). Compute option prices for a series of spot price
    int len = 5;
    optionOutput output = value;
    std::vector<double> priceArr;
    std::vector<double> valueArr;
    
    stockOption.optType = "C";
    
    // Input value
    for (int i = 0; i < len; i++) {
        priceArr.push_back(S + 2.0 * i);
    }
    
    valueArr = PriceArray(stockOption, priceArr, output);
    
    // Output value
    for (int i = 0; i < valueArr.size(); i++) {
        std::cout << "S = " << priceArr[i] << ", Option price = " << valueArr[i] << "\n";
    }
    
    
    // A-I-(d). Input a matrix of option parameters and receive a matrix of option prices as the result
    
    std::vector<double> paraVec1;
    std::vector<double> paraVec2;
    
    for (int i = 0; i < len; i++) {
        paraVec1.push_back(stockOption.T + i);
    }

    for (int i = 0; i < len; i++) {
        paraVec2.push_back(stockOption.sig + 0.01 * i);
    }
    
    optionInput input1 = maturity;
    optionInput input2 = volatility;
    optionOutput output1 = value;
    
    std::map<optionInput, std::vector<double>> paraMat;
    paraMat[input1] = paraVec1;
    paraMat[input2] = paraVec2;
    
    std::vector<std::vector<double>> valueMat;
    valueMat = ParameterMatrix(stockOption, paraMat, input1, input2, output1, "C", S);
    
    // print out the result
    std::cout << "\n-- Option Price Matrix -- \n" << "Expiry  ";
    
    for (int i = 0; i < paraVec1.size(); i++) {
        std::cout << paraVec1[i] << "  ";
    }
    
    std::cout << "\n" << "Sigma" << "\n";
    
    for (int i = 0; i < valueMat.size(); i++) {
        std::cout << paraVec2[i] << " | ";
        for (int j = 0; j < valueMat[i].size(); j++) {
            std::cout << valueMat[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    
    // A-II. Option Sensitivities (aka the Greeks)  
    
    // A-II-(a). Compute delta and gamma for call and put future option pricing
    double delta_call = stockOption.Delta(S);
    stockOption.toggle();
    double delta_put = stockOption.Delta(S);
    
    std::cout << "\nDelta_Call = " << delta_call << ", Delta_Put = " << delta_put << "\n";
    std::cout << "\nGamma = " << stockOption.Gamma(S) << "\n\n";
    
    // A-II-(b). Compute call delta value for a monotonically increasing range of underlying values of S.
    len = 5;
    output = gama;
    
    priceArr.clear();
    for (int i = 0; i < len; i++) {
        priceArr.push_back(S + i);
    }
    
    valueArr.clear();
    valueArr = PriceArray(stockOption, priceArr, output);
    
    for (int i = 0; i < valueArr.size(); i++) {
        std::cout << "Stock Price = " << priceArr[i] << ", Option gamma = " << valueArr[i] << "\n";
    }
    
    
    // A-II-(c). Input a matrix of option parameters and receive a matrix of option prices as the result
    input1 = maturity;
    input2 = volatility;
    output1 = gama;
    
    paraVec1.clear();
    for (int i = 0; i < len; i++) {
        paraVec1.push_back(stockOption.T + i);
    }
    
    paraVec2.clear();
    for (int i = 0; i < len; i++) {
        paraVec2.push_back(stockOption.sig + 0.02 * i);
    }
    
    paraMat[input1] = paraVec1;
    paraMat[input2] = paraVec2;
    
    valueMat = ParameterMatrix(stockOption, paraMat, input1, input2, output1, "P", S);
    
    // print out the result
    std::cout << "\n-- Option Gamma Matrix -- \n" << "Expiry  ";
    
    for (int i = 0; i < paraVec1.size(); i++) {
        std::cout << paraVec1[i] << "  ";
    }
    
    std::cout << "\n" << "Sigma" << "\n";
    
    for (int i = 0; i < valueMat.size(); i++) {
        std::cout << paraVec2[i] << " | ";
        for (int j = 0; j < valueMat[i].size(); j++) {
            std::cout << valueMat[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    
    // A-II-(d). Divided Differences method to compute optioin sensitivities
    
    double numeric_gamma = numericGamma(stockOption, S, 0.05);
    double numeric_delta_put = numericDelta(stockOption, S, 0.10);
    stockOption.toggle();
    double numeric_delta_call = numericDelta(stockOption, S, 0.10);
    
    std::cout << "\nNumeric Delta_Call = " << numeric_delta_call << ", Numeric Delta_Put = " << numeric_delta_put << "\n";
    std::cout << "\nStock Price = " << S <<  ", Numeric Gamma = " << numeric_gamma << "\n";
    
    
    // ---------------------------------
    /* B. Perpetual American Options */
    // ---------------------------------
    
    // B-(a). See PerpetualOption.cpp
    
    
    // B-(b). Pricing the Perpetual Options
    PerpetualOption xpo;
    xpo.K = 100.0;
    xpo.r = 0.10;
    xpo.b = 0.02;
    xpo.sig = 0.10;
    xpo.optType = "C";
    
    double S_xpo = 110.0;
    double xpoCall = xpo.Value(S_xpo);
    xpo.toggle();
    double xpoPut = xpo.Value(S_xpo);
    
    std::cout << "\nPerpetual option, Call = " << xpoCall << ", Put = " << xpoPut << "\n\n";
    
    
    // B-(c). Compute call and put option price for a monotonically increasing range of underlying values of S
    
    len = 5;
    output = value;
    
    priceArr.clear();
    for (int i = 0; i < len; i++) {
        priceArr.push_back(S_xpo + 2.0 * i);
    }
    
    valueArr.clear();
    valueArr = PriceArray(xpo, priceArr, output);
    
    for (int i = 0; i < valueArr.size(); i++) {
        std::cout << "Asset Price = " << priceArr[i] << ", Option value = " << valueArr[i] << "\n";
    }
    
    
    // B-(d). Input a matrix of option parameters and receive a matrix of Perpetual American option prices
    input1 = rate;
    input2 = volatility;
    output1 = gama;
    
    paraVec1.clear();
    for (int i = 0; i < len; i++) {
        paraVec1.push_back(xpo.r + 0.02 * i);
    }
    
    paraVec2.clear();
    for (int i = 0; i < len; i++) {
        paraVec2.push_back(xpo.sig + 0.04 * i);
    }
    
    // Generate a matrix of parameters
    paraMat[input1] = paraVec1;
    paraMat[input2] = paraVec2;
    
    valueMat = ParameterMatrix(stockOption, paraMat, input1, input2, output1, "P", S);
    
    // print out the result
    std::cout << "\n-- Perpetual Option Value Matrix -- \n" << "Interest rate  ";
    
    for (int i = 0; i < paraVec1.size(); i++) {
        std::cout << paraVec2[i] << "  ";
    }
    
    std::cout << "\n" << "Volatility" << "\n";
    
    for (int i = 0; i < valueMat.size(); i++) {
        std::cout << paraVec2[i] << " | ";
        for (int j = 0; j < valueMat[i].size(); j++) {
            std::cout << valueMat[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}
