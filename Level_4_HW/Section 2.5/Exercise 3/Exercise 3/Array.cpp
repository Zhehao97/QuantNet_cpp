//
//  Array.cpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/3/10.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "Point.hpp"
#include "Array.hpp"
#include <iostream>


// Default Constructor
Array::Array(){
    m_size = 10;
    m_data = new Point[10];
}

// Constructor with argument
Array::Array(int arrSize){
    m_size = arrSize;
    m_data = new Point[arrSize];
}

// Copy Constructor
Array::Array(const Array & A){
    m_size = A.m_size;
    m_data = new Point[m_size];
    for (int i = 0; i < m_size; i++) {
        *(m_data + i) = A.m_data[i];
    }
}


// Destructor
Array::~Array(){
    delete [] m_data;
    std::cout << "Goodbye my Point array!" << std::endl;
}


// Acessing Functions
int Array::Size() const{                                          // Return the size of array
    return m_size;
}

Point & Array::GetElement(int idx) const{                   // Return the corresponding element of array
    if (idx >= m_size) {
        return *m_data;                                     // m_data points to the address of first element of array
    }
    else{
        return m_data[idx];                                 // Return by reference
    }                                                       // Returned element has a longer lifetime than the function
}

const Point & Array::operator[] (int idx) const{            // Const function --> may not change the data member in this function
    if (idx >= m_size) {
        return *m_data;
    }
    else{
        return m_data[idx];                                     // Return a const reference --> may not change the value of obj by reference
    }
   
}


// Modifying Functions
void Array::SetElement(const Point & pt, int idx){
    if (idx < m_size) {
        m_data[idx] = pt;                                   // Assignment operator of Point overloading
    }
}

Array & Array::operator = (const Array & source){           // Assignment operator overloading
    if (m_data == source.m_data) {                          // Check if they have the same address
        return *this;
    }
    else{                                                   // Avoid the error of arr1 = arr1
        delete [] m_data;
        m_size = source.m_size;
        m_data = new Point[m_size];
        for (int i = 0; i < m_size; i++) {
            *(m_data + i) = source.m_data[i];
        }
        return *this;
    }
}

Point & Array::operator [] (int idx){
    return m_data[idx];                                     // Return a reference --> enable reading and writing elements
}


