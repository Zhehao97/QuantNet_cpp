//
//  SizeMismatchException.cpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/29.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "SizeMismatchException.hpp"
#include <iostream>
#include <sstream>
#include <string>


namespace ZhehaoLi {

    namespace Exception{
        
    // Constructors
    SizeMismatchException::SizeMismatchException(int arrSize): m_size(arrSize){}            // Constructor with value
        
    // Destructor

    // Assgining Functions
    
    // Accessing Functions
    std::string SizeMismatchException::GetMessage() const{
        std::stringstream str_buffer;
        std::string str;
        str_buffer << "Input size " << m_size << " doesn't match!";
        str = str_buffer.str();
        return str;
    }
    
    }

}
