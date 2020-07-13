//
//  ArrayStructure.hpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/15.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Base class for array storage structure. A size_t is used for indexing. Indexing starts at 1 in this class and its dervived classes. These derived classes must implement the indexing [] operator.

#ifndef ArrayStructure_hpp
#define ArrayStructure_hpp

#include <cstring>                                      // size_t

template <typename T> class ArrayStructure{
    
private:
    
public:
    // Constructors
    ArrayStructure();                                   // Default constructor
    ArrayStructure(const ArrayStructure<T> & source);   // Copy constructor
    
    // Destructor
    virtual ~ArrayStructure();                          // Destructor
    
    // Operators
    virtual T & operator [] (std::size_t index) = 0;                        // Indexing operator (modification)
    virtual const T & operator [] (std::size_t index) const = 0;            // Indexing operator (accessing)
    ArrayStructure<T> & operator = (const ArrayStructure<T> & source);      // Copy operator
    
    // Modifiers
    void Element(std::size_t index, const T & val);     // Modify elements in the array
    
    // Accessors
    virtual std::size_t Size() const = 0;
    const T & Element(std::size_t index) const;         // Access elements in the array
    std::size_t MinIndex() const;                       // Return the minimum index = 1
    std::size_t MaxIndex() const;                       // Return the maximum index = size
    
};

//#ifndef ArrayStructure_hpp
//#include "ArrayStructure.cpp"
//#endif

#endif /* ArrayStructure_hpp */
