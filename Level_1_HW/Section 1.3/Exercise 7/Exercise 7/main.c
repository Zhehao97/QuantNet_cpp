//
//  main.c
//  Exercise 7
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "stdio.h"

int main(int argc, const char * argv[]) {
    
    int a = 234;
    int n = 4;
    
    if (n <= 0) {
        printf("Error! The power to the 2 should be positive number.");
    }
    else{
        printf("%d times 2 to the power %d equals to: %d \n", a, n, a << n);
    }

    return 0;
}
