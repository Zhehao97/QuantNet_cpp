//
//  FullMatrix.hpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Template class for normal matrices.

#ifndef FullMatrix_hpp
#define FullMatrix_hpp

#include "MatrixStructure.hpp"
#include "FullArray.hpp"

template <typename T, typename TA=std::allocator<T> > class FullMatrix: public MatrixStructure<T>{
    
private:
    FullArray<FullArray<T, TA>, std::allocator<FullArray<T, TA> >> m_structure;
    
    std::size_t num_row;
    std::size_t num_col;

public:
    // Constructors
    FullMatrix();                                                       // Default constructor
    FullMatrix(std::size_t rows, std::size_t columns);                  // Constructor with size
    FullMatrix(const FullMatrix<T, TA> & source);                       // Copy constructor
    
    // Destructor
    virtual ~FullMatrix();
    
    // Operators
    FullMatrix<T, TA> & operator = (const FullMatrix<T, TA> & source);          // assignment operator
    
    T       & operator () (std::size_t row_idx, std::size_t col_idx);           // retrive the elem at (x, y) (mdify)
    const T & operator () (std::size_t row_idx, std::size_t col_idx) const;     // retrive the elem at (x, y) (access)
    
    FullArray<T, TA>       & operator [] (std::size_t index);                  // retreive the row vector (modify)
    const FullArray<T, TA> & operator [] (std::size_t index) const;            // retreive the row vector (access)
    
    // Modifiers
    void setElement(std::size_t row, std::size_t column, const T & val);        // set element at (x, y)
    
    // Accessors
    const T getElement(std::size_t row, std::size_t column) const;              // return element at (x, y)
    std::size_t Rows() const;                                   // Number of rows
    std::size_t Columns() const;                                // Number of columns
    std::size_t MinRowIndex() const;                            // return the min index of row
    std::size_t MaxRowIndex() const;                            // return the max index of row
    std::size_t MinColumnIndex() const;                         // return the min index of column
    std::size_t MaxColumnIndex() const;                         // return the max index of column

};



#endif /* FullMatrix_hpp */
