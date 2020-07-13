//
//  ParabolicPDE.hpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/18.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Namespace containing the function pointers and data that represent the defining parameters of the initial boundary value problem for the 1 factor Black Scholes PDE.

#ifndef ParabolicPDE_hpp
#define ParabolicPDE_hpp

namespace ParabolicIBVP{

    // Coefficients of PDE equation
    double (*sigma)(double x, double t);    // Diffusion term
    double (*mu)(double x, double t);       // Convection term
    double (*bb)(double x, double t);       // Free term
    double (*ff)(double x, double t);       // The forcing term term

    // (Dirichlet) boundary conditions
    double (*BCL)(double t);                // The left-hand boundary condition
    double (*BCR)(double t);                // The right-hand boundary condition

    // Initial condition
    double (*IC)(double x);                 // The condition at time t = 0
}

#endif /* ParabolicPDE_hpp */
