//
//  OutOfBoundsException.hpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef OutOfBoundsException_hpp
#define OutOfBoundsException_hpp

#include "ArrayException.hpp"


namespace ZhehaoLi {

    namespace Exception {
        
        class OutOfBoundsException: public ArrayException{
            
        private:
            int m_index;
            
        public:
            // Consturctors
            OutOfBoundsException(int idx);                      // Constructor with value
            
            // Destructor

            // Assigning Function
            
            // Accessing Function
            std::string GetMessage() const;                     // Override GetMessage() 
            
        };
    
    }
}


#endif /* OutOfBoundsException_hpp */
