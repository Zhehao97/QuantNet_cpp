//
//  main.c
//  Exercise 3
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int x;
    
    x = -3 + 4 * 5 - 6;
    printf("x = %d \n", x); // x = 11
     
    x = 3 + 4 % 5 - 6;
    printf("x = %d \n", x); // x = 1
    
    x = -3 * 4 % - 6 / 5;
    printf("x = %d \n", x); // x = 0
    
    x = (7 + 6) % 5 / 2;
    printf("x=%d\n", x); // x = 1.5
}
