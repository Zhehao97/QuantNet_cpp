//
//  Range.hpp
//  CPP_4.2
//
//  Created by Zhehao Li on 2020/3/25.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Declaration of Range template class

#ifndef Range_hpp
#define Range_hpp

template <typename Type=double> class Range{           // default type = double

private:
    Type lo;                                        // lower range
    Type hi;                                        // higher range
    
public:
    // Consturctors
    Range();                                        // Default consturctor
    Range(const Type & low, const Type & high);     // Constructor with values
    Range(const Range<Type> & ran1);                // Copy constructor
    
    // Destructor
    virtual ~Range();
    
    // Modifier functions
    void low(const Type & t1);                      // Set the lowest value of range
    void high(const Type & t1);                     // Set the highest value of range
    
    // Accesssing functions
    Type low() const;                               // Access the lowest value of range
    Type high() const;                              // Access the highest value of range
    Type spread() const;                            // Acceess the spread of range
    
    // Operators overloading
    Range<Type> & operator = (const Range<Type> & ran2);
    
    // Boolean functions
    bool left(const Type & val) const;              // Is the value to the left of the range
    bool right(const Type & val) const;             // Is the value to the right of the range
    bool contains(const Type & val) const;          // Does range contains the value
    
};

#endif /* Range_hpp */
