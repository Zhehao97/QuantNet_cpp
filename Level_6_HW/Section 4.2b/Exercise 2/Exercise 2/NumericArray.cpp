//
//  NumericArray.cpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/26.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The implementation of template derived class NumericArray


#ifndef NumericArray_cpp
#define NumericArray_cpp

#include "Array.hpp"
#include "NumericArray.hpp"
#include "SizeMismatchException.hpp"
#include <iostream>

namespace ZhehaoLi {

    namespace Containers{

        /* Constructors */
        // Default constructor
        template <typename Type> NumericArray<Type>::NumericArray(): Array<Type>(){
            std::cout << "NumericArray Default Constructor.." << std::endl;
        }
        
        // COnstructor with value
        template <typename Type> NumericArray<Type>::NumericArray(int arrSize): Array<Type>(arrSize){
            std::cout << "NumericArray Constructor with values.." << std::endl;
        }
        
        // Copy constructor
        template <typename Type> NumericArray<Type>::NumericArray(const NumericArray<Type> & numArr): Array<Type>(numArr){
            std::cout << "NumericArray Copy Constructor.." << std::endl;
        }
        
        
        /* Destructor */
        template <typename Type> NumericArray<Type>::~NumericArray(){
            std::cout << "Bye bye NumericArray template!" << std::endl;
        }
        
        
        /* Member operators overloading */
        // Assignment operator
        template <typename Type> NumericArray<Type> & NumericArray<Type>::operator=(const NumericArray<Type> & source){
            if (this == &source) {                                                      // Compare the address of pointers
                return *this;
            }
            else{
                Array<Type>::operator = (source);                                       // Assginment operator of base template class
                return *this;
            }
        }
        
        // Additionn operator
        template <typename Type> NumericArray<Type> NumericArray<Type>::operator+(const NumericArray<Type> & newArr) const{
            NumericArray<Type> Temp(this->Size());                                      // Create a temporay object
            if (this->Size() == newArr.Size()) {
                for (int i=0; i < this->Size(); i++) {
                    Temp.GetElement(i) = this->GetElement(i) + newArr.GetElement(i);    // Assume template argument Type has functionality + and =
                }
            }
            else{
                throw Exception::SizeMismatchException(newArr.Size());
            }
            return Temp;
        }
        
        // Scale operator
        template <typename Type> NumericArray<Type> NumericArray<Type>::operator*(const Type & b) const{
            NumericArray<Type> Temp(this->Size());                                      // Create a temporary object
            for (int i=0; i < this->Size(); i++) {
                Temp.SetElement(this->GetElement(i) * b, i);                            // Assume template argument Type has functionality *
            }
            return Temp;
        }
        
        
        /* Accessing functions */
        template <typename Type> Type NumericArray<Type>::DotProduct(const NumericArray<Type> & newArr) const{
            Type temp = (*this).GetElement(0) + newArr.GetElement(0);                   // Intialize the value with first product
            if (this->Size() == newArr.Size()) {
                for (int i=1; i < this->Size(); i++) {
                    temp += this->GetElement(i) * newArr.GetElement(i);                 // Assume template argument Type has functionality +=
                }
            }
            else{
                throw Exception::SizeMismatchException(newArr.Size());
            }
            return temp;
        }
    
    }
}



#endif /* NumericArray_cpp */
