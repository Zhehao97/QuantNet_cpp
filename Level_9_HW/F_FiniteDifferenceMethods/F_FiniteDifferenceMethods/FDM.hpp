//
//  FDM.hpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/18.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  FDM scheme for one factor Black Scholes equation. For the moment we assume explicit Euler.


#ifndef FDM_hpp
#define FDM_hpp

#include "ParabolicPDE.hpp"
#include <iostream>
#include <vector>

class FDM{
    
public:
    // Member data
    std::string optType = "C";                  // Option type, call or put
    std::vector<double> a, b, c;                // LHS coeffiicients at level n + 1
    std::vector<double> RHS;                    // Inhomeegenous term
    
    std::vector<double> vecPrev;                // Solution at time t = n + 1
    std::vector<double> vecNext;                // Soltuion at time t = n
    
    // Constructors ----------------------------------------------------
    // Default constructor
    FDM(){
        
    }
    
    // Constructor with option type
    FDM(std::string optionType){
        optType = optionType;
    }
    
    // Copy constructor
    FDM(const FDM & source): optType(source.optType), a(source.a), b(source.b), c(source.c), RHS(source.RHS), vecPrev(source.vecPrev), vecNext(source.vecNext){
        //
    }
    
    // Destructor -----------------------------------------------------
    ~FDM(){
        //
    }
    
    // Operators -------------------------------------------------------
    // Assignment operator
    FDM & operator = (const FDM & source){
        
        if (this == &source) {
            return *this;
        }
        optType = source.optType;
        a = source.a;
        b = source.b;
        c = source.c;
        RHS = source.RHS;
        vecPrev = source.vecPrev;
        vecNext = source.vecNext;
        
        return *this;
    }
    
    // Modifiers -------------------------------------------------------
    // Inialize
    void initIC(const std::vector<double> & xarr){
        // Initialise the solutin at time zero. This occurs only at the interior mesh points of xarr (and there are J-1 of them)
        
        unsigned long N = xarr.size();
        vecPrev = std::vector<double>(N);
        
        // Firstly, intialise at the boudaries
        vecPrev[0]     = ParabolicIBVP::BCL(0.0, optType);       // Boundary condtition at the bottom of matrix, S = 0
        vecPrev[N - 1] = ParabolicIBVP::BCR(0.0, optType);       // Boundary condtition at the top of matrix, S = Smax
        
        // Now, initalise values in interior of interval using the initial function 'IC' (a function pointer) from the PDE
        for (unsigned long j = 1; j < N - 1; j++) {
            vecPrev[j] = ParabolicIBVP::IC(xarr[j], optType);
        }
        vecNext = vecPrev;
    }
    
    // Compute the coefficient
    void computeCoef(const std::vector<double> & xarr, double t_prev, double t_now){
        
        a = std::vector<double> (xarr.size() - 2);
        b = std::vector<double> (xarr.size() - 2);
        c = std::vector<double> (xarr.size() - 2);
        RHS = std::vector<double> (xarr.size() - 2);
        
        double tmp1, tmp2;
        double k = t_now - t_prev;
        double h = xarr[1] - xarr[0];
        
        for (unsigned int j = 1; j < xarr.size() - 1; j++) {
            
            tmp1 = k * ParabolicIBVP::sigma(xarr[j], t_prev) / (h * h);
            tmp2 = k * ParabolicIBVP::mu(xarr[j], t_prev) * 0.5 / h;

            a[j-1] = tmp1 - tmp2;
            b[j-1] = 1.0 - (2.0 * tmp1)
                   + k * ParabolicIBVP::bb(xarr[j], t_prev);
            c[j-1] = tmp1 + tmp2;
            RHS[j-1] = k * ParabolicIBVP::ff(xarr[j], t_prev);
        }
    }
    
    // Solve with explicit method
    void solveExplicit(double t_now){
        // Boundary condition
        vecNext[0] = ParabolicIBVP::BCL(t_now, optType);
        vecNext[vecNext.size() - 1] = ParabolicIBVP::BCR(t_now, optType);
        
        for (unsigned int i = 1; i < vecNext.size() - 1; i++) {
            
            vecNext[i] = a[i-1] * vecPrev[i-1]
                        + b[i-1] * vecPrev[i]
                        + c[i-1] * vecPrev[i+1]
                        - RHS[i-1];
        }
        vecPrev = vecNext;
    }
    
    // Accessors
    const std::vector<double> & current() const{
        
        return vecNext;
    }
    
};

#endif /* FDM_hpp */
