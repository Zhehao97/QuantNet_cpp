//
//  main.c
//  Exercise 8
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "stdio.h"

int main(int argc, const char * argv[]) {

    int x=2;
    int y;
    int z;
    
    x *= 3 + 2;
    printf("x = %d \n", x); // x = 10
    
    x *= y = z = 4;
    printf("x = %d \n", x); // x = 40
    
    x = y == z;
    printf("x = %d \n", x); // x = 1
    
    return 0;
    
}
