//
//  BinomialMethod.cpp
//  VI.6 Latice Methods
//
//  Created by Zhehao Li on 2020/5/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  An encapsulation of the Binomial Method. This is a kind of Mediator between the underlying data stucture (a lattice tree) and the different kinds of algorithms (e.g. CRR) for initialising the tree.
//
//  It also plays the role of a Builder pattern because it creates data and objects on behalf of clients.
//

#ifndef BinomialMethod_cpp
#define BinomialMethod_cpp

#include "BinomialMethod.hpp"

// Constructors and Destructor
BinomialMethod::BinomialMethod(){
    //
}

BinomialMethod::BinomialMethod(int N, double discount, BinomialLatticeStrategy & strategy){
    
    disc = discount;
    stra = &strategy;           // dereference
    buildLattice(N);            // N timestep?
}

BinomialMethod::BinomialMethod(const BinomialMethod & source){
    
    lattice = source.lattice;
    stra = source.stra;
    disc = source.disc;
}

BinomialMethod::~BinomialMethod(){
    //
}


// Modifiers
// Initialise lattiice data structure
void BinomialMethod::buildLattice(int N){
    
    lattice = Lattice<double, int, 2> (N, 0.0); // value == 0.0
}

// Initialise lattice nodes values (Forward induction)
void BinomialMethod::modifyLattice(double val){
    
    double up = stra->upValue();
    double dn = stra->downValue();
    int sidx = lattice.MinIndex();          // start index
    lattice[sidx][lattice[sidx].MinIndex()] = val;      // Root value
    
    // Loop from 2nd index to the end index
    for (int j = sidx + 1; j <= lattice.MaxIndex(); j++) {
        
        // Loop from 1st index to the end
        for (int i = lattice[j].MinIndex(); i <= lattice[j].MaxIndex(); i++) {
            
            lattice[j][i] = dn * lattice[j-1][i];
            lattice[j][i+1] = up * lattice[j-1][i];
        }
    }
    // Postcondition: we now have the complete lattice for the underlying asset
}

// Calculate dervative price (Backward induction)
double BinomialMethod::getPrice(const Vector<double, int> & RHS){
    
    double p = stra->probValue();
    int eidx = lattice.MaxIndex();          // end index
    lattice[eidx] = RHS;
    
    // Loop from the max index to the start
    for (int j = eidx - 1; j >= lattice.MinIndex(); j--) {
        
        // Loop from start index to end
        for (int i = lattice[j].MinIndex(); i <= lattice[j].MaxIndex(); i++) {
            
            lattice[j][i] = disc * (p * lattice[j+1][i+1] + (1.0 - p) * lattice[j+1][i]);
        }
    }

    int sidx = lattice.MinIndex();          // start index
    return lattice[sidx][lattice[sidx].MinIndex()];
}

// Accessors
// Handy function to give us the size at expiry date
Vector<double, int> BinomialMethod::BasePyramidVector() const{
    
    return lattice.BasePyramidVector();
}

// Underlying lattice
const Lattice<double, int, 2> & BinomialMethod::getLattice() const{
    
    return lattice;
}

#endif
