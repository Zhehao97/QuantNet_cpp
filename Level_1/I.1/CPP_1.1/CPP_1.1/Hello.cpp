//
//  Hello.cpp
//  CPP_1.1
//
//  Created by Zhehao Li on 2020/2/8.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

// Preprocessor for include files
#include <stdio.h>             // C style I/O
#include <iostream>            // C++ style I/O using operator overloading
using namespace std;           // The C++ logical collection of functions

void hello_C()
{
    printf("Hello Quantnet, C style\n");
}

void hello_CPP()
{
    // Using (binary) operator overloading
    cout << "Hello Quantnet, C++ style \n";
}
