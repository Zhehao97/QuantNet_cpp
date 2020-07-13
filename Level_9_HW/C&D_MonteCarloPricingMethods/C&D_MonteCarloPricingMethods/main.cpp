//
//  main.cpp
//  C&D_MonteCarloPricingMethods
//
//  Created by Zhehao Li on 2020/5/26.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test for Monte Carlo Simulation on option pricing

#include "OptionData/OptionData.hpp"
#include "myUtilities/RandomNumberGenerator/NormalGenerator.hpp"
#include "myUtilities/Geometry/Range.hpp"
#include <cmath>
#include <iostream>


// Template array print function
template <typename Type> void print(const std::vector<Type> & myList){
    
    std::cout << std::endl << "Size of vector is " << myList.size() << "\n[";

    typename std::vector<Type>::const_iterator it;
    for (it = myList.begin(); it != myList.end(); it++){
            std::cout << *it << ",";
    }
    std::cout << "]\n";
}


// Standard Deviation
double stdDeviation(std::vector<double> priceArr, double r, double T){
    
    double Sum = 0.0;
    double squareSum = 0.0;
    unsigned long M = priceArr.size();
    
    for (unsigned long i = 0; i < M; i++) {
        Sum += priceArr[i];
        squareSum += priceArr[i] * priceArr[i];
    }
    return sqrt((squareSum - Sum * Sum / M) / M) * exp(- r * T);
}


// Standard Error
double stdError(std::vector<double> priceArr, double r, double T){
    
    unsigned long M = priceArr.size();
    return stdDeviation(priceArr, r, T) / sqrt(M);
}





int main(int argc, const char * argv[]) {
    
    /* C. Monte Carlo 101 */
    
    // C-(a). Compile and run the program
    // C-(b) & (c). Test the data from batches 1 and 2, and compared with exact solution

    /* D. Advanced Monte Carlo */
    
    //    Batch 1: T = 0.25, K = 65, sig = 0.30, r = 0.08, S = 60 (C = 2.13337, P = 5.84628)
    //    Batch 2: T = 1.0, K = 100, sig = 0.20, r = 0.0, S = 100 (C = 7.96557, P = 7.96557)
    //    Batch 3: T = 1.0, K = 10, sig = 0.50, r = 0.12, S = 5 (C = 0.204058, P = 4.07326)
    //    Batch 4: T = 30.0, K = 100.0, sig = 0.30, r = 0.08, S = 100.0 (C = 92.17570, P = 1.24750)
        

    // 1.1. Initialize the basic parameters of option
    std::cout << "One factor MC with explicit Euler\n";
    OptionData myOption;
    myOption.K = 120.0;
    myOption.T = 1.5;
    myOption.r = 0.04;
    myOption.sigma = 0.40;
    myOption.type = 1;
    
    double S_0 = 100.0;
    
    // 1.2. Initialize the number of time steps and simulations
    long Nt = 100;
    std::cout << "Number of subintervals in time: ";
    std::cin >> Nt;
    
    long NSim = 5000;
    std::cout << "Number of simulations: ";
    std::cin >> NSim;
    

    // 1.3. Create mesh array for time step
    Range<double> range (0.0, myOption.T);
    std::vector<double> tArr = range.mesh(Nt);

    // 1.4 Initialize Normal Generator
    NormalGenerator * myNormal = new BoostNormalGenerator();
    
    int count = 0;                              // Number of times S hits origin
    double dt = myOption.T / double (Nt);       // Time Step
    
    double callPrice = 0.0;                     // Call price
    double callSDE = 0.0;                       // Call standard deviation
    double callSE = 0.0;                        // Call standard error
    
    double putPrice = 0.0;                      // Put price
    double putSDE = 0.0;                        // Put standard deviation
    double putSE = 0.0;                         // Put standard error
    
    std::vector<double> call_Vec;               // Call price at time T of each simulations
    std::vector<double> put_Vec;                // Put price at time T of each simulations
    
    // Main Loop
    for (unsigned long i = 1; i < NSim; ++i)
    { // Calculate a path at each iteration
            
        if ((i/10000) * 10000 == i){
            // Give status after each 1000th iteration
            std::cout << i << std::endl;
        }

        double S_old = S_0;
        double S_new = S_0;
        
        for (unsigned long index = 1; index < tArr.size(); ++index){

            // Create a random number
            double z = myNormal->getNormal();
            
            // 2. Compute the stock price at t, using FDM (Explicit Euler)
            S_new = S_old   + (myOption.drift(tArr[index-1], S_old) * dt)
                            + (myOption.diffusion(tArr[index-1], S_old) * z * sqrt(dt));
            S_old = S_new;

            // Spurious values
            if (S_new <= 0.0) count++;
        }
        // 3. Calculate the option Price, SDE and SEat t = T
        myOption.type = 1;      // Call
        double tmp1 = myOption.myPayoff(S_new);
        
        myOption.type = -1;     // Put
        double tmp2 = myOption.myPayoff(S_new);
        
        // 3.1 Record the option price at t = T of each simulations
        call_Vec.push_back(tmp1);
        put_Vec.push_back(tmp2);
        
        // 4. Calculate the average option price, standard deviation and standard error at t = T
        callPrice += (tmp1) / double(NSim);
        callSDE = stdDeviation(call_Vec, myOption.r, myOption.T);
        callSE  = stdError(call_Vec, myOption.r, myOption.T);
        
        putPrice  += (tmp2) / double(NSim);
        putSDE = stdDeviation(put_Vec, myOption.r, myOption.T);
        putSE  = stdError(put_Vec, myOption.r, myOption.T);

    }
    
    // 5. Discounting the average price (t = 0)
    callPrice *= exp(-myOption.r * myOption.T);
    putPrice  *= exp(-myOption.r * myOption.T);
    
    std::cout << "Number of times origin is hit: " << count << std::endl;
    
    std::cout << "Call Price, after discounting: " << callPrice << "\n";
    std::cout << "Call option standard deviation: " << callSDE << "\n";
    std::cout << "Call option stadnard error: " << callSE << "\n\n";
    
    std::cout << "Put Price, after discounting: " << putPrice << "\n";
    std::cout << "Put option standard deviation: " << putSDE << "\n";
    std::cout << "Put option stadnard error: " << putSE << "\n\n";
    
//    print(call_Vec);
//    print(put_Vec);
    
    return 0;
}

