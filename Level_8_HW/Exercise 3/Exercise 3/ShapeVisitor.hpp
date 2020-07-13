//
//  ShapeVisitor.hpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/4/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef ShapeVisitor_hpp
#define ShapeVisitor_hpp

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "boost/variant.hpp"

namespace CAD = ZhehaoLi::CAD;

class ShapeVisitor: boost::static_visitor<void>{

private:
    double m_dx;            // distance to move along x
    double m_dy;            // distance to move along y
    
public:
    /* Constructor */
    ShapeVisitor();                                 // Default  constructor
    ShapeVisitor(double dx, double dy);             // Constructor with value
    ShapeVisitor(const ShapeVisitor & source);      // Copy consturctor
    
    /* Desturctor */
    ~ShapeVisitor();
    
    /* Accessing Functions */
    void operator () (CAD::Point  & pt) const;          // Move Point object
    void operator () (CAD::Line   & ln) const;          // Move Line object
    void operator () (CAD::Circle & cr) const;          // Move Circle object
    
    /* Modifier Functions */
    ShapeVisitor & operator = (const ShapeVisitor & source);      // Assignment operators
};



#endif /* ShapeVisitor_hpp */
