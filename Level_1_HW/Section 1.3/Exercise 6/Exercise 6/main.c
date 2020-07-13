//
//  main.c
//  Exercise 6
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "stdio.h"
int main(int argc, const char * argv[]) {

    int a = -1230;
    int b = a >> 2;
    int flag = a * b;
    
    printf("original number is: %d \n", a);
    printf("number right shifted by 2: %d \n", b);
    
    printf("%s shift is performed \n", (flag > 0)? "Arithmetic" : "Logical");
    
    a = 248932;
    b = a >> 2;
    flag = a * b;
    
    printf("original number is: %d \n", a);
    printf("number right shifted by 2: %d \n", b);
    
    printf("%s shift is performed \n", (flag > 0)? "Arithmetic" : "Logical");
    
    return 0;
}
