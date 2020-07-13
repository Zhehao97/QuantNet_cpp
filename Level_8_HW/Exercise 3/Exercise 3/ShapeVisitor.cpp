//
//  ShapeVisitor.cpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/4/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "ShapeVisitor.hpp"

/* Constructor */
ShapeVisitor::ShapeVisitor(): m_dx(1.0), m_dy(1.0), boost::static_visitor<>() {}
ShapeVisitor::ShapeVisitor(double dx, double dy): m_dx(dx), m_dy(dy), boost::static_visitor<>() {}
ShapeVisitor::ShapeVisitor(const ShapeVisitor & source): m_dx(source.m_dx), m_dy(source.m_dy), boost::static_visitor<>() {}


/* Destructor */
ShapeVisitor::~ShapeVisitor() {};


/* Accessing Functions */
void ShapeVisitor::operator() (CAD::Point & pt) const{
    pt.X( pt.X() + m_dx );
    pt.Y( pt.Y() + m_dy );
}
void ShapeVisitor::operator() (CAD::Line & ln) const{
    ln.StartPoint( ln.StartPoint() + CAD::Point(m_dx, m_dy) );
    ln.EndPoint( ln.EndPoint() + CAD::Point(m_dx, m_dy) );
}
void ShapeVisitor::operator() (CAD::Circle & cr) const{
    cr.CentralPoint( cr.CentralPoint() + CAD::Point(m_dx, m_dy) );
    // Radius remains the same
}


/* Modifier Functions */
ShapeVisitor & ShapeVisitor::operator=(const ShapeVisitor & source){
    if (this == &source) {
        return *this;
    }
    else{
        m_dx = source.m_dx;
        m_dy = source.m_dy;
        return *this;
    }
}

