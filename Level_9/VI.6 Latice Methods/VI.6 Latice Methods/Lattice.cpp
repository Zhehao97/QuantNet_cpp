//
//  Lattice.cpp
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



/* Lattice Method (Binomial)
        Vec1 Vec2 Vec3 Vec4 Vec5 Vec6
 Array:  -    -    -    -    -    -
              -    -    -    -    -
                   -    -    -    -
                        -    -    -
                             -    -
                                  -
    just like a Pyrmaid
 */


#ifndef Lattice_cpp
#define Lattice_cpp

#include "Lattice.hpp"

// Constructors and Destructor
template <typename T, typename I, int SubNodes> Lattice<T, I, SubNodes>::Lattice(){
    
    tree = Array<Vector<T, I>, I> (1, 1);       // A flat matrix with 1 row in array; start idx = 1
    tree[1] = Vector<T, I> (1, 1);              // Start index = 1
    subnodes = 2;                               // Binomial method
}

template <typename T, typename I, int SubNodes> Lattice<T, I, SubNodes>::Lattice(const I & Nsteps){
    
    nsteps = Nsteps;
    subnodes = SubNodes;                          // Numbre of child nodes comes from parent node
    tree = Array<Vector<T, I>, I> (Nsteps + 1, 1);   // Start index = 1; Array -> row_vector, Vector -> col_vector
    
    I currentBranch = 1;        // Thre is always one single root, i.e. the length of Vector in Array[1]
    
    // Initialize tree vectors (give sizes of vectors)
    for (int m = tree.MinIndex(); m <= tree.MaxIndex(); m++) {
        
        tree[m] = Vector<T, I> (currentBranch, 1);
        // size = currentBranch, start = 1
        
        // Calculate the next number of columns
        currentBranch += (subnodes - 1);
    }
}

template <typename T, typename I, int SubNodes> Lattice<T, I, SubNodes>::Lattice(const I & Nsteps, const T & val){
    
    nsteps = Nsteps;
    subnodes = SubNodes;
    
    tree = Array<Vector<T, I>, I> (Nsteps + 1, 1, val);
    
    I currentBranch = 1;
    
    for (int m = tree.MinIndex(); m <= tree.MaxIndex(); m++) {
        
        tree[m] = Vector<T, I> (currentBranch, 1, val);
        
        currentBranch += (subnodes - 1);
    }
}

template <typename T, typename I, int SubNodes> Lattice<T, I, SubNodes>::Lattice(const Lattice<T, I, SubNodes> & source){

    subnodes = source.typ;
    nsteps = source.nsteps;
    tree = source.tree;
}

template <typename T, typename I, int SubNodes> Lattice<T, I, SubNodes>::~Lattice(){
    // Destructor
}


// Operators
template <typename T, typename I, int SubNodes> Lattice<T, I, SubNodes> & Lattice<T, I, SubNodes>::operator = (const Lattice<T, I, SubNodes> & source){
    
    if (this == &source) {
        return *this;
    }
    subnodes = source.subnodes;
    nsteps = source.nsteps;
    tree = source.tree;
    
    return *this;
}

template <typename T, typename I, int SubNodes> Vector<T, I> & Lattice<T, I, SubNodes>::operator [] (const I & nLevel){
    
    return  tree[nLevel];
}

template <typename T, typename I, int SubNodes> const Vector<T, I> & Lattice<T, I, SubNodes>::operator [] (const I & nLevel) const{
    
    return  tree[nLevel];
}

// Accessors
template <typename T, typename I, int SubNodes> I Lattice<T, I, SubNodes>::MinIndex() const{
    
    return tree.MinIndex();
}

template <typename T, typename I, int SubNodes> I Lattice<T, I, SubNodes>::MaxIndex() const{
    
    return tree.MaxIndex();
}

template <typename T, typename I, int SubNodes> I Lattice<T, I, SubNodes>::Depth() const{
    
    return tree.Size();
}

template <typename T, typename I, int SubNodes> I Lattice<T, I, SubNodes>::NumNodes() const{
    
    double tmp = double( nsteps * (nsteps + 1) ) / 2.0;
    return 1 + nsteps + (subnodes - 1) * I(tmp);
}

template <typename T, typename I, int SubNodes> I Lattice<T, I, SubNodes>::BasePyramidSize() const{
    
    // return the length of vector of last step
    return 1 + nsteps * (subnodes - 1);
}

template <typename T, typename I, int SubNodes> Vector<T, I> Lattice<T, I, SubNodes>::BasePyramidVector() const{
    
    // return the vector of last step
    return tree[tree.MaxIndex()];
}

#endif
