//
//  Array.cpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/3/10.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The implementation of template base class Array


#ifndef Array_cpp
#define Array_cpp

#include "Array.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>

namespace ZhehaoLi {

    namespace Containers{
    
        // Initialise the static data member
        template <typename Type> int Array<Type>::m_def_size = 6;
        

        // Constructors
        // Default Constructor
        template <typename Type> Array<Type>::Array(): m_size(m_def_size), m_data(new Type[m_def_size]){}

        // Constructor with argument
        template <typename Type> Array<Type>::Array(int arrSize): m_size(arrSize), m_data(new Type[arrSize]){}

        // Copy Constructor
        template <typename Type> Array<Type>::Array(const Array<Type> & A): m_size(A.Size()), m_data(new Type[A.Size()]){
            for (int i = 0; i < m_size; i++) {
                m_data[i] = A.m_data[i];
            }
        }


        // Destructor
        template <typename Type> Array<Type>::~Array(){
            delete [] m_data;
        }
    

        // Member operators overloading
        // Assginment operator
        template <typename Type> Array<Type> & Array<Type>::operator = (const Array & source){
            if (this == &source) {                          // Check if they have the same address
                return *this;
            }
            else{                                                   // Avoid the error of arr1 = arr1
                delete [] m_data;
                m_size = source.Size();
                m_data = new Type[m_size];
                for (int i = 0; i < m_size; i++) {
                    *(m_data + i) = source.m_data[i];
                }
                return *this;
            }
        }

        // Modifier operator
        template <typename Type> Type & Array<Type>::operator [] (int idx){
            if (idx >= m_size || idx < 0) {
                throw Exception::OutOfBoundsException(idx);
            }
            else{
                return m_data[idx];                                 // Return a reference --> enable reading and writing elements
            }
            
        }

        // Accessing operator
        template <typename Type> const Type & Array<Type>::operator[] (int idx) const{
            if (idx >= m_size || idx < 0) {
                throw Exception::OutOfBoundsException(idx);
            }
            else{                                                   // Const function --> may not change the data member in this function
                return m_data[idx];                                 // Return a const reference --> may not change the value of obj by reference
            }
            
        }


        // Acessing Functions
        // Return the default size of array
        template <typename Type> int Array<Type>::DefaultSize(){
            return m_def_size;
        }
    
        // Return the size of array
        template <typename Type> int Array<Type>::Size() const{
            return m_size;
        }
        
        // Return the corresponding element of array
        template <typename Type> Type & Array<Type>::GetElement(int idx) const{
            if (idx >= m_size) {
                throw Exception::OutOfBoundsException(idx);                                           // Throw error
            }
            else{
                return m_data[idx];                                 // Return by reference
            }                                                       // Returned element has a longer lifetime than the function
        }


        // Modifier Functions
        // Modify the default size of array
        template <typename Type> void Array<Type>::DefaultSize(int s){
            m_def_size = s;
        }
    
        // Modify the element in the array
        template <typename Type> void Array<Type>::SetElement(const Type & pt, int idx){
            if (idx >= m_size) {
                throw Exception::OutOfBoundsException(idx);
            }
            else{
                m_data[idx] = pt;                                   // Assignment operator of Point overloading
            }
        }
    
    }
}


#endif /* Array_cpp */



