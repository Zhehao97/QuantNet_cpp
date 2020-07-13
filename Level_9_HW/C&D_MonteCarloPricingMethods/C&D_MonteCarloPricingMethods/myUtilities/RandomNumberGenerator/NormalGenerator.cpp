//
//  NormalGenerator.cpp
//  VI.4 Monte Carlo Simulation
//
//  Created by Zhehao Li on 2020/5/4.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "NormalGenerator.hpp"

/* class NormalGenerator */
// Accessinig functions --> virtual


/* ---------------------------------------------------------------- */

/* class BoostNormalGenerator begin */

// Constructors
BoostNormalGenerator::BoostNormalGenerator() : NormalGenerator() {
    rng = boost::lagged_fibonacci607();
    nor = boost::normal_distribution<>(0, 1);
    myRandom = new boost::variate_generator<boost::lagged_fibonacci607 &, boost::normal_distribution<>>(rng, nor);
}

// Destructor
BoostNormalGenerator::~BoostNormalGenerator() {
    delete myRandom;
}


// Accessiing functions
double BoostNormalGenerator::getNormal() const{
    return (*myRandom)();
}
