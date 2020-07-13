//
//  Array.cpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/15.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Array class. It uses an ArrayStructure for the actual storage. This class acts like a kind of adapter class since it defines a common interface for different array structures like normal full arrays and sparse arrays. The array structure to use is given as template argument.

#ifndef Array_cpp
#define Array_cpp

#include "Array.hpp"

// default constructor
template <typename T, typename I, typename S> Array<T, I, S>::Array(){
    m_structure = S();
    m_start = 1;
}


// constructor with size
template <typename T, typename I, typename S> Array<T, I, S>::Array(I size){
    m_structure = S(std::size_t(size));
    m_start = 1;
}


// constructor with size and start
template <typename T, typename I, typename S> Array<T, I, S>::Array(I size, I start){
    m_structure = S(std::size_t(size));
    m_start = start;
}


// constructor with size, start and value
template <typename T, typename I, typename S> Array<T, I, S>::Array(I size, I start, const T & value){
    m_structure = S(std::size_t(size));
    m_start = start;
    
    for (I i = MinIndex(); i <= MaxIndex(); i++) {
        (*this)[i] = value;
    }
}


// copy constructor
template <typename T, typename I, typename S> Array<T, I, S>::Array(const Array<T, I, S> &  source){
    m_structure = source.m_structure;
    m_start = source.m_start;
}


// destructor
template <typename T, typename I, typename S> Array<T, I, S>::~Array(){
    //
}


// subscripting operator (modification)
template <typename T, typename I, typename S> T & Array<T, I, S>::operator [] (I index){
    return m_structure[index - m_start + 1];
}

// subscripting operator (accessing)
template <typename T, typename I, typename S> const T & Array<T, I, S>::operator [] (I index) const{
    return m_structure[index - m_start + 1];
}

// assignment operator
template <typename T, typename I, typename S> Array<T, I, S> & Array<T, I, S>::operator = (const Array<T, I, S> & source){
    if (this == &source) {
        return *this;
    }
    m_structure = source.m_structure;
    m_start = source.m_start;
    
    return *this;
}

// return min index
template <typename T, typename I, typename S> I Array<T, I, S>::MinIndex() const{
    return m_start;
}

// return max index
template <typename T, typename I, typename S> I Array<T, I, S>::MaxIndex() const{
    return m_start + Size() - 1;
}

// return size
template <typename T, typename I, typename S> I Array<T, I, S>::Size() const{
    return I( m_structure.Size() );
}


#endif /* Array_cpp */
