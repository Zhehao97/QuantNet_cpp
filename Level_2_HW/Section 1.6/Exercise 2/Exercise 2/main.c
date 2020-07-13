//
//  main.c
//  Exercise 2
//
//  Created by Zhehao Li on 2020/2/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The Application of Preprocessor
//  Define the MaxValue Marcos in headerfile

#include <stdio.h>
#include "Defs.h"

int main(int argc, const char * argv[]) {
    
    // initialising the variables
    int a = 15;
    int b = 4;
    int c = 12;
    
    // print out the max value among 2, 3 values seperately
    printf("Max of (%d, %d) is: %d \n", a, b, MAX2(a, b));              // Marco calls
    printf("Max of (%d, %d, %d) is: %d \n", a, b, c, MAX3(a, b, c));    // Marco calls
    
    return 0;
}
