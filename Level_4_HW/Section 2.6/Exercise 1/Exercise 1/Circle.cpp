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
        Circle::Circle(){                                       // Default constructor
            centerPoint = Point();                              // Calling deafult constructor of point
            radius = 1.0;
        //    cout << "Circle Default constructor called." << endl;
        }

        Circle::Circle(const Point &cp, const double &r){       // Consturctor with two arguments
            centerPoint = cp;
            radius = r;
        //    cout << "Circle Constructor called." << endl;
        }

        Circle::Circle(const Circle &c){                        // Copy constructor
            centerPoint = c.centerPoint;
            radius = c.radius;
        //    cout << "Circle Copy constructor called." << endl;
        }


        // Destructor
        Circle::~Circle(){
        //    cout << "Bye my circle..." << endl;
        }


        // Member operator overloading
        Circle & Circle::operator = (const Circle & source){                 // (*****)
            centerPoint = source.centerPoint;
            radius = source.radius;
            return *this;                                                    // Return this (current) object
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
            str_buffer << "Circle with center " << centerPoint.ToString() << " and radius " << radius;
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

