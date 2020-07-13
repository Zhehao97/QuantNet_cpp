//
//  PerpetualOption.cpp
//  A&B_ExactPricingMethod
//
//  Created by Zhehao Li on 2020/5/25.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "PerpetualOption.hpp"

/* Private Memeber Functions */
// Call price
double PerpetualOption::CallPrice(double S) const{

    double tmp = 0.5 - b / (sig * sig);
    double y1 = tmp + sqrt(pow(tmp, 2.0) + 2 * r / (sig * sig));

    return K / (y1 - 1) * pow((y1 - 1) / y1 * S / K, y1);
}

// Put price
double PerpetualOption::PutPrice(double S) const{
    
    double tmp = 0.5 - b / (sig * sig);
    double y2 = tmp - sqrt(pow(tmp, 2.0) + 2 * r / (sig * sig));

    return K / (1 - y2) * pow((y2 - 1) / y2 * S / K, y2);
}



/* Public Memeber Functions */
// Default constructor
PerpetualOption::PerpetualOption(): Option(), K(110.0), r(0.05), sig(0.2), b(0.05) {
    //
}

// Copy constructor
PerpetualOption::PerpetualOption(const PerpetualOption & option2): Option(option2), K(option2.K), r(option2.r), b(option2.b), sig(option2.sig) {
    //
}



// Destructor
PerpetualOption::~PerpetualOption() {}

// Assignment Operators
PerpetualOption & PerpetualOption::operator = (const PerpetualOption & option2) {
    if (this == &option2) {
        return *this;
    }
    else{
        Option::operator = (option2);
        K   = option2.K;
        r   = option2.r;
        b   = option2.b;
        sig = option2.sig;

        return *this;
    }
}

// Accessing functions
// Get value of price and senstivity of option
double PerpetualOption::getValue(optionOutput output, double S) const{
    return Value(S);
}

// Compute the price of option
double PerpetualOption::Value(double S) const{
    if (optType == "C") {
        return CallPrice(S);
    }
    else{
        return PutPrice(S);
    }
}


// Modifier functions
// Change the type of option
void PerpetualOption::toggle(){
    
    if (optType == "C") {
        optType = "P";
    }
    else{
        optType = "C";
    }
}

void PerpetualOption::setValue(double val, optionInput input){
    
    switch (input) {
        case strike:
            K = val;
            break;
        case rate:
            r = val;
            break;
        case cost:
            b = val;
            break;
        case volatility:
            sig = val;
            break;
        default:
            break;
    }
}
