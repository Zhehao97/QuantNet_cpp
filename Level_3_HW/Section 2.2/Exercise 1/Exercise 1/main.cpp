//
//  main.cpp
//  Exercise 1
//
//  Created by Zhehao Li on 2020/2/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test Point Class

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
    cin >> x >> y;                                                  // Pass the value of input stream to objects
    
    // Create a Point object
    Point pt;                                                       // Initialize with default constructor
    pt.SetX(x);                                                     // Reset the value of x-coordinates
    pt.SetY(y);                                                     // Reset the value of y-coordinates
    
    // Create a string object
    string str_pt;
    str_pt = pt.ToString();                                         // Get the description of Point object pt
    
    cout << str_pt << endl;                                                 // Print the descriotion of Point object pt
    cout << "Point(" << pt.GetX() << "," << pt.GetY() << ")" << endl;       // Print the coordinates of Point object pt
    
    return 0;
}
