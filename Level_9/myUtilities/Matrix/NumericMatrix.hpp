//
//  NumericMatrix.hpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Numeric matrix class. This is a matrix class for numerical data. Derived from Matrix and it adds mathematical functions.

#ifndef NumericMatrix_hpp
#define NumericMatrix_hpp

#include "Vector.hpp"
#include "Matrix.hpp"

template <typename T, typename I = int, typename S = FullMatrix<T>> class NumericMatrix: public Matrix<T, I, S>{
    
private:
    
public:
    // Constructors
    NumericMatrix();                                                        // default constructor
    NumericMatrix(I n_rows, I n_cols);                                      // constructor with size num, start idx = 0
    NumericMatrix(I n_rows, I n_cols, I rowStart, I colStart);              // constructor with size and start idx
    NumericMatrix(const Matrix<T, I, S> & source);                          // copy constructor with matrix as argument
    NumericMatrix(const NumericMatrix<T, I, S> & source);                   // copy consturctor with numeric matrix as argument
    
    // Destructor
    ~NumericMatrix();
    
    // Accessors
    I Rows() const;
    I Columns() const;
    
    // Modifiers
    //    void setRow(I row, const Array<T, I> & arr);
    //    void setColumn(I col, const Array<T, I> & arr);
        NumericMatrix<T, I, S> Transpose() const;                               // switch rows and cols
    
    // Operators
    NumericMatrix<T, I, S> & operator = (const NumericMatrix<T, I, S> & source);    // assignment operator
    NumericMatrix<T, I, S> operator - () const;                                     // unary minus
    
    NumericMatrix<T, I, S> operator + (const NumericMatrix<T, I, S> & mat) const;   // matrix addition
    NumericMatrix<T, I, S> operator - (const NumericMatrix<T, I, S> & mat) const;   // matrix subtraction
    NumericMatrix<T, I, S> operator * (const NumericMatrix<T, I, S> & mat) const;   // inner product with matrix
    Vector<T, I> operator * (const Vector<T, I> & vec) const;                       // inner product with vector
    
    
};

#endif /* NumericMatrix_hpp */
