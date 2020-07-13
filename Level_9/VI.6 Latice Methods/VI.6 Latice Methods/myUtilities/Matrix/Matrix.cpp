//
//  Matrix.cpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Matrix class. It uses an MatrixStructure for the actual storage. This class acts like a kind of adapter class since it defines a common interface for different matrix structures like normal matrices and sparse matrices. The matrix structure to use is given as template argument.
//  Matrix can be string or numeric matrix

#ifndef Matrix_cpp
#define Matrix_cpp

#include "Matrix.hpp"


// Constructor ---------------------------------------------------------
// default constructor
template <typename T, typename I, typename S> Matrix<T, I, S>::Matrix(){
    
    m_structure = S();
    m_rowstart = 1;
    m_colstart = 1;
}

// constructor with size num
template <typename T, typename I, typename S> Matrix<T, I, S>::Matrix(I n_rows, I n_cols){
    
    m_structure = S(n_rows, n_cols);
    m_rowstart = 1;
    m_colstart = 1;
}

// constructor with size num and start idx
template <typename T, typename I, typename S> Matrix<T, I, S>::Matrix(I n_rows, I n_cols, I rowStart, I colStart){
    
    m_structure = S(n_rows, n_cols);
    m_rowstart = 1;
    m_colstart = 1;
}

// copy constructor
template <typename T, typename I, typename S> Matrix<T, I, S>::Matrix(const Matrix<T, I, S> & source){
    m_structure = source.m_structure;
    m_rowstart = source.m_rowstart;
    m_colstart = source.m_colstart;
}

// Destructor ----------------------------------------------------------
template <typename T, typename I, typename S> Matrix<T, I, S>::~Matrix(){
    //
}


// Operators -----------------------------------------------------------
// assignment operattor
template <typename T, typename I, typename S> Matrix<T, I, S> & Matrix<T, I, S>::operator = (const Matrix<T, I, S> & source){
    
    if (this == &source) {
        return *this;
    }
    m_structure = source.m_structure;
    m_rowstart = source.m_rowstart;
    m_colstart = source.m_colstart;
}

// get the element at (row, col) (modification)
template <typename T, typename I, typename S> T & Matrix<T, I, S>::operator () (I row, I col){
    
    return m_structure[row - m_rowstart + 1][col - m_colstart + 1];
}

// get the element ar (row, col) (accessing)
template <typename T, typename I, typename S> const T & Matrix<T, I, S>::operator () (I row, I col) const{
    
    return m_structure[row - m_rowstart + 1][col - m_colstart + 1];
}

// retreive the row vector (modify)
template <typename T, typename I, typename S> Array<T, I> & Matrix<T, I, S>::operator [] (I index){
    return m_structure[index];
}

// retreive the row vector (access)
template <typename T, typename I, typename S> const Array<T, I> & Matrix<T, I, S>::operator [] (I index) const{
    return m_structure[index];
}


// Modifiers -----------------------------------------------------------
// set element at (x, y)
template <typename T, typename I, typename S> void Matrix<T, I, S>::setElement(I row, I column, const T & val){
    
    m_structure.setElement(row, column, val);
}

// replace row with array
template <typename T, typename I, typename S> void Matrix<T, I, S>::setRow(I row, const Array<T, I> & arr){
    
    I i, j; 
    for (i = arr.MinIndex(), j = m_structure.MinColumnIndex(); i <= arr.MaxIndex(); i++, j++) {
        m_structure[row][j] = arr[i];
    }
}

// replace column with array
template <typename T, typename I, typename S> void Matrix<T, I, S>::setColumn(I col, const Array<T, I> & arr){
    
    I i, j;
    for (i = arr.MinIndex(), j = m_structure.MinRowIndex(); i <= arr.MaxIndex(); i++, j++) {
        m_structure[j][col] = arr[i];
    }
}


// Accessors -----------------------------------------------------------
// return the element at (x, y)
template <typename T, typename I, typename S> const T Matrix<T, I, S>::getElement(I row, I column) const{
    
    return m_structure.getElement(row, column);
}


// return the number of row
template <typename T, typename I, typename S> Array<T, I> Matrix<T, I, S>::getRow(I row) const{
    
    return m_structure[row];
}


// retuen the number of column
template <typename T, typename I, typename S> Array<T, I> Matrix<T, I, S>::getColumn(I col) const{
    
    Array<T, I> col_arr(m_structure.Columns(), m_structure.MinRowIndex());
    for (I i = col_arr.MinIndex(), j = m_structure.MinRowIndex(); i <= col_arr.MaxIndex(); i++, j++) {
        
        col_arr[i] = m_structure[j][col];
    }
    return col_arr;
}

// number of rows
template <typename T, typename I, typename S> I Matrix<T, I, S>::Rows() const{
    
    return I( m_structure.Rows() );
}

// number of columns
template <typename T, typename I, typename S> I Matrix<T, I, S>::Columns() const{
    
    return I( m_structure.Columns() );
}

// return the min of index of row
template <typename T, typename I, typename S> I Matrix<T, I, S>::MinRowIndex() const{
    
    return I( m_structure.MinRowIndex() );
}

// return the max of index of row
template <typename T, typename I, typename S> I Matrix<T, I, S>::MaxRowIndex() const{
    
    return I( m_structure.MaxRowIndex() );
}

// return the min of index of column
template <typename T, typename I, typename S> I Matrix<T, I, S>::MinColumnIndex() const{
    
    return I( m_structure.MinColumnIndex() );
}

// return the max of index of column
template <typename T, typename I, typename S> I Matrix<T, I, S>::MaxColumnIndex() const{
    
    return I( m_structure.MaxColumnIndex() );
}

#endif
