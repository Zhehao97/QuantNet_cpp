//
//  FullMatrix.cpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Template class for normal matrices.

#ifndef FullMatrix_cpp
#define FullMatrix_cpp

#include "FullMatrix.hpp"

// Constructors & destructor
// default constructor
template <typename T, typename TA> FullMatrix<T, TA>::FullMatrix(): MatrixStructure<T>(){

    m_structure = FullArray<FullArray<T, TA>, std::allocator<FullArray<T, TA> > >();
    num_row = 1;
    num_col = 1;
}

// constructor with size
template <typename T, typename TA> FullMatrix<T, TA>::FullMatrix(std::size_t rows, std::size_t columns): MatrixStructure<T>(){

    // create the rows
    m_structure = FullArray<FullArray<T, TA>, std::allocator<FullArray<T, TA>> >(rows);

    // Add the colums to the rows
    for (std::size_t i = 1; i <= m_structure.Size(); i++){
        m_structure[i] = FullArray<T, TA>(columns);
    }
    num_row = rows;
    num_col = columns;

}

// copy constructor
template <typename V, typename TA> FullMatrix<V, TA>::FullMatrix(const FullMatrix<V, TA>& source): MatrixStructure<V>(source){

    m_structure = source.m_structure;
    num_row = source.num_row;
    num_col = source.num_col;
}

// Destructor -----------------------------------------------------------
template <typename T, typename TA> FullMatrix<T, TA>::~FullMatrix(){
    //
}


// Operators -------------------------------------------------------------
// assignment operator
template <typename T, typename TA> FullMatrix<T, TA> & FullMatrix<T, TA>::operator = (const FullMatrix<T, TA> & source){

    // Exit if same object
    if (this == &source) {
        return *this;
    }
    // Call base class assignment
    MatrixStructure<T>::operator = (source);

    m_structure = source.m_structure;
    num_row = source.num_row;
    num_col = source.num_col;

    return *this;
}

// modify specific elem from matrix
template <typename T, typename TA> T & FullMatrix<T, TA>::operator () (std::size_t row_idx, std::size_t col_idx){
    // Use the subscripting operator of derived class
    return (*this)[row_idx][col_idx];
}

// get specific elem from matrix
template <typename T, typename TA> const T & FullMatrix<T, TA>::operator () (std::size_t row_idx, std::size_t col_idx) const{
    // Use the subscripting operator of derived class
    return (*this)[row_idx][col_idx];
}


// subscripting operator (modification)
template <typename T, typename TA> FullArray<T, TA> & FullMatrix<T, TA>::operator [] (std::size_t row){

    return m_structure[row];
}

// Subscripting operator (accessing)
template <typename T, typename TA> const FullArray<T, TA> & FullMatrix<T, TA>::operator [] (std::size_t row) const{

    return m_structure[row];
}


// Modifiers -----------------------------------------------------------
// set element at (x, y)
template <typename T, typename TA> void FullMatrix<T, TA>::setElement(std::size_t row, std::size_t column, const T & val){
    // Use the subscripting operator of derived class
    (*this)[row][column] = val;
}


// Accessors -----------------------------------------------------------
// return const element at (x, y)
template <typename T, typename TA> const T FullMatrix<T, TA>::getElement(std::size_t row, std::size_t column) const{
    // Use the subscripting operator of derived class
    return (*this)[row][column];
}

// return num of rows
template <typename T, typename TA> std::size_t FullMatrix<T, TA>::Rows() const{

    return num_row;
}

// return num of cols
template <typename T, typename TA> std::size_t FullMatrix<T, TA>::Columns() const{

    return num_col;
}

template <typename T, typename TA> std::size_t FullMatrix<T, TA>::MinRowIndex() const{
    
    return 1;
}

template <typename T, typename TA> std::size_t FullMatrix<T, TA>::MaxRowIndex() const{
    
    return Rows();
}

template <typename T, typename TA> std::size_t FullMatrix<T, TA>::MinColumnIndex() const{
    
    return 1;
}

template <typename T, typename TA> std::size_t FullMatrix<T, TA>::MaxColumnIndex() const{
    
    return Columns();
}

#endif
