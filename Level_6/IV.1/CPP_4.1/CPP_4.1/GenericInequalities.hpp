//
//  GenericInequalities.hpp
//  CPP_4.1
//
//  Created by Zhehao Li on 2020/3/25.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Declaration of template function
//
// Preprocessor directives; ensures that we do not include a file twice (gives compiler error)
#ifndef GenericInequalities_hpp
#define GenericInequalities_hpp

// Max and Min of two numbers
template <typename Numeric> Numeric Max(const Numeric & x, const Numeric & y);
template <typename Numeric> Numeric Min(const Numeric & x, const Numeric & y);

// Max and Min of three numbers
template <typename Numeric> Numeric Max(const Numeric & x, const Numeric & y, const Numeric & z);
template <typename Numeric> Numeric Min(const Numeric & x, const Numeric & y, const Numeric & z);

#endif /* GenericInequalities_hpp */
