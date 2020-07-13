//
//  main.cpp
//  CPP_4.2
//
//  Created by Zhehao Li on 2020/3/25.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test Range template class

#include "Range.cpp"
#include <iostream>
using namespace std;

typedef Range<> DoubleRange;

int main(int argc, const char * argv[]) {
    
    // The default type is double
    double closingPrice (45.7);
    double openingPrice (60.0);
    Range<double> bearish (closingPrice, openingPrice);         // Create a template class

    Range<> r2;                     // Type = double
    DoubleRange r3(r2);             // Type = double

    // Looking at some prices
    double currentPrice = 50.0;

    bool test1 = bearish.left(currentPrice);
    bool test2 = bearish.right(currentPrice);
    bool test3 = bearish.contains(currentPrice);
    
    if (test1 == false && test2 == false && test3 == true)
        cout << "Everything OK\n";

    // Create a range with float as underlying type
    float closingPriceII (90.0);
    float openingPriceII (60.0);
    Range<float> bulllish (closingPriceII, openingPriceII);
    
    return 0;
}
