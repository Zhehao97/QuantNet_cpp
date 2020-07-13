//
//  MatrixMechanisms.cpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/16.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef MatrixMechanisms_cpp
#define MatrixMechanisms_cpp

#include "MatrixMechanisms.hpp"
#include <iostream>

template <class T, class I> void print(const Matrix<T, I> & mat){

    for (int i = mat.MinRowIndex(); i <= mat.MaxRowIndex(); i++){
    
        std::cout << "\n[";
        for (I j = mat.MinColumnIndex(); j <= mat.MaxColumnIndex()-1; j++){
            std::cout << mat(i,j) << ", ";
        }
        std::cout << mat(i, mat.MaxColumnIndex());
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
}

#endif
