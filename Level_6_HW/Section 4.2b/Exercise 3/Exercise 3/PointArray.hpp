//
//  PointArray.hpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/3/26.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The declarationo of template concrete derived class PointArray --> regular class, not template class

#ifndef PointArray_hpp
#define PointArray_hpp

#include "Point.hpp"
#include "Array.hpp"

namespace ZhehaoLi {

    namespace Containers{

        class PointArray: public Array<CAD::Point>{
        // Concrete inheritance
            
        public:
            /* Constructors */
            PointArray();                                     // Default constructor
            PointArray(int arrSize);                          // Constructor with value
            PointArray(const PointArray & pArr);    // Copy consturctor
            
            /* Destructor */
            ~PointArray();
            
            /* Member operators overloading */
            PointArray & operator = (const PointArray & source);

            /* Accessing functions */
            double Length() const;
            
        };
    
    }
}

#endif /* PointArray_hpp */
