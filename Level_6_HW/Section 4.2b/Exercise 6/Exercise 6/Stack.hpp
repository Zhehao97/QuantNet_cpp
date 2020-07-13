//
//  Stack.hpp
//  Exercise 4
//
//  Created by Zhehao Li on 2020/3/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The declaration of template base class Stack (Composition)


#ifndef Stack_hpp
#define Stack_hpp

#include "Array.hpp"

namespace ZhehaoLi {
    
    namespace Containers{

        template <typename Type, int size> class Stack{
        
        private:
            Array<Type> m_Arr;                  // An Array<type> object as data member
            int m_current;                      // Current index in the array
            
        public:
            /* Constructors */
            Stack();                            // Default constructor
            Stack(const Stack<Type, size> & S);       // Copy constructor
            
            /* Destructor */
            virtual ~Stack();
            
            /* Operators overloading */
            virtual Stack<Type, size> & operator = (const Stack<Type, size> & source);      // Assginment operator
            
            /* Modifier functions */
            virtual void Push(Type data);       // Push in the data at the top of stack
            virtual Type Pop();                 // Pop out the data at the top of stack
        };
    
    }
}


#ifndef Stack_cpp
#include "Stack.cpp"
#endif

#endif /* Stack_hpp */
