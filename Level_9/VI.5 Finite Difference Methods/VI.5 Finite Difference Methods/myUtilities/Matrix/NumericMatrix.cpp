//
//  NumericMatrix.cpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Numeric matrix class. This is a matrix class for numerical data. Derived from Matrix and it adds mathematical functions.

#ifndef NumericMatrix_cpp
#define NumericMatrix_cpp

#include "NumericMatrix.hpp"

// Constructors --------------------------------------------------------
// default constructor
template <typename T, typename I, typename S> NumericMatrix<T, I, S>::NumericMatrix(): Matrix<T, I, S>() {
    //
}

// constructor with size
template <typename T, typename I, typename S> NumericMatrix<T, I, S>::NumericMatrix(I n_rows, I n_cols): Matrix<T, I, S>(n_rows, n_cols){
    //
}

// constructor with size and start idix
template <typename T, typename I, typename S> NumericMatrix<T, I, S>::NumericMatrix(I n_rows, I n_cols, I rowStart, I colStart): Matrix<T, I, S>(n_rows, n_cols, rowStart, colStart){
    // 
}

// copy constructor wiith matrix as argument
template <typename T, typename I, typename S> NumericMatrix<T, I, S>::NumericMatrix(const Matrix<T, I, S> & source): Matrix<T, I, S>(source){
    //
}

// copy constructor with numericMatrix as argument
template <typename T, typename I, typename S> NumericMatrix<T, I, S>::NumericMatrix(const NumericMatrix<T, I, S> & source): Matrix<T, I, S>(source){
    //
}

// Destructor ----------------------------------------------------------
template <typename T, typename I, typename S> NumericMatrix<T, I, S>::~NumericMatrix(){
    //
}


// Accessors -----------------------------------------------------------
// return the number of rows
template <typename T, typename I, typename S> I NumericMatrix<T, I, S>::Rows() const{
    
    return Matrix<T, I, S>::Rows();
}

// return the number of columns
template <typename T, typename I, typename S> I NumericMatrix<T, I, S>::Columns() const{
    
    return Matrix<T, I, S>::Columns();
}


// Modifiers -----------------------------------------------------------
// Switch rows and columns
template <class T, class I, class S> NumericMatrix<T, I, S> NumericMatrix<T, I, S>::Transpose() const{
    
    NumericMatrix<T, I, S> result(Columns(), Rows());

    for (I i = result.MinRowIndex(); i <= result.MaxRowIndex(); i++){
        for (I j = result.MinColumnIndex(); j<= result.MaxColumnIndex(); ++j){
            result(i,j) = (*this)(j,i);
        }
    }

    return result;
}


// Operators -----------------------------------------------------------
// assignment operator
template <class T, class I, class S> NumericMatrix<T, I, S> & NumericMatrix<T, I, S>::operator = (const NumericMatrix<T, I, S> & source){
    
    if (this == &source) {
        return *this;
    }
    Matrix<T, I, S>::operator = (source);
    return *this;
}

// unary minus
template <class T, class I, class S> NumericMatrix<T, I, S> NumericMatrix<T, I, S>::operator - () const{
    
    NumericMatrix<T, I, S> result(Rows(), Columns(), Matrix<T, I, S>::MinRowIndex(), Matrix<T, I, S>::MinColumnIndex());
    
    // Copy all elements negative
    for (I r = Matrix<T, I, S>::MinRowIndex(); r <= Matrix<T, I, S>::MaxRowIndex(); r++){
        for (I c = Matrix<T, I, S>::MinColumnIndex(); c <= Matrix<T, I, S>::MaxColumnIndex(); c++){

            result(r, c) = -(*this)(r, c);
        }
    }
    return result;
}

// matrix addition
template <class T, class I, class S> NumericMatrix<T, I, S> NumericMatrix<T, I, S>::operator + (const NumericMatrix<T, I, S> & mat) const{
    
    NumericMatrix<T, I, S> result(Rows(), Columns(), Matrix<T, I, S>::MinRowIndex(), Matrix<T, I, S>::MinColumnIndex());
    
    // Copy all elements negative
    for (I r1 = Matrix<T, I, S>::MinRowIndex(); r1 <= Matrix<T, I, S>::MaxRowIndex(); r1++){
        for (I c1 = Matrix<T, I, S>::MinColumnIndex(); c1 <= Matrix<T, I, S>::MaxColumnIndex(); c1++){

            result(r1, c1) = (*this)(r1, c1) + mat(r1, c1);
        }
    }
    return result;
}

// matrix subtraction
template <class T, class I, class S> NumericMatrix<T, I, S> NumericMatrix<T, I, S>::operator - (const NumericMatrix<T, I, S> & mat) const{
    
    NumericMatrix<T, I, S> result(Rows(), Columns(), Matrix<T, I, S>::MinRowIndex(), Matrix<T, I, S>::MinColumnIndex());
    
    // Copy all elements negative
    for (I r1 = Matrix<T, I, S>::MinRowIndex(); r1 <= Matrix<T, I, S>::MaxRowIndex(); r1++){
        for (I c1 = Matrix<T, I, S>::MinColumnIndex(); c1 <= Matrix<T, I, S>::MaxColumnIndex(); c1++){

            result(r1, c1) = (*this)(r1, c1) - mat(r1, c1);
        }
    }
    return result;
}

// inner product with matrix
template <class T, class I, class S> NumericMatrix<T, I, S> NumericMatrix<T, I, S>::operator * (const NumericMatrix<T, I, S> & mat) const{
    
    NumericMatrix<T, I, S> result(Rows(), Columns(), Matrix<T, I, S>::MinRowIndex(), Matrix<T, I, S>::MinColumnIndex());
    
    // Copy all elements negative
    for (I rr = Matrix<T, I, S>::MinRowIndex(); rr <= Matrix<T, I, S>::MaxRowIndex(); rr++){
        
        for (I cr = Matrix<T, I, S>::MinColumnIndex(); cr <= Matrix<T, I, S>::MaxColumnIndex(); cr++){
            
            result(rr, cr) = 0.0;
            
            for (I k = Matrix<T, I, S>::MinColumnIndex(); k <= Matrix<T, I, S>::MaxColumnIndex(); k++) {
                
                result(rr, cr) += (*this)(rr, k) * mat(k, cr);
            }
        }
    }
    return result;
}


// inner product with vector
template <class T, class I, class S> Vector<T, I> NumericMatrix<T, I, S>::operator * (const Vector<T, I> & vec) const{
    
    Vector<T, I> result(Rows(), vec.MinIndex());
    
    T r(0.0);    // sum of rows
    
    for (I i = Matrix<T, I, S>::MinRowIndex(); i <= Matrix<T, I, S>::MaxRowIndex(); i++){
        
        r = 0.0;
        
        for (I j = Matrix<T, I, S>::MinColumnIndex(); j <= Matrix<T, I, S>::MaxColumnIndex(); j++){
            
                r += (*this)(i, j) * vec[j];
        }
        result[i] = r;
    }
    return result;
}

#endif
