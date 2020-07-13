//
//  Line.cpp
//  Exercise 5
//
//  Created by Zhehao Li on 2020/2/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The definition of Line

#include "Point.hpp"
#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <string>


namespace ZhehaoLi {

    namespace CAD{
    
        // Constructor
        Line::Line(){                                                       // Default consturctor
            startPoint = Point();                                           // Calling default constructor of Point
            endPoint = Point(1, 1);
        //    cout << "Line Default constructor called." << endl;
        }

        Line::Line(const Point &pt1, const Point &pt2){                     // Constructor with two arguments
            startPoint = pt1;
            endPoint = pt2;
        //    cout << "Line Constructor called." << endl;
        }

        Line::Line(const Line &l){                                          // Copy constructor
            startPoint = l.startPoint;
            endPoint = l.endPoint;
        //    cout << "Line Copy constructor called." << endl;
        }

    
        // Destructor
        Line::~Line(){
        //    cout << "Bye my line..." << endl;
        }


        // Member operator overloading
        Line & Line::operator = (const Line & source){                       // (*****)
            startPoint = source.startPoint;
            endPoint = source.endPoint;
            return *this;                                                    // Return this (current) object
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
            str_buffer << "Line start from " << startPoint.ToString() << " to " << endPoint.ToString();
            str = str_buffer.str();
            return str;
        }

        double Line::Length() const{
            return endPoint.Distance(startPoint);
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



