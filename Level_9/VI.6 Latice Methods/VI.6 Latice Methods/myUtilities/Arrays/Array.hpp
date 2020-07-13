//
//  Array.hpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/15.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Array class. It uses an ArrayStructure for the actual storage. This class acts like a kind of adapter class since it defines a common interface for different array structures like normal full arrays and sparse arrays. The array structure to use is given as template argument.

#ifndef Array_hpp
#define Array_hpp

#include "ArrayStructure.hpp"
#include "FullArray.hpp"

// Default structure is FullArray with default allocator. Default integral type is int.
template <typename T, typename I = int, typename S = FullArray<T>> class Array{

private:
    S m_structure;                                      // the array structure
    I m_start;                                          // the start index
    
public:
    // Constructors
    Array();                                            // default constructor
    Array(I size);                                      // constructor with size (start inidex = 1)
    Array(I size, I start);                             // constructor with size and start index
    Array(I size, I start, const T & value);            // constructor with sizee, start and value
    Array(const Array<T, I, S> & source);               // copy constructor
    
    // Destructor
    virtual ~Array();                                   // destructor
    
    // Operators
    virtual T & operator [] (I index);                  // subscripting operator (modification)
    virtual const T & operator [] (I index) const;      // subscripting operator (modification)
    Array<T, I, S> & operator = (const Array<T, I, S> & source);
    
    // Accessors
    I MinIndex() const;                                 // return the minimum index
    I MaxIndex() const;                                 // return the maximum index
    I Size() const;                                     // return the siize of the array
};

#ifndef Array_cpp
#include "Array.cpp"
#endif

#endif /* Array_hpp */
