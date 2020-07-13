//
//  Array.hpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/3/10.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The declaratoin of template class Array

#ifndef Array_hpp
#define Array_hpp

namespace ZhehaoLi {

    namespace Containers{
       
        template <typename Type> class Array{
          
        private:
            int m_size;
            Type * m_data;
            
        public:
            // Constructors
            Array();                                                // Defualt constructor (*****)
            Array(int arrSize);                                     // Constructors with argument
            Array(const Array & A);                                 // Copy Consturctor (*****)
            
            // Destructor
            ~Array();                                               // (*****)
            
            // Member operator overloading
            Array<Type> & operator = (const Array<Type> & source);        // Asignment operator (*****)
            Type & operator [] (int idx);                           // Return a reference --> enable writing elements
            const Type & operator [] (int idx) const;               // Return a const reference --> may not change the value of obj by reference
                                                                    // Const function --> may not change the data member in this function
            
            // Accessing Functions
            int Size() const;
            Type & GetElement(int idx) const;                       // Const --> may not modify the data member
            
            // Modifier Functions
            void SetElement(const Type & pt, int idx);
            
        };
    
    }
}

#ifndef Array_cpp
#include "Array.cpp"
#endif

#endif /* Array_hpp */
