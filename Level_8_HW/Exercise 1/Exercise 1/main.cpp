//
//  main.cpp
//  Exercise 1
//
//  Created by Zhehao Li on 2020/4/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "Array.hpp"
#include "ArrayException.hpp"
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "boost/shared_ptr.hpp"
#include <iostream>

namespace CAD = ZhehaoLi::CAD;
namespace CTN = ZhehaoLi::Containers;
namespace EXC = ZhehaoLi::Exception;

typedef boost::shared_ptr<CAD::Shape> ShapePtr;
typedef CTN::Array<ShapePtr> ShapeArray;


/* Print the reference count */
void PrintCount(const ShapePtr & sptr){
    std::cout << sptr -> ToString() << std::endl;
    std::cout << "Reference count:" << sptr.use_count() << "\n\n";
}

int main(int argc, const char * argv[]) {
    
    
    /* Create some Shape objects */
    CAD::Point  pt1(3.0, 4.0);
    CAD::Point  pt2(2.0, 8.0);
    
    /* Create some Shape shared pointers */
    ShapePtr ptr_1( new CAD::Point(9.99, 1.11));        // Point constructed with value
    ShapePtr ptr_2( new CAD::Line(pt1, pt2)   );        // Line constructed with value
    ShapePtr ptr_3( new CAD::Circle(pt2, 5.0) );        // Circle constructed with value
    
    // Print the reference count
    PrintCount(ptr_1);                                  // Reference count for (9.99, 1.11): 1
        
    {
        // SharedPtr copy constructed
        ShapePtr ptr_4(ptr_1);
        
        // Print the reference count
        PrintCount(ptr_1);                              // Reference count for (9.99, 1.11): 2
        
        {
            /* Create a Shape shared pointers array */
            ShapeArray Arr(4);
                
            // Inserting elements into array
            Arr[0] = ptr_1;                             // Reference count for (9.99, 1.11): 3
            Arr[1] = ptr_2;
            Arr[2] = ptr_3;
            Arr[3] = ptr_4;                             // Reference count for (9.99, 1.11): 4
            
            // Print the reference count
            PrintCount(ptr_1);
        }
        // Print the reference count
        PrintCount(ptr_1);                              // Reference count for (9.99, 1.11): 2
    }
    // Print the reference count
    PrintCount(ptr_1);                                  // Reference count for (9.99, 1.11): 1
    
    ptr_1.reset(new CAD::Point(pt1));               // Reference count for (9.99, 1.11): 0
                                                    // (9.99, 1.11) is destructed
    // Print the reference count
    PrintCount(ptr_1);                              // Reference count for pt1: 1
    
    return 0;
}
