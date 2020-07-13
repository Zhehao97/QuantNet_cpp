//
//  main.c
//  Exercise 1
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include <stdio.h>


double minus(double a, double b);

int main(int argc, const char * argv[]) {
    
    double a = 134.53;
    double b = 4890.232;
    double diff;
    
    diff = minus(a, b);
    
    printf("The difference of a and b is: %lf \n", diff);
    
    return 0;
}


double minus(double a, double b){
    return (a - b);
}
