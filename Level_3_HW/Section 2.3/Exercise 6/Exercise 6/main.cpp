//
//  main.cpp
//  Exercise 6
//
//  Created by Zhehao Li on 2020/2/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test the structure and interfaces of class Circle

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
        
    // Create a Line object
    Circle C1;                                                              // Intialize with Default constructor
    Point centerP = C1.CentralPoint();                                      // Get the default central point (0,0) of C1
    double r1 = C1.Radius();                                                // Get the default radius (=1) of C1
    
    // Print the default start point and end point of line l1
    cout << "Circle with center " << centerP.ToString() << " and radius " << r1 << endl;

    
    // Create a new Point objects and new radius
    Point cp(3.0, 4.0);                                                     // Initialize with two values
    double r2 = 3.0;
    
    // Reset the center point and radius of line C1
    C1.CentralPoint(cp);                                                    // Set the points of Circle C1
    C1.Radius(r2);
    
    // Print the description of line l1
    cout << C1.ToString();
     
    // Print the diameter of line l1
    cout << "Diameter of C1: " << C1.Diameter() << endl;
    
    // Print the circumference of line l1
    cout << "Circumference of C1: " << C1.Circumference() << endl;
    
    // Print the area of line l1
    cout << "Area of C1: " << C1.Area() << endl;
    
    return 0;
}


//      Point:
//          1. Default constructor called once          -- central point of Object C1
//          2. Copy constructor called once             -- centerP copy the central point of Object C1
//          3. Constructor with values called once      -- new points cp intialized with values
//          4. Destructor called six times
//
//      Circle:
//          1. Default constructor called once          -- create Object C1
//          2. Destructor called once
