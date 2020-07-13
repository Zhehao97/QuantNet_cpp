//
//  Range.cpp
//  CPP_4.2
//
//  Created by Zhehao Li on 2020/3/25.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Definition of Range template class

#ifndef Range_cpp
#define Range_cpp

#include "Range.hpp"

// Constructors
template <typename Type>
Range<Type>::Range(){                                       // Default constructor
    Type val(0);                                            // Need this, called default constructor of each type
    lo = val;
    hi = val;
}

template <typename Type>
Range<Type>::Range(const Type & low, const Type & high){    // Constructor with values
    if (low < high) {
        lo = low;
        hi = high;
    }
    else{
        lo = high;
        hi = low;
    }
}

template <typename Type>
Range<Type>::Range(const Range<Type> & ran1){               // Copy constructor
    lo = ran1.lo;
    hi = ran1.hi;
}


// Destructor
template <typename Type>                                       // All template functions and classes need this title
Range<Type>::~Range(){}


// Modifier functions
template <typename Type>
void Range<Type>::low(const Type &t1){
    lo = t1;
}

template <typename Type>
void Range<Type>::high(const Type &t1){
    hi = t1;
}


// Accessing functions
template <typename Type>
Type Range<Type>::low() const{
    return lo;
}

template <typename Type>
Type Range<Type>::high() const{
    return hi;
}

template <typename Type>
Type Range<Type>::spread() const{
    return (hi - lo);
}


// Operators overloading
template <typename Type>
Range<Type> & Range<Type>::operator=(const Range<Type> & ran2){
    lo = ran2.lo;
    hi = ran2.hi;
    return * this;
}


// Booleean functions
template <typename Type>
bool Range<Type>::left(const Type & val) const{
    if (val < lo) {
        return true;
    }
    else{
        return false;
    }
}

template <typename Type>
bool Range<Type>::right(const Type & val) const{
    if (val > hi) {
        return true;
    }
    else{
        return false;
    }
}

template <typename Type>
bool Range<Type>::contains(const Type &val) const{
    if (lo <= val && val <= hi) {
        return true;
    }
    else{
        return false;
    }
}


#endif /* Range_cpp */
