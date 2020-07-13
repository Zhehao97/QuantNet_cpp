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
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"
#include "ArrayException.hpp"
#include <iostream>

namespace ZhehaoLi {

    namespace Containers{
        
        /* Consturctors */
        // Default constructor
        template <typename Type, int size> Stack<Type, size>::Stack(): m_Arr(size), m_current(0){
            // Current index = 0 when the array is empty
            std::cout << "Stack Default Constructor.." << std::endl;
        }
    
        // Copy constructor
        template <typename Type, int size> Stack<Type, size>::Stack(const Stack<Type, size> & S): m_Arr(S.m_Arr), m_current(S.m_current){
            // S.m_Arr, S,m_current -> Access level is at the class level: not individual object (not limitation of private member)
            // Private means that only the class is able to change the data.
            std::cout << "Stack Copy Constructor.." << std::endl;
        }
    
        /* Destructor */
        template <typename Type, int size> Stack<Type, size>::~Stack(){                 // Will automatically call ~Array()
            std::cout << "Bye bye Stack template!" << std::endl;
        }
    
        /* Operators overloading */
        template <typename Type, int size> Stack<Type, size> & Stack<Type, size>::operator=(const Stack<Type, size> & source){
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
        template <typename Type, int size> void Stack<Type, size>::Push(Type data){
            try {
                m_Arr[m_current++] = data;                      // First assign the value at m_current, then increase m_current
            } catch (Exception::ArrayException & Err) {
                throw Exception::StackFullException();
            }
            
        }
    
        template <typename Type, int size> Type Stack<Type, size>::Pop(){
            try {
                return m_Arr[--m_current];                          // First return the value at m_current, then decrease m_current
            } catch (Exception::ArrayException & Err) {
                m_current = 0;
                throw Exception::StackEmptyException();
            }
            
        }
    
    }
}

#endif /* Stack_cpp */


