//
//  SizeMismatchException.hpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/29.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef SizeMismatchException_hpp
#define SizeMismatchException_hpp

#include "ArrayException.hpp"

namespace ZhehaoLi {

    namespace Exception {
        
        class SizeMismatchException: public ArrayException{
            
        private:
            int m_size;
            
        public:
            // Consturctors
            SizeMismatchException(int arrSize);     // Constructor with values
            
            // Destructor

            // Assigning Function
            
            // Accessing Function
            std::string GetMessage() const;         // Override GetMessage()
            
        };
    
    }
}

#endif /* SizeMismatchException_hpp */
