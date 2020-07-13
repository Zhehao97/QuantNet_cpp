//
//  Point.cpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/2/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The definition of class Point

#include "Point.hpp"
#include <sstream>
#include <string>
#include <cmath>
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

double Point::DistanceOrigin(){
    return sqrt( pow(m_x, 2.0) + pow(m_y, 2.0) );
}

double Point::Distance(Point p){
    return sqrt( pow(m_x - p.m_x, 2.0) + pow(m_y - p.m_y, 2.0) );
}


// Modifiers
void Point::SetX(double newX){
    m_x = newX;
}

void Point::SetY(double newY){
    m_y = newY;
}
