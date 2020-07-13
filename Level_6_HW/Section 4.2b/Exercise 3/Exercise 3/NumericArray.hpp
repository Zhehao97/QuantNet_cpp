//
//  NumericArray.hpprray
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/26.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The declaration of template generic derived class NumericArray

#ifndef NumericArray_hpp
#define NumericArray_hpp

#include "Array.hpp"

namespace ZhehaoLi {

    namespace Containers{

        template <typename Type> class NumericArray: public Array<Type>{
            
        public:
            /* Constructors */
            NumericArray();                                     // Default constructor
            NumericArray(int arrSize);                          // Constructor with value
            NumericArray(const NumericArray<Type> & numArr);    // Copy consturctor
            
            /* Destructor */
            ~NumericArray();
            
            /* Member operators overloading */
            NumericArray<Type> & operator = (const NumericArray<Type> & source);
            NumericArray<Type> operator + (const NumericArray<Type> & newArr) const;         // Const --> function may not modify the data member
            NumericArray<Type> operator * (const Type & b) const;                       // Const --> function may not modify the data member
            
            /* Accessing functions */
            Type DotProduct(const NumericArray<Type> & newArr) const;            // Const --> function may not modify the data member
        };
    
    }
}

#ifndef NumericArray_cpp
#include "NumericArray.cpp"
#endif

#endif /* NumericArray_hpp */
