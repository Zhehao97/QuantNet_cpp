//
//  Matrix.hpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Matrix class. It uses an MatrixStructure for the actual storage. This class acts like a kind of adapter class since it defines a common interface for different matrix structures like normal matrices and sparse matrices. The matrix structure to use is given as template argument.

#ifndef Matrix_hpp
#define Matrix_hpp

#include "Array.hpp"
#include "FullMatrix.hpp"

// Default structure is FullArray with default allocator. Default integral type is int.
template <typename T, typename I = int, typename S = FullMatrix<T> > class Matrix{
    
private:
    S m_structure;                                                  // the FullMatrix structure
    I m_rowstart;                                                   // the row start index
    I m_colstart;                                                   // the column start index
    
public:
    // Constructors
    Matrix();                                                       // default constructor
    Matrix(I n_rows, I n_cols);                                     // constructor with size num, start idx = 0
    Matrix(I n_rows, I n_cols, I rowStart, I colStart);             // constructor with size and start idx
    Matrix(const Matrix<T, I, S> & source);                         // copy constructor
    
    // Destructor
    virtual ~Matrix();
    
    // Operators
    Matrix<T, I, S> & operator = (const Matrix<T, I, S> & source);  // assignment operator
    
    T       & operator () (I row, I col);                           // get the element at (row, col) (modification)
    const T & operator () (I row, I col) const;                     // get the element at (row, col) (accessing)
    
    Array<T, I>       & operator [] (I index);            // retreive the row vector (modify)
    const Array<T, I> & operator [] (I index) const;      // retreive the row vector (access)

    
    // Modifiers
    void setElement(I row, I column, const T & val);               // set element at (x, y)
    void setRow(I row, const Array<T, I> & arr);                    // replace row with array
    void setColumn(I col, const Array<T, I> & arr);                 // replace column with array
    
    // Accessors
    const T getElement(I row, I column) const;              // return element at (x, y)
    Array<T, I> getRow(I row) const;                                // return the row of matrix
    Array<T, I> getColumn(I col) const;                             // return the column of matrix
    
    I Rows() const;                                   // number of rows
    I Columns() const;                                // number of columns
    I MinRowIndex() const;                            // return the min index of row
    I MaxRowIndex() const;                            // return the max index of row
    I MinColumnIndex() const;                         // return the min index of column
    I MaxColumnIndex() const;                         // return the max index of column
    
};

#ifndef Matrix_cpp
#include "Matrix.cpp"
#endif

#endif /* Matrix_hpp */
