//
//  main.cpp
//  4 - Random
//
//  Created by Zhehao Li on 2020/4/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "boost/random.hpp"                     // Convenience header file
#include "boost/random/detail/const_mod.hpp"    // LCG class
#include <iostream>
#include <ctime>                                // std::time

using namespace std;

template<class PRNG, class Dist> inline boost::variate_generator<PRNG &, Dist> make_gen(PRNG & rng, Dist d){
  return boost::variate_generator<PRNG &, Dist>(rng, d);
}   // Inline function

int main(int argc, const char * argv[]) {
    
    // 1. Get Pseudo-Random Number Generator Engine
    boost::mt19937 rng;                                     // A uniform RNG engine
//    boost::lagged_fibonacci607 rng;                         // A uniform RNG engine
    rng.seed(static_cast<unsigned int> (std::time(0)));     // Random seed
    
    // 2. Get specific Distribution
    boost::triangle_distribution<> tri(0.0, 0.5, 1.0);

    // 3. Construct specific Random Number Generator
    boost::variate_generator< boost::mt19937&, boost::triangle_distribution<> > triRng(rng, tri);   // <Enigne e, Dstn d>
//    boost::variate_generator<boost::lagged_fibonacci607&, boost::triangle_distribution<> > triRng(rng, tri);

    for (int n = 0; n <=100; ++n){
        cout << triRng() << ",";
    }
    return 0;
}
