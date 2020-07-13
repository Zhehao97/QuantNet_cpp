//
//  main.c
//  Exercise 4
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include <stdio.h>
#include <math.h>

void printnumber(int n);

int main(int argc, const char * argv[]) {
    
    int n = -342383102;
    printnumber(n);
    return 0;
}

void printnumber(int n){
    if (n < 0) {
        putchar('-');
        n = - n;
    }
    if (n / 10 != 0)
        printnumber(n / 10); // recursive
    putchar((n % 10) + '0');
}


