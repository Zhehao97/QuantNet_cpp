//
//  ArrayException.cpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Definition of ArrayException

#include "ArrayException.hpp"
#include <iostream>
#include <sstream>
#include <string>

namespace ZhehaoLi {

    namespace Exception {

        std::string ArrayException::GetMessage() const{
            std::stringstream str_buffer;
            std::string str;
            str_buffer << "Error!";
            str = str_buffer.str();
            return str;
        };
    
    }
}
