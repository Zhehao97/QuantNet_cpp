//
//  Vector.hpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Vector class is an array with mathematical functions

#ifndef Vector_hpp
#define Vector_hpp

#include "Array.hpp"

// Default structure iis FullArray with default allocator. Default integral type is int
template <typename T, typename I = int, typename S = FullArray<T>> class Vector: public Array<T, I, S>{
  
public:
    // Constructors
    Vector();                                       // default
    Vector(I size);                                 // constructor with size
    Vector(I size, I start);                        // constructor with size and start
    Vector(I size, I start, const T & value);       // constructor with size, start and value
    Vector(const Vector<T, I, S> & source);         // copy constructor with a vector as argument
    Vector(const Array<T, I, S> & source);          // copy constructor with am array as argument
    
    // Destructor
    virtual ~Vector();
    
    // Operators
    Vector<T, I, S> & operator - () const;                              // unary minus
    
    // element-wise operation with scalar
    Vector<T, I, S> operator + (const T & a) const;                     // element-wise addition by scalar a
    Vector<T, I, S> operator - (const T & a) const;                     // element-wise subtraction by scalar a
    Vector<T, I, S> operator * (const T & a) const;                     // element-wise multiplication by scalar a
    Vector<T, I, S> operator / (const T & a) const;                     // element-wise division by scalar a
    
    // vector operations
    Vector<T, I, S> operator + (const Vector<T, I, S> & vec) const;     // vector addition
    Vector<T, I, S> operator - (const Vector<T, I, S> & vec) const;     // vector subtraction
    Vector<T, I, S> operator * (const Vector<T, I, S> & vec) const;     // vector multiplication

    
    // assignment operations with scalar
    Vector<T, I, S> & operator += (const T & a);     // assignment addition
    Vector<T, I, S> & operator -= (const T & a);     // assignment subtraction
    Vector<T, I, S> & operator *= (const T & a);     // assignment multiplication
    Vector<T, I, S> & operator /= (const T & a);     // assignment division


    // assignment operations with vector
    Vector<T, I, S> & operator = (const Vector<T, I, S> & source);      // assignment operator
    Vector<T, I, S> & operator += (const Vector<T, I, S> & source);     // assignment addition
    Vector<T, I, S> & operator -= (const Vector<T, I, S> & source);     // assignment subtraction
    Vector<T, I, S> & operator *= (const Vector<T, I, S> & source);     // assignment multiplication


    // friend operations
    friend Vector<T, I, S> operator + (const Vector<T, I, S> & source, const T & a);
    friend Vector<T, I, S> operator + (const T & a, const Vector<T, I, S> & source);
    
    friend Vector<T, I, S> operator - (const Vector<T, I, S> & source, const T & a);
    friend Vector<T, I, S> operator - (const T & a, const Vector<T, I, S> & source);
    
    friend Vector<T, I, S> operator * (const Vector<T, I, S> & source, const T & a);
    friend Vector<T, I, S> operator * (const T & a, const Vector<T, I, S> & source);
    
    friend Vector<T, I, S> operator / (const Vector<T, I, S> & source, const T & a);
    friend Vector<T, I, S> operator / (const T & a, const Vector<T, I, S> & source);
    
};

// template function
template <typename T, typename I> void scale(Vector<T, I> & vector, const T & a);       // v * a
template <typename T, typename I> void scale(const T & a, Vector<T, I> & vector);       // a * v

template <typename T, typename I> void add(Vector<T, I> & vector, const T & a);         // v + a
template <typename T, typename I> void add(const T & a, Vector<T, I> & vector);         // a + v

template <typename T, typename I> void subtract(Vector<T, I> & vector, const T & a);    // v - a
template <typename T, typename I> void subtract(const T & a, Vector<T, I> & vector);    // a - v

template <typename T, typename I> void divide(Vector<T, I> & vector, const T & a);      // v / a

template <typename T, typename I> void toggleSign(Vector<T, I> & vector);               // -v

template <typename T, typename I> void scaleAndOffset(Vector<T, I> & vector, const T & a, const T & b);     // (a * v) + b

template <typename T, typename I> void assign(Vector<T, I> & vector, const T & RHS);     // all elements = RHS

#ifndef Vector_cpp
#include "Vector.cpp"
#endif

#endif /* Vector_hpp */
