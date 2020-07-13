//
//  NormalGenerator.cpp
//  VI.4 Monte Carlo Simulation
//
//  Created by Zhehao Li on 2020/5/4.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "NormalGenerator.hpp"

/* class NormalGenerator */

// Constructors
NormalGenerator::NormalGenerator(){
    // Default consturctor
}

NormalGenerator::NormalGenerator(const NormalGenerator & source){
    // Copy constructor
}

// Destructor
NormalGenerator::~NormalGenerator(){
    // Destructor
}

// Assignment operator
NormalGenerator & NormalGenerator::operator=(const NormalGenerator & source){
    if (this == &source) {
        return *this;
    }
    /* private data member handling */
    return *this;
}

// Accessinig functions --> virtual


/* ---------------------------------------------------------------- */

/* class BoostNormalGenerator begin */

// Constructors
BoostNormalGenerator::BoostNormalGenerator() : NormalGenerator() {
    rng = boost::lagged_fibonacci607();
    nor = boost::normal_distribution<>(0, 1);
    myRandom = new boost::variate_generator<boost::lagged_fibonacci607 &, boost::normal_distribution<>>(rng, nor);
}

BoostNormalGenerator::BoostNormalGenerator(const BoostNormalGenerator & source) : NormalGenerator(source) {
    rng = source.rng;
    nor = source.nor;
    myRandom = source.myRandom;
}

// Destructor
BoostNormalGenerator::~BoostNormalGenerator() {
    delete myRandom;
}

// Assignment operator
BoostNormalGenerator & BoostNormalGenerator::operator = (const BoostNormalGenerator & source) {
    if (this == &source) {
        return *this;
    }
    rng = source.rng;
    nor = source.nor;
    myRandom = source.myRandom;
    return *this;
}

// Accessiing functions
double BoostNormalGenerator::getNormal() const{
    return (*myRandom)();
}
