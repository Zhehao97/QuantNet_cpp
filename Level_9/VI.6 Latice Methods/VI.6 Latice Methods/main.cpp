//
//  main.cpp
//  VI.6 Latice Methods
//
//  Created by Zhehao Li on 2020/5/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Main program to run and test the Binomial method for a stock option. This code 'drives' the process as it were.


#include "Option.hpp"
#include "BinomialMethod.hpp"
#include "BinomialLatticeStrrategy.hpp"
#include "LatticeMechanisms.hpp"
#include "EuropeanOptionFactory.hpp"
#include <iostream>


EuropeanOptionFactory * getFactory(){
    
    return new ConsoleEuroOptionFactory;
}

BinomialLatticeStrategy * getStrategy(double r, double sig, double dt, double S, double K, double N){
    
    std::cout << "\n1. CRR, 2. JR, 3. TRG, 4. EQP, 5. Modified CRR \n6. Cayley JR Transform: 7 Cayley CRR: ";
    
    int choice;
    std::cin >> choice;
    
    if (choice == 1) {
        return new CoxRossRubinStrategy(r, sig ,dt);
    }
    if (choice == 2){
        return new JarrowRuddStrategy(r, sig, dt);
    }
    if (choice == 3){
        return new TRGStrategy(r, sig, dt);
    }
    if (choice == 4){
        return new EQPStrategy(r, sig, dt);
    }
    if (choice == 5){
        return new ModCRRStrategy(r, sig, dt, S, K, N);
    }
    if (choice == 6){
        return new PadeCRRStrategy(r, sig, dt);
    }
    if (choice == 7) {
        return new PadeCRRStrategy(r, sig, dt);
    }
    return 0;
}


int main(int argc, const char * argv[]) {
    
    // Phase I: Create and initialise the option
    // -----------------------------------------
    int N = 200;
    std::cout << "Number of steps: \n";
    std::cin >> N;
    
    double S = 200;
    std::cout << "Underlying value: \n";
    std::cin >> S;
    
    // Intialise the paramerters
    EuropeanOptionFactory * optFac = getFactory();
    Option * opt = optFac->create();
    delete optFac;
    
    // Compute the step size dt
    double dt = opt->T / double(N);
    std::cout << "Step size: " << dt << std::endl;
    
    // Compute the discounting factor
    double discount = exp(- opt->r * dt);
    std::cout << "Discounting factor: " << discount << std::endl;
    
    // Phase II: Create the binomial method and a lattice
    // --------------------------------------------------
    BinomialLatticeStrategy * stra = getStrategy(opt->r, opt->sig, dt, S, opt->K, N);
    BinomialMethod bm(N, discount, *stra);
    
    // Phase III: Forward Inductioin
    // -----------------------------
    bm.modifyLattice(S);
    
    print(bm.getLattice());
    
    // Phase IV: Backward Induction
    // ----------------------------
    Vector<double, int> RHS = bm.BasePyramidVector();   // The price vector at the last step N
    
    if (stra->binomialType() == Additive) {
        
        RHS[RHS.MinIndex()] = S * exp(N * stra->downValue());     // the lowest value
        
        for (int j = RHS.MinIndex() + 1; j <= RHS.MaxIndex(); j++) {
            
            RHS[j] = RHS[j-1] * exp(stra->upValue() - stra->downValue());
        }
    }
    
    // Compute the value of option at the last step N
    Vector<double, int> Pay = opt->payoffVector(RHS);
    
    // Get the value of option (price) at t = 0
    double Px = bm.getPrice(Pay);
    std::cout << "Price (N steps): " << Px << std::endl;
    
    print(bm.getLattice());
    
    // Finally..
    delete stra;
    delete opt;
    
    return 0;
}
