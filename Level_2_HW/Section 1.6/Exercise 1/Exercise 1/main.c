//
//  main.c
//  Exercise 1
//
//  Created by Zhehao Li on 2020/2/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The Application of Preprocessor
//  Define the Print Marcos in headerfile

#include <stdio.h>
#include "Defs.h"

int main(int argc, const char * argv[]) {
    
    // initialising two int variables
    int x = 3;
    int y = 7;
    
    // print Marco calls
    PRINT1(x);
    PRINT2(x, y);
    
    return 0;
}
