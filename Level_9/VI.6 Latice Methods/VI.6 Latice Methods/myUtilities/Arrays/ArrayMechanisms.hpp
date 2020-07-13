//
//  ArrayMechanisms.hpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/15.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef ArrayMechanisms_hpp
#define ArrayMechanisms_hpp

#include "Array.hpp"
#include "Vector.hpp"

template <typename T, typename I> void print(const Array<T, I> & arr);

template <typename T, typename I> void print(const Vector<T, I> & vec);

#ifndef ArrayMechanisms_cpp
#include "ArrayStructure.cpp"
#endif

#endif /* ArrayMechanisms_hpp */
