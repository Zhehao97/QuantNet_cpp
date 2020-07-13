//
//  Lattice.hpp
//  VI.6 Latice Methods
//
//  Created by Zhehao Li on 2020/5/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Class respresenting a special kind of tree-like matrix that is needed in specific applications, for example binomial and trinomial methods in options pricing.
//
//  This structure can be used in other applications, such as computer graphics and interpolation schemes.
//
//  The matrix is 'expanding' in the form of a lattice; we must define a function that states how many elements to create in moving from step 'n' to step 'n+1'. The lattice is recombining or reconnecting as is usual in some applications.
//
//  This class is a basic data structure that can be used in other classes using composition or inheritance.


#ifndef Lattice_hpp
#define Lattice_hpp

#include "Array.hpp"
#include "Vector.hpp"

// Generic lattice class
template <typename T, typename I, int SubNodes> class Lattice{
    
private:
    // Implement as a full nested Vector class
    Array<Vector<T, I>, I> tree;
    
    // Redundant data
    I nsteps;               // Number of steps (depth of tree)
    int subnodes;           // What kind of lattice (2 == binomial, 3 == trinmoial)
    
public:
    // Constructors and Destructor
    Lattice();                                          // Default constructor
    Lattice(const I & Nsteps);                          // Constructor with number of rows
    Lattice(const I & Nsteps, const T & val);           // Constructor with num of rows + value at nodes
    Lattice(const Lattice<T, I, SubNodes> & source);    // Copy constructor
    virtual ~Lattice();
    
    // Operators
    Lattice<T, I, SubNodes> & operator = (const Lattice<T, I, SubNodes> & source);    // Copy constructor
    Vector<T, I> & operator [] (const I & nLevel);                              // Subscripting operator (modification)
    const Vector<T, I>  & operator [] (const I & nLevel) const;             // Subscripting operator (accessing)
    
    
    // Accessors
    // Iterating in a Lattice; we need forard and backward versions
    I MinIndex() const;                                 // Return the min row index
    I MaxIndex() const;                                 // Return the max row index
    I Depth() const;                                    // The depth of rows in the lattice
    // We need the form of the lattice at the 'base' of the pyramid. Will be needed when we use backward induction
    I NumNodes() const;                                 // Total numbeer of mesh points
    I BasePyramidSize() const;                          // The number of diiscretee poiints at end
    Vector<T, I> BasePyramidVector() const;
    
};

#ifndef Lattice_cpp
#include "Lattice.cpp"
#endif

#endif /* Lattice_hpp */
