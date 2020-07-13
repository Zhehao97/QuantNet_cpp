//
//  main.cpp
//  Exercise 4
//
//  Created by Zhehao Li on 2020/4/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Exercise 4 Random Number Generation

#include "boost/random.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <map>

int main(int argc, const char * argv[]) {
    
    /* Throwing Dice */
    
    /* Create a uniform generator */
    boost::random::mt19937 myRng;                               // Mersenne Twister RNG
    myRng.seed(static_cast<boost::uint32_t> (std::time(0)));    // Set the seed
    boost::random::uniform_int_distribution<int> sixGen(1, 6);  // Uniform Dstn in range [1,6]
    
    /* Record the outcomes */
    std::map<int, long> statistics;         // Structure to hold outcome + frequencies
    int outcome;                            // Current outcome

    outcome = sixGen(myRng);                // Return an outcome
    std::cout << outcome << std::endl;
    
    /* Sampling */
    std::cout << "How many trials?" << std::endl;
    long N_trials;
    std::cin >> N_trials;
    
    for (int i = 0; i < N_trials; i++) {
        outcome = sixGen(myRng);                // Return an outcome
        statistics[outcome] ++;                 // Record the outcome
    }
    
    /* Print the sampling result */
    std::cout.precision(4);                     // Set decimal precision
    std::cout << std::fixed;                    // Fixed precision
    std::cout << "Trial 1 has " << 100.0 * statistics[1] / N_trials << "% outcomes" << std::endl;
    std::cout << "Trial 2 has " << 100.0 * statistics[2] / N_trials << "% outcomes" << std::endl;
    std::cout << "Trial 3 has " << 100.0 * statistics[3] / N_trials << "% outcomes" << std::endl;
    std::cout << "Trial 4 has " << 100.0 * statistics[4] / N_trials << "% outcomes" << std::endl;
    std::cout << "Trial 5 has " << 100.0 * statistics[5] / N_trials << "% outcomes" << std::endl;
    std::cout << "Trial 6 has " << 100.0 * statistics[6] / N_trials << "% outcomes" << std::endl;
    
    return 0;
}
