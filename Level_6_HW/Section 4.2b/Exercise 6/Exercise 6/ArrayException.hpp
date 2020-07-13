//
//  ArrayException.hpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Declaration of ArrayException (base class of hierarchy)


#ifndef ArrayException_hpp
#define ArrayException_hpp

#include <string>

namespace ZhehaoLi {

    namespace Exception {

        class ArrayException{
          
        private:
            
        public:
            // Constructors
            // Destructors
            // Assginment Functions
            // Accesing Functions
            virtual std::string GetMessage() const;
        };
    
    }
}

#endif /* ArrayException_hpp */
