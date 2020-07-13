//
//  main.c
//  Exercise 1
//
//  Created by Zhehao Li on 2020/2/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Application of Input and Output using getchar() and putchar()

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int c;                                                  // Creat a int object
    
    while ( (c = getchar()) != 1 ){
        putchar(c);                                         // Output all the char in the (line) buffer.
    }
    printf("\nCTRL+A is correct ending\n");                 // On Mac OS, ENTER should be typed after CTRL-A to end the loop.
    
    return 0;
}
