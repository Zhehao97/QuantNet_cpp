//
//  OutOfBoundsException.cpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "OutOfBoundsException.hpp"
#include <iostream>
#include <sstream>
#include <string>


namespace ZhehaoLi {

    namespace Exception{
        
    // Constructors
    OutOfBoundsException::OutOfBoundsException(int idx){            // Constructor with value
        m_index = idx;
    }
        
    // Destructor

    // Assgining Functions
    
    // Accessing Functions
    std::string OutOfBoundsException::GetMessage() const{
        std::stringstream str_buffer;
        std::string str;
        str_buffer << "Index " << m_index << " is out of bounds!";
        str = str_buffer.str();
        return str;
    }
    
    
    }

}


