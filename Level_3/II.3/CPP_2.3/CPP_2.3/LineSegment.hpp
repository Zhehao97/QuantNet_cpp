//
//  LineSegment.hpp
//  CPP_2.3
//
//  Created by Zhehao Li on 2020/2/26.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef LineSegment_hpp
#define LineSegment_hpp

#include "Point.hpp"
#include <iostream>
using namespace std;

class LineSegment {
    
private:
    Point startPoint;           // e1
    Point endPoint;             // e2
    
public:
    // Constructor
    LineSegment();                                      // Default constructor
    LineSegment(const Point &p1, const Point &p2);      // Initialize with two points
    LineSegment(const LineSegment &l);                  // Copy constructor
    
    // Destructor
    virtual ~LineSegment();
    
    // Accessing functions
    Point Start() const;                                // May not change the data member
    Point End() const;                                  // May not change the data member
    
    // Modifers
    void Start(const Point &pt);                        // Call by reference, may not change the original object
    void End(const Point &pt);                          // Overloading function name
    
};


#endif /* LineSegment_hpp */
