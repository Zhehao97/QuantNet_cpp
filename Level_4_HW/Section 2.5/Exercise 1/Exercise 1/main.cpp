//
//  main.cpp
//  Exercise 1
//
//  Created by Zhehao Li on 2020/3/10.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Dynamically Creating Objects

#include "Point.hpp"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    Point * p1 = new Point;                     // Creat a Point object on heap using Default Constructor
    Point * p2 = new Point(3.0, 4.0);           // Creat a Point object on heap using Constructor with coordinates
    Point * p3 = new Point(*p2);                // Creat a Point object on heap using Copy Constructor
    
    cout << "Distance between (0, 0) and " << *p2 << " is: " << (*p2).Distance() << endl;
    cout << "Distance between " << *p1 << " and " << *p3 << " is: " << (*p1).Distance(*p3) << endl;
    
    delete p1;
    delete p2;
    delete p3;
    
    int arr_size;
    
    cout << "Plese enter the size of the array: " << endl;
    cin >> arr_size;
    
//    Point p_arr[arr_size];                  // No error appears
    Point * p4 = new Point[arr_size];       // ONLY Default Constructor can be used when create an array of objects?
    
//    cout << "Size of Point array is: " << sizeof(p_arr)/sizeof(Point) << endl;
    cout << "Size of *p4 is: " << sizeof(*p4) << endl;

    delete [] p4;
    
    return 0;
}
