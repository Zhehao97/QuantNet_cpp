//
//  main.c
//  Exercise 5
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "stdio.h"

int main(int argc, const char * argv[]) {
    
    int i = 5;
    int a, b;
    
    a = i--;
    printf("a = %d, i = %d \n", a, i); // a = 5, i = 4
    
    i = 5;
    b = --i;
    printf("b = %d, i = %d \n", b, i); // b = 4, i = 4
    
    return 0;
}
