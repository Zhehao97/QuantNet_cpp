//
//  LineSegment.cpp
//  CPP_2.3
//
//  Created by Zhehao Li on 2020/2/26.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "LineSegment.hpp"
#include <cmath>

LineSegment::LineSegment(){}                                    // Default constructor

LineSegment::LineSegment(const Point &p1, const Point &p2){     // Intializing with two points
    startPoint = p1;
    endPoint = p2;
}

LineSegment::LineSegment(const LineSegment &l){                 // Copy constructor
    startPoint = l.startPoint;
    endPoint = l.endPoint;
}

LineSegment::~LineSegment(){                                   // Destructor
    cout << "Bye my line segement..." << endl;
}

// Accessing functions
Point LineSegment::Start() const{
    return startPoint;
}

Point LineSegment::End() const{
    return endPoint;
}

// Modifiers
void LineSegment::Start(const Point &pt){
    startPoint = pt;
}

void LineSegment::End(const Point &pt){
    endPoint = pt;
}
