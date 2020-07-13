//
//  MatrixStructure.cpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Base class for matrix storage structure.

#ifndef MatrixStructure_cpp
#define MatrixStructure_cpp

#include "MatrixStructure.hpp"

// Constructor ---------------------------------------------------------
// default constructor
template <typename Type> MatrixStructure<Type>::MatrixStructure(){
    //
}

// copy constructor
template <typename Type> MatrixStructure<Type>::MatrixStructure(const MatrixStructure<Type> & source){
    //
}


// Destructor ----------------------------------------------------------
template <typename Type> MatrixStructure<Type>::~MatrixStructure(){
    //
}

// Operators -----------------------------------------------------------
// assignment operator
template <typename Type> MatrixStructure<Type> & MatrixStructure<Type>::operator = (const MatrixStructure<Type> & source){

    return *this;
}

#endif
