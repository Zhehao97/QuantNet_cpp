//
//  FullArray.cpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/15.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Template class for a full (non-sparse) arrays.


#ifndef FullArray_cpp
#define FullArray_cpp

#include "FullArray.hpp"

// Default constructor
template<typename T, typename TA> FullArray<T, TA>::FullArray(): ArrayStructure<T>() {
    m_vector = std::vector<T, TA>(1);               // vector obj with size = 1
}


// Constructor with size
template<typename T, typename TA> FullArray<T, TA>::FullArray(std::size_t size): ArrayStructure<T>() {
    m_vector = std::vector<T, TA>(size);
}


// Copy constructor
template<typename T, typename TA> FullArray<T, TA>::FullArray(const FullArray<T, TA> & source): ArrayStructure<T>(source) {
    m_vector = source.m_vector;
}


// Destructor
template<typename T, typename TA> FullArray<T, TA>::~FullArray() {}


// Indexing operator (modification)
template<typename T, typename TA> T & FullArray<T, TA>::operator [] (std::size_t index) {
    return m_vector[index - 1];                     // index start from 1
}


// Indexing operator (accessing)
template<typename T, typename TA> const T & FullArray<T, TA>::operator [] (std::size_t index) const {
    return m_vector[index - 1];
}


// Assignment operator
template<typename T, typename TA> FullArray<T, TA> & FullArray<T, TA>::operator = (const FullArray<T, TA> & source){
    if (this == &source) {
        return *this;
    }
    ArrayStructure<T>::operator=(source);           // call basee class constructor
    m_vector = source.m_vector;                     // copy to the embeded vector
    return *this;
}

#endif
