//
//  PointArray.cpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/3/26.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The implementation of template concrete derived class PointArray


#include "PointArray.hpp"

namespace ZhehaoLi {

    namespace Containers{
        
        /* PointArray is a regular class*/
        
        /* Constructors */
        // Default constructors
        PointArray::PointArray(): Array<CAD::Point>(){
            std::cout << "PointArray Default Constructor.." << std::endl;
        }

        // Constructors with value
        PointArray::PointArray(int arrSize): Array<CAD::Point>(arrSize){
            std::cout << "PointArray Constructor with values.." << std::endl;
        }
    
        // Copy Consturctor
        PointArray::PointArray(const PointArray & source): Array<CAD::Point>(source){
            std::cout << "PointArray Copy Constructor.." << std::endl;
        }
    
        
        /* Destructor */
        PointArray::~PointArray(){
            std::cout << "Bye bye PointArray!" << std::endl;
        }
    
        
        /* Memeber operators overloading */
        // Assignment operator
        PointArray & PointArray::operator=(const PointArray & source){
            if (this == &source) {                                      // Check the address
                return *this;
            }
            else{
                Array<CAD::Point>::operator = (source);                 // Assginment operator of base template class with type Point
                return *this;
            }
        }
    
        
        /* Accessing functions */
        // Length of PointArray
        double PointArray::Length() const{
            double totalLen = 0;
            for (int i = 0; i < this->Size() - 1; i++) {
                totalLen += this->GetElement(i).Distance(this->GetElement(i + 1));
            }
            return totalLen;                                            // The total length of ponits between the points in the array
        }
    
    }
}
