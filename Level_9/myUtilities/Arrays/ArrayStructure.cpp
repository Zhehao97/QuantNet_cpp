//
//  ArrayStructure.cpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/15.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef ArrayStructure_cpp
#define ArrayStructure_cpp

#include "ArrayStructure.hpp"

// Default constructor
template <typename T> ArrayStructure<T>::ArrayStructure() {}

// Copy constructor
template <typename T> ArrayStructure<T>::ArrayStructure(const ArrayStructure<T> & source) {}

// Destructor
template <typename T> ArrayStructure<T>::~ArrayStructure() {}

// Indexing operator (modification): pure virtual memeber function

// Indexing operator (accessing): pure virtual memeber function

// Assignment operator
template <typename T> ArrayStructure<T> & ArrayStructure<T>::operator = (const ArrayStructure<T> & source){
    return *this;
}

// Element modifier
template <typename T> void ArrayStructure<T>::Element(std::size_t index, const T & val){
    (*this)[index] = val;
}

// Element accessor
template <typename T> const T & ArrayStructure<T>::Element(std::size_t index) const{
    return (*this)[index];
}

// Size of array accessor: pure virtual memeber function

// Min element accessor
template <typename T> std::size_t ArrayStructure<T>::MinIndex() const{
    return 1;
}

// Max element accessor
template <typename T> std::size_t ArrayStructure<T>::MaxIndex() const{
    return Size();
}

#endif
