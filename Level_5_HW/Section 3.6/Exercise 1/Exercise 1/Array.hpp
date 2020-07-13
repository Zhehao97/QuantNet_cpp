//
//  Array.hpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/3/10.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include "Point.hpp"


namespace ZhehaoLi {

    namespace Containers{
       
        class Array{
          
        private:
            int m_size;
            CAD::Point * m_data;
            
        public:
            // Constructors
            Array();                                                // Defualt constructor (*****)
            Array(int arrSize);                                     // Constructors with argument
            Array(const Array & A);                                 // Copy Consturctor (*****)
            
            // Destructor
            ~Array();                                               // (*****)
            
            // Member operator overloading
            Array & operator = (const Array & source);              // Asignment operator (*****)
            CAD::Point & operator [] (int idx);                     // Return a reference --> enable writing elements
            const CAD::Point & operator [] (int idx) const;         // Return a const reference --> may not change the value of obj by reference
                                                                    // Const function --> may not change the data member in this function
            
            // Accessing Functions
            int Size() const;
            CAD::Point & GetElement(int idx) const;                  // Const --> may not modify the data member
            
            // Modifying Functions
            void SetElement(const CAD::Point & pt, int idx);
            
        };
    
    }
}




#endif /* Array_hpp */
