//
//  main.cpp
//  Exercise 1
//
//  Created by Zhehao Li on 2020/3/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
        

//    /* Test Line Class */
//    using ZhehaoLi::CAD::Line;                              // Declaration for using a single class (Line).
//
//    Line L1;

    
    /* Test Circle class */
    namespace ZLCAD = ZhehaoLi::CAD;                        // Creating a shorter alias for the ZhehaoLi::CAD namespace.

    ZLCAD::Circle C1;
    
    
    std::cout << "Time to say goodbye..." << std::endl;

    return 0;
}



/* Without colon syntax (Line):
 
 Point: Default constructor called.     A Point obj 1 created by system
 Point: Default constructor called.     A Point obj 2 created by system
 Point: Default constructor called.     Line.startPoint initialized with default value
 Bye my Point...                        A Point obj 1 deleted
 Point: Constructor called.             Line.endPoint initialized with given value
 Bye my Point...                        A Point obj 2 deleted
 Line Default constructor called.
 Time to say goodbye...                 Program is over
 Bye my line...
 Bye my Point...                        Line.startPoint deleted
 Bye my Point...                        Line.endPoint deleted
 Program ended with exit code: 0
 
 */


/* With colon syntax (Line):
 
 Point: Default constructor called.     Line.startPoint created and initialized
 Point: Constructor called.             Line.endPoint created and initialized with given value
 Line Default constructor called.       Line obj created
 Time to say goodbye...
 Bye my line...
 Bye my Point...
 Bye my Point...
 
 */



/* Without colon syntax (Circle):
 
 Point: Default constructor called.
 Point: Default constructor called.
 Bye my Point...
 Circle Default constructor called.
 Time to say goodbye...
 Bye my circle...
 Bye my Point...
 
 */

/* With colon syntax (Circle):
 
 Point: Default constructor called.
 Circle Default constructor called.
 Time to say goodbye...
 Bye my circle...
 Bye my Point...
 
 */
