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
using namespace std;


// Constructor
Point::Point(){                             // Default constructor
    m_x = 0.0;
    m_y = 0.0;
    cout << "Default constructor called." << endl;
}

Point::Point(double newX, double newY){     // Constructor with initialization
    m_x = newX;
    m_y = newY;
    cout << "Constructor called." << endl;
}


Point::Point(const Point &pt){              // Copy constructor
    m_x = pt.m_x;
    m_y = pt.m_y;
    cout << "Copy constructor called." << endl;
}


// Destructor
Point::~Point(){
    cout << "Bye my point..." << endl;
}


// Selector
double Point::X() const{
    return m_x;
}

double Point::Y() const{
    return m_y;
}

string Point::ToString() const{
    stringstream str_buffer;
    string str;
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

