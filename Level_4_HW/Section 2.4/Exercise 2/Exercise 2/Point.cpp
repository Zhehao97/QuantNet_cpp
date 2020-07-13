//
//  Point.cpp
//  Exercise 4
//
//  Created by Zhehao Li on 2020/2/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The definition of class Point

#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>


// Constructor
Point::Point(){                                                         // Default constructor
    m_x = 0.0;
    m_y = 0.0;
//    cout << "Default constructor called." << endl;
}

Point::Point(double newX, double newY){                                 // Constructor with initialization
    m_x = newX;
    m_y = newY;
//    cout << "Constructor called." << endl;
}


Point::Point(const Point &pt){                                          // Copy constructor
    m_x = pt.m_x;
    m_y = pt.m_y;
//    cout << "Copy constructor called." << endl;
}


// Destructor
Point::~Point(){
//    cout << "Bye my point..." << endl;
}


// Member operator overloading
Point Point::operator - () const{
    return Point(-m_x, -m_y);                                           // Return by value
}

Point Point::operator * (double factor) const{
    return Point(m_x * factor, m_y * factor);                           // Return a copy of current object
}

Point Point::operator + (const Point & p) const{                        // Const argument ensures the arguments passed may not be changed
    return Point(m_x + p.m_x, m_y + p.m_y);                             // Const function may not modify the data member of object
}

bool Point::operator == (const Point & p) const{
    return (m_x == p.m_x && m_y == p.m_y);                              // Equally compare operator
}

Point & Point::operator = (const Point & source){                       // (*****)
    m_x = source.m_x;
    m_y = source.m_y;
    return *this;                                                       // Return this (current) object
}

Point & Point::operator *= (double factor){
    m_x *= factor;
    m_y *= factor;
    return *this;                                                       // To chain the = and *= operators (E.g.: a=b+=c), return the “this” object.
}


// Accessing functions
double Point::X() const{
    return m_x;
}
double Point::Y() const{
    return m_y;
}

std::string Point::ToString() const{
    std::stringstream str_buffer;
    std::string str;
    str_buffer << "Point(" << m_x << "," << m_y << ")";
    str = str_buffer.str();
    return str;
}

double Point::Distance() const{
    return sqrt( pow(m_x, 2.0) + pow(m_y, 2.0) );
}

double Point::Distance(const Point &pt) const{                          // (function overloading)
    return sqrt( pow(m_x - pt.m_x, 2.0) + pow(m_y - pt.m_y, 2.0) );
}


// Modifiers
void Point::X(double newX){                                             // (function overloading)
    m_x = newX;
}
void Point::Y(double newY){                                             // (function overloading)
    m_y = newY;
}

// Global operator overloading
std::ostream & operator << (std::ostream & os, const Point & p){
    os << p.ToString();
    return os;
}

