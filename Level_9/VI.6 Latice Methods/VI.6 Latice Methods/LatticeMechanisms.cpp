//
//  LatticeMechanisms.cpp
//  VI.6 Latice Methods
//
//  Created by Zhehao Li on 2020/5/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef LatticeMechanisms_cpp
#define LatticeMechanisms_cpp

#include "LatticeMechanisms.hpp"

template<typename T, typename I, int SubNodes> void print(const Lattice<T, I, SubNodes> & source){
    
    for (I j = source.MinIndex(); j <= source.MaxIndex(); j++) {
        
        std::cout << "\nBranch Number: " << j << ": [";
        for (I i = source[j].MinIndex(); i <= source[j].MaxIndex(); i++) {
            
            std::cout << source[j][i] << ", ";
        }
        std::cout << "]\n";
    }
}

#endif
