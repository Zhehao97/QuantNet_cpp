//
//  FullArray.hpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/15.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Template class for a full (non-sparse) arrays.

#ifndef FullArray_hpp
#define FullArray_hpp

#include "ArrayStructure.hpp"
#include <vector>

template <typename T, typename TA = std::allocator<T>> class FullArray: public ArrayStructure<T>{
  
private:
    std::vector<T, TA> m_vector;                // use STL vector class for storage
    
public:
    // Constructors
    FullArray();
    FullArray(std::size_t size);
    FullArray(const FullArray<T, TA> & source);
    
    // Destructor
    ~FullArray();
    
    // Operators
    T & operator [] (std::size_t index);                // Indexing operator (modification)
    const T & operator [] (std::size_t index) const;    // Indexinig opeartor (accessing)
    FullArray<T, TA> & operator = (const FullArray<T, TA> & source);
    
    // Modifiers
    
    // Accessors
    virtual std::size_t Size() const;
    
};


//#ifndef FullArray_cpp
//#include "FullArray.cpp"
//#endif

#endif /* FullArray_hpp */
