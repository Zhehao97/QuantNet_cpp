//
//  main.cpp
//  4 - RandomPI
//
//  Created by Zhehao Li on 2020/4/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "boost/limits.hpp"
#include "boost/random.hpp" // Convenience header file
#include <iostream>
#include <ctime>            // std::time
using namespace std;

int main(int argc, const char * argv[]) {
    
    // A. Define the Lagged-Fibonacci Enigne object and Normal Distribution objects
    boost::lagged_fibonacci607 rng;
    rng.seed(static_cast<boost::uint32_t> (std::time(0)));              // Datatype converted
    boost::uniform_real<> uni(0.0, 1.0);

    // B. Produce Uniform (0, 1)
    boost::variate_generator< boost::lagged_fibonacci607 &, boost::uniform_real<> > uniRng(rng, uni);

    // C. Choose the desired accuracy
    cout << "How many darts to throw? ";
    long N;
    cin >> N;

    // D. Thow the dart; does it fall in the circle or outside
    // Start throwing darts and count where they land
    long hits = 0;
    double x, y, distance;
    
    for (long n = 1; n <= N; ++n){
        x = uniRng();
        y = uniRng();
        distance = sqrt(x * x + y * y);

        if ( distance <= 1 ){
            hits++;
        }
    }

    //E.  Produce the answer
    cout << "Numbers of hits, PI is: " << hits << ", " << 4.0 * double(hits) / double (N) << endl;
            
    return 0;
}
