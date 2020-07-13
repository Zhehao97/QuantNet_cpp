//
//  main.cpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/4/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Exercise 3 Variant

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "ShapeVisitor.hpp"
#include "boost/variant.hpp"
#include <iostream>
#include <string>
namespace CAD = ZhehaoLi::CAD;

typedef boost::variant<CAD::Point, CAD::Line, CAD::Circle> ShapeType;

/* Variant of Shapes Function */
ShapeType CreateShape(){
    std::cout << "Which shape would you like to create (Point, Line, Circle):" << std::endl;
    std::string str;
    std::cin >> str;
    if (str == "Point") {
        return CAD::Point();
    }
    else if (str == "Line"){
        return CAD::Line();
    }
    else if (str == "Circle"){
        return CAD::Circle();
    }
    else{
        throw -1;
    }
}


int main(int argc, const char * argv[]) {
    
    // 1. Test shape variant
    ShapeType myVariant = CreateShape();
    std::cout << myVariant << std::endl;
    
    // 2. Test exception
    CAD::Line ln;
    try{
        ln = boost::get<CAD::Line>(myVariant);
    }
    catch (boost::bad_get & err){
        std::cout << "Error: " << err.what() << std::endl;
    }
    
    // 3. Test static visitor of variant
    ShapeVisitor myVisitor(3.3, 2.2);
    boost::apply_visitor(myVisitor, myVariant);
    std::cout << myVariant << std::endl;
    
    return 0;
}
