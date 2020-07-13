//
//  Circle.cpp
//  Exercise 6
//
//  Created by Zhehao Li on 2020/2/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "Point.hpp"
#include "Circle.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#define _USE_MATHS_DEFINES


namespace ZhehaoLi {

    namespace CAD{
        
        // Constructor
        Circle::Circle(): Shape(), centerPoint(), radius(1.0){                                           // Default constructor
//            std::cout << "Circle: Default constructor called." << std::endl;
        }

        Circle::Circle(const Point &cp, const double &r): Shape(), centerPoint(cp), radius(r){           // Consturctor with two arguments
//            std::cout << "Circle: constructor called." << std::endl;
        }

        Circle::Circle(const Circle &c): Shape(c), centerPoint(c.centerPoint), radius(c.radius){          // Copy constructor
//            std::cout << "Circle: Copy constructor called." << std::endl;
        }


        // Destructor
        Circle::~Circle(){
            std::cout << "Bye my circle..." << std::endl;
        }


        // Member operator overloading
        Circle & Circle::operator = (const Circle & source){
            if (this == &source) {
                return *this;
            }
            else{
                Shape::operator = (source);                                 // Assignment operator of base class
                centerPoint = source.centerPoint;
                radius = source.radius;
                return *this;
            }                                                               // Return this (current) object
        }


        // Acessing functions
        Point Circle::CentralPoint() const{
            return centerPoint;
        }

        double Circle::Radius() const{
            return radius;
        }

        double Circle::Diameter() const{
            return (2 * radius);
        }

        double Circle::Area() const{
            return (M_PI * pow(radius, 2.0));
        }

        double Circle::Circumference() const{
            return (2 * M_PI * radius);
        }

        std::string Circle::ToString() const{
            std::stringstream str_buffer;
            std::string str;
            std::string s = Shape::ToString();
            str_buffer << s << ", Circle with center " << centerPoint.ToString() << " and radius " << radius;
            str = str_buffer.str();
            return str;
        }



        // Modifiers
        void Circle::CentralPoint(const Point &cp){
            centerPoint = cp;
        }

        void Circle::Radius(const double &r){
            radius = r;
        }


        // Global operator overloading (Friend)
        std::ostream & operator << (std::ostream & os, const Circle & c){
            os << "Circle with center " << c.centerPoint.ToString() << " and radius " << c.radius;
            return os;
        }


        //// Global operator overloading
        //std::ostream & operator << (std::ostream & os, const Circle & c){
        //    os << c.ToString();
        //    return os;
        //}

    }
}

