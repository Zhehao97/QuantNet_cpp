//
//  main.cpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/3/10.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Creating Array of Pointers

#include "Point.hpp"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int max_size = 3;
    
    // Create an array of Point pointers with 3 elements on the heap
    Point ** ptr = new Point * [max_size];              // Allocate the memory for an array of Point pointers
    
    // Create for each element in the array a point on the heap
    ptr[0] = new Point(1.0, 2.0);                       // Allocate the memory for a Point object
    ptr[1] = new Point(3.0, 4.0);
    *(ptr+2) = new Point(5.0, 6.0);
    
    // Iterate the array and print each point in the array.
    for (int i = 0; i < max_size; i++) {
        cout << *ptr[i] << endl;
    }
    
    // Iterate the array again and delete each point in the array.
    for (int i = 0; i < max_size; i++) {
        delete ptr[i];                                  // Deallocate the memory for each Point object
    }
    
    delete [] ptr;                                      // Deallocate the memory for the array of pointers itself.
    
    return 0;
}




/*

Memory Layout:
                                            HEAP
        STACK         _________________________________________________
       ________       |                                               |
       |      |       |  --------------                               |
       |  ptr -------->  |   ptr[0]   | ---------> | Point object 1 | |
       |      |       |  --------------                               |
       |______|       |  |   ptr[1]   | ---------> | Point object 2 | |
                      |  --------------                               |
                      |  |   ptr[2]   | ---------> | Point object 3 | |
                      |  --------------                               |
                      |_______________________________________________|
 
 */
