//
//  main.cpp
//  2 - Tuples
//
//  Created by Zhehao Li on 2020/4/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_io.hpp"
#include <string>
#include <iostream>
using namespace std;

boost::tuple<double, double> Arithmetic(double f, double s){

    // Create an anonymous object
    return boost::make_tuple(f+s, f*s);
}


int main(int argc, const char * argv[]) {
    
    /* Example 1
    // Using declaration, for readability purposes
    using boost::tuple;

    // Creating tuples using Tuple constructor with appropriate arguments
    tuple<std::string, int>  myTuple = boost::make_tuple(std::string("position x"), 0);

    // Print the tuple
    std::cout << myTuple << std::endl;
    */
    
    /* Example 2 */
    // Using declaration, for readability purposes
    using boost::tuple;

    // Creating tuples
    tuple<string, double> myTuple(string("Hello"), 3.1415);
    
    // Using make_tuple()
    tuple<string, int> myTuple2 = boost::make_tuple(string("position x"), 0);

    // Retrieving values from a tuple
    tuple<long, double, string> newTuple(100, 2.17, string("a new tuple"));

    long first = newTuple.get<0>();
    double second = newTuple.get<1>();
    string third = newTuple.get<2>();

    cout << "Elements of tuple: " << first << ", " << second  << ", " << third << endl;
    cout << newTuple << endl;

    // Creating a tuple using our own function
    double a = 2.0; double b = 3.0;
    tuple<double, double> calc = Arithmetic(a, b);

    // Printing tuple
    cout << "Arithmetic: " << calc.get<0>() << ", " << calc.get<1>() << endl;
    cout << calc << endl;

    // Modifying the tuple's element values using get member function
    calc.get<0>() = 3.0;
    calc.get<1>() = 2.0;
    cout << "Arithmetic: " << calc.get<0>() << ", " << calc.get<1>() << endl;

    // Modification using free function get, notice the namespace (boost::tuples::)
    boost::tuples::get<0>(calc) = 5.0;
    boost::tuples::get<1>(calc) = 5.0;

    // Print tuple
    //cout << "Arithmetic: " << calc.get<0>() << ", " << calc.get<1>() << endl;
    cout << "After modification: " << calc << endl;


    // Tie tuple elements with normal C variables
    string name; double value;
    tuple<string, double> myTupleA(string("Hello"), 3.1415);
    boost::tie(name, value) = myTupleA;                                 // Unpacked
    cout << "Tuple components: " << name << ", " << value << endl;
    
    return 0;
}

/*
 boost::tuple
 boost::make_tuple
 boost::tie
 boost::get
 */
