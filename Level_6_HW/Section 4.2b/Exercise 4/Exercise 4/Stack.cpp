//
//  Stack.cpp
//  Exercise 4
//
//  Created by Zhehao Li on 2020/3/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef Stack_cpp
#define Stack_cpp

#include "Stack.hpp"
#include <iostream>

namespace ZhehaoLi {

    namespace Containers{
        
        /* Consturctors */
        // Default constructor
        template <typename Type> Stack<Type>::Stack(): m_Arr(), m_current(0){
            // Current index = 0 when the array is empty
            std::cout << "Stack Default Constructor.." << std::endl;
        }
    
        // Constructor with values
        template <typename Type> Stack<Type>::Stack(int arrSize): m_Arr(arrSize), m_current(0){
            // Current index = 0 when the array is empty
            std::cout << "Stack Constructor with values.." << std::endl;
        }
    
        // Copy constructor
        template <typename Type> Stack<Type>::Stack(const Stack<Type> & S): m_Arr(S.m_Arr), m_current(S.m_current){
            std::cout << "Stack Copy Constructor.." << std::endl;
        }
    
        /* Destructor */
        template <typename Type> Stack<Type>::~Stack(){                 // Will automatically call ~Array()
            std::cout << "Bye bye Stack template!" << std::endl;
        }
    
        /* Operators overloading */
        template <typename Type> Stack<Type> & Stack<Type>::operator=(const Stack<Type> & source){
            if (this == &source) {                                      // Check the address
                return *this;
            }
            else{
                m_current = source.m_current;
                m_Arr = source.m_Arr;                                   // Call the assignment operator of Array
            }
            return *this;
        }
    
        /* Modifer functions */
        template <typename Type> void Stack<Type>::Push(Type data){
            m_Arr[m_current++] = data;                                  // First assign the value at m_current, then increase m_current
        }
    
        template <typename Type> Type Stack<Type>::Pop(){
            return m_Arr[--m_current];                                  // First return the value at m_current, then decrease m_current
        }
    
    }
}

#endif /* Stack_cpp */


