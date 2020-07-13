//
//  LatticeMechanisms.hpp
//  VI.6 Latice Methods
//
//  Created by Zhehao Li on 2020/5/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef LatticeMechanisms_hpp
#define LatticeMechanisms_hpp

#include "Lattice.hpp"
#include "Matrix.hpp"
#include "MatrixMechanisms.hpp"
#include <iostream>

template <typename T, typename I, int SubNodes> void print(const Lattice<T, I, SubNodes> & source);

#ifndef LatticeMechanisms_cpp
#include "LatticeMechanisms.cpp"
#endif

#endif /* LatticeMechanisms_hpp */
