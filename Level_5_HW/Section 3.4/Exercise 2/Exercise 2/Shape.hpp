//
//  Shape.hpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Declaration of base class Shape

#ifndef Shape_hpp
#define Shape_hpp

#include <iostream>
#include <stdlib.h>
#include <string>


namespace ZhehaoLi {

    namespace CAD{
    
        class Shape{
          
        private:
            int m_id;
            
        public:
            // Constructors
            Shape();                                        // Default Constructor
            Shape(const Shape & source);                    // Copy Constructor
            
            // Destructors
            virtual ~Shape();
            
            // Accessing Functions
            std::string ToString() const;                   // Returns the id as string
            int ID() const;                                 // Return the id of shape
            
            // Assigning Functions
            Shape & operator = (const Shape & source);      // Assginment operator
            
            
        };
    
    }
}




#endif /* Shape_hpp */
