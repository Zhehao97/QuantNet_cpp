//
//  Range.cpp
//  VI.4 Monte Carlo Simulation
//
//  Created by Zhehao Li on 2020/5/4.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The implementation of template class Range

#ifndef Range_cpp
#define Range_cpp

#include "Range.hpp"

// Constructors
// Default constructor
template <typename Type> Range<Type>::Range(){
    Type def(0);
    lo = def;
    hi = def;
}

// Constructor with two values
template <typename Type> Range<Type>::Range(const Type & l, const Type & h){
    if (l < h) {
        lo = l;
        hi = h;
    }
    else{
        lo = h;
        hi = l;
    }
}

// Copy constructor
template <typename Type> Range<Type>::Range(const Range<Type> & source){
    lo = source.l;
    hi = source.h;
}


// Destructor
template <typename Type> Range<Type>::~Range(){
    // ...
}


// Assignment operator
template <typename Type> Range<Type> & Range<Type>::operator = (const Range<Type> & source){
    if (this == &source) {
        return *this;
    }
    lo = source.lo;
    hi = source.hi;
    return *this;
}

// Accessing function
// return low value
template <typename Type> Type Range<Type>::low() const{
    return lo;
}

// return high value
template <typename Type> Type Range<Type>::high() const{
    return hi;
}

// return the spread
template <typename Type> Type Range<Type>::spread() const{
    return (hi - lo);
}

// if the value is lower than lo
template <typename Type> bool Range<Type>::left(const Type & val) const{
    if (val < lo) {
        return true;
    }
    return false;
}

// if the value is higher than hi
template <typename Type> bool Range<Type>::right(const Type & val) const{
    if (val > hi) {
        return true;
    }
    return false;
}

// if the value is contained in range
template <typename Type> bool Range<Type>::contains(const Type & val) const{
    if ((lo <= val) && (val <= hi)) {
        return true;
    }
    return false;
}


// Modifier functions
// modifier the low value
template <typename Type> void Range<Type>::low(const Type & l1){
    lo = l1;
}

template <typename Type> void Range<Type>::high(const Type & h1){
    hi = h1;
}


// Utility functions
template <typename Type> std::vector<Type> Range<Type>::mesh(long nSteps) const{
    Type val = lo;
    Type h = (hi - lo) / Type(nSteps);                      // force to change the type
    std::vector<Type> results(nSteps + 1);
    for (long i = 0; i < nSteps + 1; i++) {
        results[i] = val;
        val += h;
    }
    return results;
}

#endif /* Range_cpp */
