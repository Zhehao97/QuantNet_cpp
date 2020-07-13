//
//  main.cpp
//  Exercise 5
//
//  Created by Zhehao Li on 2020/2/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test the structures and interfaces of class Line

#include "Point.hpp"
#include "Line.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
        
    // Create a Line object
    Line l1;                                                                // Intialize with Default constructor
    Point l1_pt1 = l1.StartPoint();                                         // Get the default start point (0,0) of l1
    Point l1_pt2 = l1.EndPoint();                                           // Get the default end point (0,0) of l2
    
    // Print the default start point and end point of line l1
    cout << "Line start from " << l1_pt1.ToString() << " to " << l1_pt2.ToString() << endl;
    
    // Create two new Point objects
    Point pt1(3.0, 4.0);                                                    // Initialize with two values
    Point pt2(6.0, 8.0);
    
    // Reset the start point and end point of line l1
    l1.StartPoint(pt1);                                                     // Set the points of line l1
    l1.EndPoint(pt2);
    
    // Print the description of line l1
    cout << l1.ToString();
     
    // Print the length of line l1
    cout << "Length of l1: " << l1.Length() << endl;
    
    return 0;
}


//      Point:
//          1. Default constructor called twice         -- start and end point of Object l1
//          2. Copy constructor called twice            -- l1_pt1, l2_pt2 copy the start and end point of Object l1
//          3. Constructor with values called twice     -- new points pt1, pt2 intialized with values
//          4. Destructor called six times
//
//      Line:
//          1. Default constructor called once          -- create Object l1
//          2. Destructor called once
