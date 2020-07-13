//
//  main.c
//  Exercise 2
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "stdio.h"

int main(int argc, const char * argv[]) {
    
    float height;
    float base;
    float surf;
    
    printf("Please enter the height:");
    scanf("%f", &height);
    
    printf("Please enter the base:");
    scanf("%f", &base);
    
    surf = (height * base)/2;
    
    printf("The surface of triangle is: %f \n", surf);
    
    return 0;
}

