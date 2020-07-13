//
//  GenericInequalities.cpp
//  CPP_4.1
//
//  Created by Zhehao Li on 2020/3/25.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Definition of template function
//
// Preprocessor directives; ensures that we do not include a file twice (gives compiler error)

#ifndef GenericInequalities_cpp
#define GenericInequalities_cpp

#include "GenericInequalities.hpp"   // Can be commented out

// Max and Min of two numbers
template <typename Numeric> Numeric Max(const Numeric & x, const Numeric & y){
    if (x > y) {
        return x;
    }
    else{
        return y;
    }
}

template <typename Numeric> Numeric Min(const Numeric & x, const Numeric & y){
    if (x < y) {
        return x;
    }
    else{
        return y;
    }
}

// Max and Min of three numbers
template <typename Numeric> Numeric Max(const Numeric & x, const Numeric & y, const Numeric & z){
    return Max<Numeric>(z, Max<Numeric>(x, y));
}

template <typename Numeric> Numeric Min(const Numeric & x, const Numeric & y, const Numeric & z){
    return Min<Numeric>(z, Min<Numeric>(x, y));
}

#endif /* GenericInequalities_cpp */
