//
//  ArrayMechanisms.cpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/15.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//


#ifndef ArrayMechanisms_cpp
#define ArrayMechanisms_cpp

#include "ArrayMechanisms.hpp"
#include <iostream>

template <typename T, typename I> void print(const Array<T, I> & arr){
    
    std::cout << "\n\nMinIndex: " << arr.MinIndex() << ", MaxIndex: " << arr.MaxIndex() << std::endl;

    std::cout << "\nARR: [";
    for (I j = arr.MinIndex(); j <= arr.MaxIndex(); j++){
        std::cout << arr[j] << ", ";
    }
    std::cout << "]";
}

template <typename T, typename I> void print(const Vector<T, I> & vec){
    
    std::cout << "\n\nMinIndex: " << vec.MinIndex() << ", MaxIndex: " << vec.MaxIndex() << std::endl;

    std::cout << "\nARR: [";
    for (I j = vec.MinIndex(); j <= vec.MaxIndex(); j++){
        std::cout << vec[j] << ", ";
    }
    std::cout << "]";
}

#endif
