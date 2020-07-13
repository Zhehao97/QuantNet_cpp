//
//  main.cpp
//  Exercise 7
//
//  Created by Zhehao Li on 2020/2/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test inline member functions

#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    // Create two double objects to for x- and y-coordinates
    double x;
    double y;
    
    // Ask the user for x- and y-coordinates
    cout << "Please enter the x- and y-coordinates:" << endl;
    cin >> x >> y;                                                          // Pass the value of input stream to objects
    
    // Create a Point object
    Point pt;                                                               // Initialize with default constructor
    pt.X(x);                                                                // Reset the value of x-coordinates
    pt.Y(y);                                                                // Reset the value of y-coordinates
    
    // Create a string object
    string str_pt;
    str_pt = pt.ToString();                                                 // Get the description of Point object pt
    
    cout << str_pt << endl;                                                 // Print the descriotion of Point object pt
    cout << "Point(" << pt.X() << "," << pt.Y() << ")" << endl;             // Print the coordinates of Point object pt
    
    // Create a new Point object to test the distance function
    Point pt2(3.0, 4.0);                                                    // Initialize with two values
    
    
    // Test the distance function
    cout << "The distance to Origin(0,0) is: " << pt.Distance() << endl;                    // Print the distance to origin
    cout << "The distance to " << pt2.ToString() << " is: " << pt.Distance(pt2) << endl;    // Print the distance to (3, 4)
    
    // Create a const point
    const Point cp(1.5, 3.9);                                               // A const object cannot change after declaring
    //cp.X(0.3);
    cout << cp.X() << endl;
    
    return 0;
}



//  With Copy Constructor:
//      1. Default constructor called once;
//      2. Constructor with value called twice;
//      3. Copy constructor wasn't called;
//      4. Destructor called three times;
//
//      Now the number of calls of Default constructor = Destructor

