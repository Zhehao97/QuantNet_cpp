//
//  BinomialLatticeStrrategy.hpp
//  VI.6 Latice Methods
//
//  Created by Zhehao Li on 2020/5/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Strategy pattern for creating binomial lattice. Note that there is a built-in Template Method pattern built in here.

//  For convenience all data is public and all code is inline. Furthermore, classes have minimal functionality. We can make production code from this at a later stage.


#ifndef BinomialLatticeStrrategy_hpp
#define BinomialLatticeStrrategy_hpp

#include "Lattice.hpp"
#include <cmath>

// A enumeration class
enum BinomialType {Additive, Multiplicative};

class BinomialLatticeStrategy{
    
protected:
    double u;           // upward
    double d;           // downward
    double p;           // prob. of upward
    
    double r;           // interest rate
    double v;           // volatility
    double dt;          // time step

    BinomialType bType; // ??
    
    // Constructor
    BinomialLatticeStrategy(double interest, double vol, double deltaT);
    
public:
    // Modifiers
    virtual void updateLattice(Lattice<double, int, 2> & source, double rootValue) const;
    
    // Accessors
    // Public inline functions for nomral clients
    double upValue() const {return u;}
    double downValue() const {return d;}
    double probValue() const {return p;}
    BinomialType binomialType () const {return bType;}
    
};

// Method 1
class CoxRossRubinStrategy: public BinomialLatticeStrategy{
    
public:
    CoxRossRubinStrategy(double interest, double vol, double deltaT);
};


// Method 2
class PadeCRRStrategy: public BinomialLatticeStrategy{
    
public:
    PadeCRRStrategy(double interest, double vol, double deltaT);
};

// Method 3
class ModCRRStrategy: public BinomialLatticeStrategy{
    
public:
    ModCRRStrategy(double interest, double vol, double deltaT, double S, double K, int N);
};


// Method 4
class JarrowRuddStrategy: public BinomialLatticeStrategy{
    
public:
    JarrowRuddStrategy(double interest, double vol, double deltaT);
};


// Method 5
class PadeJRRStrategy: public BinomialLatticeStrategy{
    
public:
    PadeJRRStrategy(double interest, double vol, double deltaT);
};


// Method 6
class EQPStrategy: public BinomialLatticeStrategy{
    
public:
    EQPStrategy(double interest, double vol, double deltaT);
};


// Method 7
class TRGStrategy: public BinomialLatticeStrategy{
    
public:
    TRGStrategy(double interest, double vol, double deltaT);
};


#endif /* BinomialLatticeStrrategy_hpp */
