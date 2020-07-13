//
//  MatrixStructure.hpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Base class for matrix storage structure (API).

#ifndef MatrixStructure_hpp
#define MatrixStructure_hpp

#include "ArrayStructure.hpp"

template <typename Type> class MatrixStructure{
    
public:
    // Constructors
    MatrixStructure();                                          // default constructor
    MatrixStructure(const MatrixStructure<Type> & source);      // copy constructor
    
    // Destructor
    virtual ~MatrixStructure();
    
    // Operators
    MatrixStructure<Type> & operator = (const MatrixStructure<Type> & source);          // assignment operator
    
    virtual       Type & operator () (std::size_t row, std::size_t col)        = 0;     // modify specific elem from matrix
    virtual const Type & operator () (std::size_t row, std::size_t col) const  = 0;     // get specific elem from matrix
    
    virtual       ArrayStructure<Type> & operator [] (std::size_t index)       = 0;     // subscripting operator (modify)
    virtual const ArrayStructure<Type> & operator [] (std::size_t index) const = 0;     // subscripting operator (access)
    
    // Accessors
    virtual std::size_t Rows()    const = 0;                                            // return number of rows
    virtual std::size_t Columns() const = 0;                                            // return number of rows

    virtual std::size_t MinRowIndex() const = 0;
    virtual std::size_t MaxRowIndex() const = 0;
    virtual std::size_t MinColumnIndex() const = 0;
    virtual std::size_t MaxColumnIndex() const = 0;
    
};


#endif /* MatrixStructure_hpp */
