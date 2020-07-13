//
//  Vector.cpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Vector class is an array wiith mathematical functions

#ifndef Vector_cpp
#define Vector_cpp

#include "Vector.hpp"

// Constructors -------------------------------------------------------
// default constructor
template<typename T, typename I, typename S> Vector<T, I, S>::Vector(): Array<T, I, S>() {
    // no data memeber
}

// constructor with size
template<typename T, typename I, typename S> Vector<T, I, S>::Vector(I size): Array<T, I, S>(size){
    // no data memeber
}

// constructor with size and start
template<typename T, typename I, typename S> Vector<T, I, S>::Vector(I size, I start): Array<T, I, S>(size, start){
    // no data memeber
}

// constructor with size, start and value
template<typename T, typename I, typename S> Vector<T, I, S>::Vector(I size, I start, const T & value): Array<T, I, S>(size, start, value){
    //
}

// copy constructor with vector as arguement
template<typename T, typename I, typename S> Vector<T, I, S>::Vector(const Vector<T, I, S> & source): Array<T, I, S>(source){
    // no data memeber
}

// copy constructor with array as arguement
template<typename T, typename I, typename S> Vector<T, I, S>::Vector(const Array<T, I, S> & source): Array<T, I, S>(source){
    // no data memeber
}


// Destructor ---------------------------------------------------------
template<typename T, typename I, typename S> Vector<T, I, S>::~Vector(){
    // no data member to destroy
}


// Element-wise operation ---------------------------------------------
// Unary minus
template<typename T, typename I, typename S> Vector<T, I, S> & Vector<T, I, S>::operator - () const{
    
    // create new vector of same size and same starting index
    Vector<T, I, S> result(Array<T, I, S>::Size(), Array<T, I, S>::MinIndex());
    
    // copy all elements negative
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MaxIndex(); i++) {
        result[i] = - (*this)[i];
    }
    return result;
}

// element-wise addition with saclar
template<typename T, typename I, typename S> Vector<T, I, S> Vector<T, I, S>::operator + (const T & a) const{
    
    Vector<T, I, S> result(Array<T, I, S>::Size(), Array<T, I, S>::MinIndex());
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        result[i] = (*this)[i] + a;
    }
    return result;
}

// element-wise subtraction with saclar
template<typename T, typename I, typename S> Vector<T, I, S> Vector<T, I, S>::operator - (const T & a) const{
    
    Vector<T, I, S> result(Array<T, I, S>::Size(), Array<T, I, S>::MinIndex());
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        result[i] = (*this)[i] - a;
    }
    return result;
}

// element-wise multipication with saclar
template<typename T, typename I, typename S> Vector<T, I, S> Vector<T, I, S>::operator * (const T & a) const{
    
    Vector<T, I, S> result(Array<T, I, S>::Size(), Array<T, I, S>::MinIndex());
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        result[i] = (*this)[i] * a;
    }
    return result;
}

// element-wise multipication with saclar
template<typename T, typename I, typename S> Vector<T, I, S> Vector<T, I, S>::operator / (const T & a) const{
    
    Vector<T, I, S> result(Array<T, I, S>::Size(), Array<T, I, S>::MinIndex());
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        result[i] = (*this)[i] / a;
    }
    return result;
}


// Vector operations ---------------------------------------------------
// vector addition with saclar
template<typename T, typename I, typename S> Vector<T, I, S> Vector<T, I, S>::operator + (const Vector<T, I, S> & vec) const{
    
    
    
    Vector<T, I, S> result(Array<T, I, S>::Size(), Array<T, I, S>::MinIndex());
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        result[i] = (*this)[i] + vec[i];
    }
    return result;
}

// vector subtraction with saclar
template<typename T, typename I, typename S> Vector<T, I, S> Vector<T, I, S>::operator - (const Vector<T, I, S> & vec) const{
    
    Vector<T, I, S> result(Array<T, I, S>::Size(), Array<T, I, S>::MinIndex());
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        result[i] = (*this)[i] - vec[i];
    }
    return result;
}

// vector multiplication with saclar
template<typename T, typename I, typename S> Vector<T, I, S> Vector<T, I, S>::operator * (const Vector<T, I, S> & vec) const{
    
    Vector<T, I, S> result(Array<T, I, S>::Size(), Array<T, I, S>::MinIndex());
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        result[i] = (*this)[i] * vec[i];
    }
    return result;
}


// Assignment operations with scalar ----------------------------------
// assignment addition
template <typename T, typename I, typename S> Vector<T, I, S> & Vector<T, I, S>::operator += (const T & a){
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        (*this)[i] = (*this)[i] + a;
    }
    return *this;
}

// assignment subtraction
template <typename T, typename I, typename S> Vector<T, I, S> & Vector<T, I, S>::operator -= (const T & a){
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        (*this)[i] = (*this)[i] - a;
    }
    return *this;
}

// assignment multiplication
template <typename T, typename I, typename S> Vector<T, I, S> & Vector<T, I, S>::operator *= (const T & a){
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        (*this)[i] = (*this)[i] * a;
    }
    return *this;
}

// assignment division
template <typename T, typename I, typename S> Vector<T, I, S> & Vector<T, I, S>::operator /= (const T & a){
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        (*this)[i] = (*this)[i] / a;
    }
    return *this;
}


// Assignment operations with vector ----------------------------------
// assignment operator
template <typename T, typename I, typename S> Vector<T, I, S> & Vector<T, I, S>::operator = (const Vector<T, I, S> & source){
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        (*this)[i] = source[i];
    }
    return *this;
}

// assignment addition
template <typename T, typename I, typename S> Vector<T, I, S> & Vector<T, I, S>::operator += (const Vector<T, I, S> & source){
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        (*this)[i] = (*this)[i] + source[i];
    }
    return *this;
}

// assignment subtraction
template <typename T, typename I, typename S> Vector<T, I, S> & Vector<T, I, S>::operator -= (const Vector<T, I, S> & source){
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        (*this)[i] = (*this)[i] - source[i];
    }
    return *this;
}

// assignment multiplication
template <typename T, typename I, typename S> Vector<T, I, S> & Vector<T, I, S>::operator *= (const Vector<T, I, S> & source){
    
    for (I i = Array<T, I, S>::MinIndex(); i <= Array<T, I, S>::MinIndex(); i++) {
        (*this)[i] = (*this)[i] * source[i];
    }
    return *this;
}


// friend operations --------------------------------------------------
// addition 1
template<typename T, typename I, typename S> Vector<T, I, S> operator + (const Vector<T, I, S> & source, const T & a){
    
    Vector<T, I, S> result(source.Size(), source.MinIndex());
    
    for (I i = source.MinIndex(); i <= source.MaxIndex(); i++) {
        result[i] = source[i] + a;
    }
    return result;
}

// addition 2
template<typename T, typename I, typename S> Vector<T, I, S> operator + (const T & a, const Vector<T, I, S> & source){
    return source + a;
}

// subtration 1
template<typename T, typename I, typename S> Vector<T, I, S> operator - (const Vector<T, I, S> & source, const T & a){
    
    Vector<T, I, S> result(source.Size(), source.MinIndex());
    
    for (I i = source.MinIndex(); i <= source.MaxIndex(); i++) {
        result[i] = source[i] - a;
    }
    return result;
}

// subtration 2
template<typename T, typename I, typename S> Vector<T, I, S> operator - (const T & a, const Vector<T, I, S> & source){
    return source - a;
}

// multiplication 1
template<typename T, typename I, typename S> Vector<T, I, S> operator * (const Vector<T, I, S> & source, const T & a){
    
    Vector<T, I, S> result(source.Size(), source.MinIndex());
    
    for (I i = source.MinIndex(); i <= source.MaxIndex(); i++) {
        result[i] = source[i] * a;
    }
    return result;
}

// multiplication 2
template<typename T, typename I, typename S> Vector<T, I, S> operator * (const T & a, const Vector<T, I, S> & source){
    return source * a;
}

// division 1
template<typename T, typename I, typename S> Vector<T, I, S> operator / (const Vector<T, I, S> & source, const T & a){
    
    Vector<T, I, S> result(source.Size(), source.MinIndex());
    
    for (I i = source.MinIndex(); i <= source.MaxIndex(); i++) {
        result[i] = source[i] / a;
    }
    return result;
}

// division 2
template<typename T, typename I, typename S> Vector<T, I, S> operator / (const T & a, const Vector<T, I, S> & source){
    return source / a;
}


// template global function -------------------------------------------
// v * a
template <typename T, typename I> void scale(Vector<T, I> & vec, const T & a){
    
    for (I i = vec.MinIndex(); i <= vec.MaxIndex(); i++) {
        vec[i] *= a;
    }
}

// a * v
template <typename T, typename I> void scale(const T & a, Vector<T, I> & vec){
    
    scale(vec, a);
}

// v + a
template <typename T, typename I> void add(Vector<T, I> & vec, const T & a){
    
    for (I i = vec.MinIndex(); i <= vec.MaxIndex(); i++) {
        vec[i] += a;
    }
}

// a + v
template <typename T, typename I> void add(const T & a, Vector<T, I> & vec){
    
    add(vec, a);
}

// v - a
template <typename T, typename I> void subtract(Vector<T, I> & vec, const T & a){
    
    for (I i = vec.MinIndex(); i <= vec.MaxIndex(); i++) {
        vec[i] -= a;
    }
}

// a - v
template <typename T, typename I> void subtract(const T & a, Vector<T, I> & vec){
    
    for (I i = vec.MinIndex(); i <= vec.MaxIndex(); i++) {
        vec[i] = a - vec[i];
    }
}

// -v
template <typename T, typename I> void toggleSign(Vector<T, I> & vec){
    
    for (I i = vec.MinIndex(); i <= vec.MaxIndex(); i++) {
        vec[i] = - vec[i];
    }
}

// (a * v) + b
template <typename T, typename I> void scaleAndOffset(Vector<T, I> & vec, const T & a, const T & b){
    
    for (I i = vec.MinIndex(); i <= vec.MaxIndex(); i++) {
        vec[i] *= a;
        vec[i] += b;
    }
}

// all elements = RHS
template <typename T, typename I> void assign(Vector<T, I> & vec, const T & RHS){
    
    for (I i = vec.MinIndex(); i <= vec.MaxIndex(); i++) {
        vec[i] = RHS;
    }
}

#endif
