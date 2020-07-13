//
//  FDMDirector.hpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/18.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The class that drives the whole FDM process. It mediates between the Mesh generation class and the FDM class.

#ifndef FDMDirector_hpp
#define FDMDirector_hpp

#include "Mesher.hpp"
#include "FDM.hpp"

class FDMDirector{
    
private:
    
    double dt;                  // time interval
    long NS;                    // Steps of price
    long NT;                    // Steps of time
    double Smax;                // Max value of price along price axis
    double Tmax;                // Max value of time along time axis
    double t_prev, t_next;      // Time points
    FDM fdm;                    // Finite Difference Method Obj
    
public:
    std::vector<double> sarr;   // Mesh array in Price Space
    std::vector<double> tarr;   // Mesh array in Time Space
    
    // Constructors ---------------------------------------------------
    // Default constructor
    FDMDirector(){
        //
    }
    
    // Constructor with arguments
    FDMDirector(double SM, double TM, double ns, double nt, std::string optionType){
        
        // Initialize base value
        Smax = SM;
        Tmax = TM;
        NS   = ns;
        NT   = nt;
        fdm = FDM(optionType);
        
        // Create meshes in price space and time space
        Mesher mx(0.0, Smax);               // Min index = 0; Max index = Smax
        sarr = mx.Xarr(ns);                 // Arraya with ns steps

        Mesher mt(0.0, Tmax);               // Min index = 0; Max index = Tmax
        tarr = mt.Xarr(nt);                 // Array with nt steps
        
        start();
    }
    
    // Copy constructor ------------------------------------------------
    FDMDirector(const FDMDirector & source){
        dt = source.dt;
        NS = source.NS;
        NT = source.NT;
        Smax = source.Smax;
        Tmax = source.Tmax;
        t_prev = source.t_prev;
        t_next = source.t_next;
        fdm = source.fdm;
        
        sarr = source.sarr;
        tarr = source.tarr;
    }
    
    // Destructor
    ~FDMDirector(){
        //
    }
    
    // Modifiers
    void start(){
        // Steps 1, 2: Get stuff from Mesher
        dt = Tmax/NT;
        t_prev = t_next = 0.0;
        
        // Step 3: Update new mesh array in FDM scheme
        fdm.initIC(sarr);
    }
    
    void doIt(){
        // Step 4, 5: Get new coefficient arrays + solve
        for (unsigned int n = 1; n < tarr.size(); ++n){
            t_next = tarr[n];                           // n + 1
            fdm.computeCoef(sarr, t_prev, t_next);      // Solve the coefs at time n + 1
            fdm.solveExplicit(t_next);                  // Compute the price array at time n + 1
            t_prev = t_next;                            // n becomes n+1
        }
    }
    
    void setType(std::string optionType){
        fdm.optType = optionType;
    }
    
    // Accessors
    const std::vector<double> & current() const{
        return fdm.current();
    }

    
};

#endif /* FDMDirector_hpp */
