//
//  Array.hpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/3/10.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include "Point.hpp"

class Array{
  
private:
    int m_size;
    Point * m_data;
    
public:
    // Constructors
    Array();                                            // Defualt constructor (*****)
    Array(int arrSize);                                 // Constructors with argument
    Array(const Array & A);                             // Copy Consturctor (*****)
    
    // Destructor
    ~Array();                                           // (*****)
    
    // Accessing Functions
    int Size() const;                                   // Acessing functions should be const in general
    Point & GetElement(int idx) const;                  // Const --> may not modify the data member
    const Point & operator [] (int idx) const;          // Return a const reference --> may not change the value of obj by reference
                                                        // Const function --> may not change the data member in this function
    
    // Modifying Functions
    void SetElement(const Point & pt, int idx);
    Array & operator = (const Array & source);          // Asignment operator (*****)
    Point & operator [] (int idx);                      // Return a reference --> enable writing elements
    
};


#endif /* Array_hpp */
