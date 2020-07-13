//
//  main.cpp
//  3 - Variant
//
//  Created by Zhehao Li on 2020/4/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test Variant

#include "Point.hpp"
#include <boost/variant.hpp>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // Using declaration, for readability purposes
    using boost::variant;

    // Equivalent of C union
    typedef variant<int, float, double> NumericDataType;

    NumericDataType myType = 3.142;
    cout << myType << endl;
    
    myType = 1.98f;
    cout << myType << endl;
    
    myType = static_cast<double>(3.14);             // Force data type converted, cast<new type>(value)
    cout << myType << endl;

    // Gives compiler error
    // myType = string("dddd");

    
    // Some ways to construct a variant
    variant<long, string, Point> myVariant;                 // Default constructed: long
    variant<long, string, Point> myVariant2(myVariant);     // Copy constructed

    Point pt(1.0, 2.0);
    variant<long, string, Point> myVariant3(pt);            // Constructed with value: Point

    long val = 100;
    variant<long, string, Point> myVariant4(val);           // Constructed with value: long

    variant<long, string, Point> myVariant5 = myVariant4;   // Assignment operator = variant

    variant<long, string, Point> myVariant6 = val;          // Assignment opertoar = long

    // Give some values
    myVariant = 24;                                         // Assignment opertoar = long

    myVariant = string("It's amazing");                     // Assignment opertoar = string
    myVariant = Point(3.0, 4.0);                            // Assignment opertoar = Point

    // Try to get the value out of the variant
    Point ptA;                                              // Default constructed (0,0)
    string stA;
    
    try{
        ptA = boost::get<Point>(myVariant);
//        stA = boost::get<string>(myVariant); // won't work, wrong type
    }
    catch (boost::bad_get & err){
        cout << "Error: " << err.what() << endl;
    }

    cout << "Value got from Variant: " << ptA << endl;
    return 0;
}

/*
 A Cast operator is an unary operator which forces one data type to be converted into another data type.
 C++ supports four types of casting:
 1. Static Cast
 2. Dynamic Cast
 3. Const Cast
 4. Reinterpret Cast
 */
