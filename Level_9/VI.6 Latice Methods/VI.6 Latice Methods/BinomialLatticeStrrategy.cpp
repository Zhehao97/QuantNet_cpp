//
//  BinomialLatticeStrrategy.cpp
//  VI.6 Latice Methods
//
//  Created by Zhehao Li on 2020/5/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef BinomialLatticeStrrategy_cpp
#define BinomialLatticeStrrategy_cpp

#include "BinomialLatticeStrrategy.hpp"
#include <iostream>


// BinomialLatticeStrategy --------------------------
// Constructor
BinomialLatticeStrategy::BinomialLatticeStrategy(double interest, double vol, double deltaT){
    
    r = interest;
    v = vol;
    dt = deltaT;
    bType = Multiplicative;
}

// Modifiers
void BinomialLatticeStrategy::updateLattice(Lattice<double, int, 2> & source, double rootValue) const{
    // Find the depth of the lattice; this a Template Method Pattern
    int idx = source.MinIndex();        // index start from 1
    source[idx][source[idx].MinIndex()] = rootValue;
    
    // Loop from the 2nd index to the end index
    for (int i = source.MinIndex() + 1; i <= source.MaxIndex(); i++) {
        // Loop from the 1st index to the end
        for (int j = source[i].MinIndex(); j <= source[i].MaxIndex(); j++) {
            
            source[i][j] = d * source[i-1][j];      // price go down
            source[i][j+1] = u * source[i-1][j];    // price go up
        }
    }
}

// CoxRossRubinStrategy -----------------------------
CoxRossRubinStrategy::CoxRossRubinStrategy(double interest, double vol, double deltaT): BinomialLatticeStrategy(interest, vol, deltaT){
    
    double R1 = (r - 0.5 * vol * vol) * deltaT;
    double R2 = vol * sqrt(deltaT);
    
    p = 0.5;
    u = exp(R1 + R2);
    d = exp(R1 - R2);
    
    std::cout << "U, D, p:" << u << "," << d << "," << p << std::endl;
}

// PadeCRR ------------------------------------------
PadeCRRStrategy::PadeCRRStrategy(double interest, double vol, double deltaT): BinomialLatticeStrategy(interest, vol, deltaT){
    
    double R1 = (r - 0.5 * vol * vol) * deltaT;
    double R2 = vol * sqrt(deltaT);
    
    // Carley transform
    double z1 = (R1 + R2);
    double z2 = (R1 - R2);
    
    p = 0.5;
    u = (2.0 + z1) / (2.0 - z1);
    d = (2.0 + z2) / (2.0 - z2);
    
    std::cout << "U, D, p:" << u << "," << d << "," << p << std::endl;
}

// ModCRR ------------------------------------------
ModCRRStrategy::ModCRRStrategy(double interest, double vol, double deltaT, double S, double K, int N): BinomialLatticeStrategy(interest, vol, deltaT){
    
    double KN = log(K / S) / double(N);
    double VN = vol * sqrt(deltaT);
    
    u = exp(KN + VN);
    d = exp(KN - VN);
    p = (exp(r * dt) - d) / (u - d);
    
    std::cout << "U, D, p:" << u << "," << d << "," << p << std::endl;
}

// JarrowRudd ---------------------------------------
JarrowRuddStrategy::JarrowRuddStrategy(double interest, double vol, double deltaT): BinomialLatticeStrategy(interest, vol, deltaT){
    
    u = exp(vol * dt * dt);
    d = 1.0 / u;
    p = 0.5 + 0.5 * (r - 0.5 * vol * vol) * dt * dt / vol;
    
    std::cout << "U, D, p:" << u << "," << d << "," << p << std::endl;
    
}

// PadeJRR ------------------------------------------
PadeJRRStrategy::PadeJRRStrategy(double interest, double vol, double deltaT): BinomialLatticeStrategy(interest, vol, deltaT){
    
    double z = vol * sqrt(dt);
    double numer = 12.0 - (6.0 * z) + (z * z);
    double denom = 12.0 + (6.0 * z) + (z * z);
    
    u = denom/numer;
    d = numer/denom;
    p = 0.5 + 0.5 * (r - 0.5 * vol * vol) * dt * dt / vol;
    
    std::cout << "U, D, p:" << u << "," << d << "," << p << std::endl;
}

// EQP ----------------------------------------------
EQPStrategy::EQPStrategy(double interest, double vol, double deltaT): BinomialLatticeStrategy(interest, vol, deltaT){
    
    bType = Additive;
    
    // Needed for additive method: page 19 Clewlow/Strickland formula 2.17
    // "v" is "nu" here, for "v" see  page 19 formula 2.14
    double nu = r - 0.5 * vol * vol;
    double a = nu * dt;
    double b = 0.5 * sqrt(4.0 * vol * vol * dt) - (3.0 * nu * nu * dt * dt);
    
    // EQP parameters: page 19 formula 2.17
    u = 0.5 * a + b;
    d = 1.5 * a - b;
    p = 0.5;
    
    std::cout << "U, D, p:" << u << "," << d << "," << p << std::endl;
}


// TRG ----------------------------------------------
TRGStrategy::TRGStrategy(double interest, double vol, double deltaT): BinomialLatticeStrategy(interest, vol, deltaT){
    
    bType = Additive;
    double nu = r - 0.5 * vol * vol;
    double nudt = nu * dt;
    
    // TRG parameters: page 19 formula 2.19
    u = sqrt(vol * vol * dt + nudt * nudt);
    d = -u;
    p = 0.5 * (1.0 + nudt / u);
    
    std::cout << "U, D, p:" << u << "," << d << "," << p << std::endl;
}


#endif
