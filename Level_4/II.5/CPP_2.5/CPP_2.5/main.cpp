//
//  main.cpp
//  CPP_2.5
//
//  Created by Zhehao Li on 2020/3/9.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Memory Scenarios
//
//  Lifecycle management on the heap. Normal scenarios.
//
//  Some exceptions:
//
//      1. No memory allocated for a ptr
//      2. Accessing null/undefined ptr
//      3. Ptr goes out of scope but pointee (memory has been cleaned up)
//      4. 'Double' delete
//

#include <iostream>
using namespace std;

struct A{                                           // simple class (aggregate of data)
    
    int k;
    
    A(int val = 0): k(val) {}                       // Deafult consturctor, Colon syntax: Initialize k from val outside the body of function
    A(const A& source): k(source.k + 2) {}          // Copy constructor

    ~A() { cout << "Bye object of struct A, value: " << k << endl;}
};

/*
Differences between a class and a struct in C++ are that structs have default public members and bases and classes have default private members and bases. Both classes and structs can have a mixture of public, protected and private members, can use inheritance and can have member functions.

I would recommend using structs as plain-old-data structures without any class-like features, and using classes as aggregate data structures with private data and member functions.
*/


int main(int argc, const char * argv[]) {
    /*
    // Single variable
    {
        A * a = new A();                            // Default constructor
        delete a;
    }
    cout << "phase 1" << endl;
    
    {
        A* a = new A();
        delete a;                                   // Memory leak if not delete
    }
    cout << "Phase 2" << endl;
    
    {
        A * a = new A();
        delete a;
//        delete a;                                 // Runtime Error if delete again
    }
    cout << "phase 3" << endl;
    
    
    // Arrays
    {
        int N = 4;
        A * arr = new A[N];
        delete [] arr;
    }
    cout << "phase 4" << endl;
    
    {
        int N = 4;
        A * arr = new A[N];
//        delete arr;                                 // 1st element deleted, then RT error
        delete [] arr;
    }
    cout << "phase 4A" << endl;
    
    {
        int N = 200000;
        A * arr = new A[N];
        delete [] arr;
    }                                               // Not delete at all, huge meory leak
    cout << "phase 4B" << endl;
    */
    
    // Another Pointer
    {
        A * a = new A();
        A * b = a;                                  // a and b share the same reference (pointee) as the other
//        delete a;
        delete b;                                   // It's the pointed-to memory that delete the allocates; can only delete that once
    }
    cout << "Phase 5" << endl;

    {
        A * a = new A(1);
        A b(*a);                                    // Copy constructor, call by value (derefence of a)
        delete a;
    }
    cout << "Phase 6" << endl;

    {
        A * a = new A();
        A b(*a);
        delete a;                                   // Not delete a
    }
    cout << "Phase 7" << endl;

    {
        A * a = new A();
        A * b = a;
        cout << a << endl;
        cout << b << endl;
        delete a;
    }
    cout << "Phase 8" << endl;
    
    int * pi;                                       // No memory allocated
    
//    pi = NULL;
    pi = new int;
    *pi = 100;
    cout << *pi << endl;

    delete pi;
//    delete pi;                                      // cannot delete twice
    
    return 0;
}
