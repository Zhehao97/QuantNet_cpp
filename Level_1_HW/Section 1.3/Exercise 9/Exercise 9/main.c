//
//  main.c
//  Exercise 9
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int x = 1;
    int y = 1;
//    int z = 1;
    x += y += x;
    
    printf("%d \n", (x < y)? y:x);          // number = 3
    printf("%d \n", (x < y)? x++:y++);      // number = 2
    printf("%d \n", x);                     // x = 3
    printf("%d \n", y);                     // y = 3
    
    return 0;
    
}
