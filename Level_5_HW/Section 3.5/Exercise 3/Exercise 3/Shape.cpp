//
//  Shape.cpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Definition of base class Shape

#include "Shape.hpp"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>

namespace ZhehaoLi
{
    namespace CAD
    {
            
    // Constructors
    Shape::Shape(): m_id(rand()){
//        std::cout << "Shape: Default constructor called" << std::endl;
    }
    
    Shape::Shape(const Shape & source): m_id(source.m_id){
//        std::cout << "Shape: Copy consturctor called" << std::endl;
    }
    
    
    // Destructors
    Shape::~Shape(){
        std::cout << "Bye my Shape..." << std::endl;
    }
    
    
    // Accessing Functions
    std::string Shape::ToString() const{
        std::stringstream str_buffer;
        std::string str;
        str_buffer << "ID(" << m_id << ")";
        str = str_buffer.str();
        return str;
    }
    
    int Shape::ID() const{
        return m_id;
    }
    
    
    // Assigning Functions
    Shape & Shape::operator = (const Shape & source){
        m_id = source.m_id;
        return *this;
    }

    
    }
}
