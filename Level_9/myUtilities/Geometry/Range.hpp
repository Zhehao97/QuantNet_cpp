//
//  Range.hpp
//  VI.4 Monte Carlo Simulation
//
//  Created by Zhehao Li on 2020/5/4.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The declaration of template class Range

#ifndef Range_hpp
#define Range_hpp

#include <vector>

template <typename Type> class Range{
  
private:
    Type lo;
    Type hi;
    
public:
    // Constructors
    Range();                                                        // Default constructor
    Range(const Type & low, const Type & high);                     // Low and high valuee
    Range(const Range<Type> & source);                              // Copy constructor
    
    // Destructor
    virtual ~Range();
    
    // Assignment operator
    Range<Type> & operator = (const Range<Type> & source);
    
    // Accessing functions
    Type low() const;                                               // Return the low value
    Type high() const;                                              // Return the high value
    Type spread() const;                                            // Return the spread
    bool left(const Type & val) const;                             // The value is lower than the range
    bool right(const Type & val) const;                            // The value is higher than the range
    bool contains(const Type & val) const;                          // The value is contained in the range
    
    // Modifier functions
    void low(const Type & l1);                                      // Set the low value
    void high(const Type & h1);                                     // Set the high value
        
    // Utility functions
    std::vector<Type> mesh(long nSteps) const;                      // Create a discrete mesh
    
};

#ifndef Range_cpp
#include "Range.cpp"
#endif

#endif /* Range_hpp */
