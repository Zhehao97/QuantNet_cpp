//
//  NormalGenerator.hpp
//  VI.4 Monte Carlo Simulation
//
//  Created by Zhehao Li on 2020/5/4.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The declaration of Normal random number generator

#ifndef NormalGenerator_hpp
#define NormalGenerator_hpp

#include <boost/random.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/variate_generator.hpp>

class NormalGenerator{                                  // an abstract base class

public:
    // Constructors
    NormalGenerator();
    NormalGenerator(const NormalGenerator & source);
    
    // Destructors
    virtual ~NormalGenerator();
    
    // Assignment operator
    NormalGenerator & operator = (const NormalGenerator & source);
    
    // Accessing functions
    virtual double getNormal() const = 0;               // pure virtual memeber function
    
};


class BoostNormalGenerator : public NormalGenerator{
    
private:
    boost::lagged_fibonacci607 rng;                     // random number generator
    boost::normal_distribution<> nor;                   // default => double
    boost::variate_generator<boost::lagged_fibonacci607 &, boost::normal_distribution<>> * myRandom;        // random variable generator

public:
    // Constructors
    BoostNormalGenerator();
    BoostNormalGenerator(const BoostNormalGenerator & source);
    
    // Destructors
    ~BoostNormalGenerator();
    
    // Assignment operator
    BoostNormalGenerator & operator = (const BoostNormalGenerator & source);
    
    // Accessing functions
    double getNormal() const;
    
};

#endif /* NormalGenerator_hpp */
