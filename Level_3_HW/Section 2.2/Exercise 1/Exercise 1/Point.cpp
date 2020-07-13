//
//  Point.cpp
//  Exercise 1
//
//  Created by Zhehao Li on 2020/2/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  This file is the definitioin of class Point

#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


// Constructor
Point::Point(){                 // Default constructor
    m_x = 0.0;
    m_y = 0.0;
}


// Destructor
Point::~Point(){}


// Selector
double Point::GetX(){
    return m_x;
}

double Point::GetY(){
    return m_y;
}

string Point::ToString(){
    stringstream str_buffer;
    string str;
    str_buffer << "Point(" << m_x << "," << m_y << ")";
    str = str_buffer.str();
    return str;
}


// Modifiers
void Point::SetX(double newX){
    m_x = newX;
}

void Point::SetY(double newY){
    m_y = newY;
}
