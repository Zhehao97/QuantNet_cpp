//
//  Option.cpp
//  A&B_ExactPricingMethod
//
//  Created by Zhehao Li on 2020/5/25.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "Option.hpp"

/* Public Member functions */
// Default constructor
Option::Option(): optType("C"){
    //
}

// Copy constructor
Option::Option(const Option & opt): optType(opt.optType){
    //
}

// Desturctor
Option::~Option(){
    //
}

// Assgnment operators
Option & Option::operator = (const Option & opt){
    if (this == &opt) {
        return *this;
    }
    optType = opt.optType;
    return *this;
}



/* Global Utility Functions */
// Mesher Array
std::vector<double> PriceArray(Option & Opt, std::vector<double> priceArr, optionOutput output){
    
    double tmp = 0.0;
    std::vector<double> valueArr;
    
    for (int i = 0; i < priceArr.size(); i++) {
        tmp = Opt.getValue(output, priceArr[i]);
        valueArr.push_back(tmp);
    }
    return valueArr;
}

std::vector<std::vector<double>> ParameterMatrix(Option & Opt, std::map<optionInput, std::vector<double>> paraMat, optionInput input1, optionInput input2, optionOutput output, std::string oType, double S){
    
    Opt.optType = oType;
    std::vector<double> vec1 = paraMat[input1];
    std::vector<double> vec2 = paraMat[input2];
    std::vector<std::vector<double>> valueMat;
    
    for (int i = 0; i < vec2.size(); i++) {
        
        Opt.setValue(vec2[i], input2);
        std::vector<double> valueVec;
        
        for (int j = 0; j < vec1.size(); j++) {
        
            Opt.setValue(vec1[j], input1);
            valueVec.push_back( Opt.getValue(output, S) );
        }
        valueMat.push_back(valueVec);
    }
    return valueMat;
}

// Divided differences method for Delta
double numericDelta(Option & opt, double S, double h){
    
    double Vh = opt.Value(S + h);
    double Vl = opt.Value(S - h);
    
    return (Vh - Vl) / (2 * h);
}

// Divided differences method for Gamma
double numericGamma(Option & opt, double S, double h){
    
    double V = opt.Value(S);
    double Vh = opt.Value(S + h);
    double Vl = opt.Value(S - h);
    
    return (Vh + Vl - 2 * V) / (h * h);
}
