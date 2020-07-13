//
//  BinomialMethod.hpp
//  VI.6 Latice Methods
//
//  Created by Zhehao Li on 2020/5/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  An encapsulation of the Binomial Method. This is a kind of Mediator between the underlying data stucture (a lattice tree) and the different kinds of algorithms (e.g. CRR) for initialising the tree.
//
//  It also plays the role of a Builder pattern because it creates data and objects on behalf of clients.
//

#ifndef BinomialMethod_hpp
#define BinomialMethod_hpp


#include "BinomialLatticeStrrategy.hpp"
#include <iostream>

class BinomialMethod{

private:
    // Underlying data structure
    Lattice<double, int, 2> lattice;    // Magic number = 2 means binomial
    BinomialLatticeStrategy * stra;     // Pointer to an algorithm (class)
    double disc;                        // Discounting factor
    
public:
    // Constructors and Destructor
    BinomialMethod();
    BinomialMethod(int N, double discount, BinomialLatticeStrategy & strategy);
    BinomialMethod(const BinomialMethod & source);
    ~BinomialMethod();
    
    // Modifiers
    // Initialise lattice data structure
    void buildLattice(int N);
    
    // Initialise lattice nodes values (Forward Induction)
    void modifyLattice(double val);
    
    // Calculate derivative price (Backward Induction)
    double getPrice(const Vector<double, int> & RHS);
    
    
    // Accessors
    // Handy function to give us the size at expiry date
    Vector<double, int> BasePyramidVector() const;
    
    // Underlying lattice
    const Lattice<double, int, 2> & getLattice() const;
    
};


#endif /* BinomialMethod_hpp */
