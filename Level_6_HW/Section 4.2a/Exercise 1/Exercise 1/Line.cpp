//
//  Line.cpp
//  Exercise 5
//
//  Created by Zhehao Li on 2020/2/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The implementation of derived class Line

#include "Point.hpp"
#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <string>


namespace ZhehaoLi {

    namespace CAD {
    
        // Constructor
        Line::Line(): Shape(), startPoint(), endPoint(1, 1){                                         // Default consturctor
//            std::cout << "Line: Default constructor called." << std::endl;
        }

        Line::Line(const Point &pt1, const Point &pt2): Shape(), startPoint(pt1), endPoint(pt2){     // Constructor with two arguments
//            std::cout << "Line: constructor called." << std::endl;
        }
    
        Line::Line(const Line &l): Shape(l), startPoint(l.startPoint), endPoint(l.endPoint){         // Copy constructor
//            std::cout << "Line: Copy constructor called." << std::endl;
        }

    
        // Destructor
        Line::~Line(){
//            std::cout << "Bye my line..." << std::endl;
        }


        // Member operator overloading
        Line & Line::operator = (const Line & source){
            if (this == &source) {
                return *this;
            }
            else{
                Shape::operator = (source);                                 // Assginment opertaor of base class
                startPoint = source.startPoint;
                endPoint = source.endPoint;
                return *this;
            }                                                               // Return this (current) object
        }


        // Accessing functions
        Point Line::StartPoint() const{
            return startPoint;
        }

        Point Line::EndPoint() const{
            return endPoint;
        }

        std::string Line::ToString() const{
            std::stringstream str_buffer;
            std::string str;
            std::string s = Shape::ToString();
            str_buffer << s << ", Line from " << startPoint.ToString() << " to " << endPoint.ToString();
            str = str_buffer.str();
            return str;
        }

        double Line::Length() const{
            return endPoint.Distance(startPoint);
        }
    
        void Line::Draw() const{
            std::cout << "Line is drawing now.." << std::endl;
        }


        // Modifers
        void Line::StartPoint(const Point &sp){
            startPoint = sp;
        }

        void Line::EndPoint(const Point &ep){
            endPoint = ep;
        }


        // Global operator overloading (Friend)
        std::ostream & operator << (std::ostream & os, const Line & l){
            os << "Line start from " << l.startPoint.ToString() << " to " << l.endPoint.ToString();
            return os;
        }


        //// Global operator overloading
        //std::ostream & operator << (std::ostream & os, const Line & l){
        //    os << l.ToString();
        //    return os;
        //}
    
    }
}



