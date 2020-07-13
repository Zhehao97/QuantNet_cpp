//
//  Option.hpp
//  A&B_ExactPricingMethod
//
//  Created by Zhehao Li on 2020/5/25.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef Option_hpp
#define Option_hpp

#include <vector>
#include <map>
#include <cmath>
#include <string>

// Enumerate class of option input parameters
enum optionInput{strike, maturity, rate, cost, volatility};

// Enumerate class of option output value
enum optionOutput{value, delta, gama};


class Option{
  
public:
    // Member data
    std::string optType;        // Option type (call, put)
    
    // Constructors
    Option();                                           // Default constructor
    Option(const Option & opt);                         // Copy constructor
    
    // Destructor
    virtual ~Option();
    
    // Operators
    Option & operator = (const Option & opt);           // Assignment
    
    // Accessors
    virtual double getValue(optionOutput output, double S) const = 0;         // Get the price and sensitivites of option
    virtual double Value(double S) const = 0;                               // Get the price of option
    
    
    // Modifier functions
    virtual void toggle() = 0;
    virtual void setValue(double val, optionInput input) = 0;
};



/* Utility Global Functions */
// Mesher array for parameter
std::vector<double> PriceArray(Option & Opt, std::vector<double> priceArr, optionOutput output);

// Mesher matrix for different parameters
std::vector<std::vector<double>> ParameterMatrix(Option & Opt, std::map<optionInput, std::vector<double>> paraMat, optionInput input1, optionInput input2, optionOutput output, std::string oType, double S);

// Divided differences method
double numericDelta(Option & opt, double S, double h);
double numericGamma(Option & opt, double S, double h);


#endif /* Option_hpp */
