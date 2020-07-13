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
using namespace std;

// Constructor
Line::Line(){                                         // Default consturctor
    cout << "Line Default constructor called." << endl;
}

Line::Line(const Point &pt1, const Point &pt2){       // Constructor with two arguments
    startPoint = pt1;
    endPoint = pt2;
    cout << "Line Constructor called." << endl;
}

Line::Line(const Line &l){                            // Copy constructor
    startPoint = l.startPoint;
    endPoint = l.endPoint;
    cout << "Line Copy constructor called." << endl;
}

// Destructor
Line::~Line(){
    cout << "Bye my line..." << endl;
}


// Selectors
Point Line::StartPoint() const{
    return startPoint;
}

Point Line::EndPoint() const{
    return endPoint;
}

string Line::ToString() const{
    stringstream str_buffer;
    string str;
    str_buffer << "Line start from " << startPoint.ToString() << " to " << endPoint.ToString() << endl;
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




