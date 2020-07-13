//
//  main.c
//  Exercise 4
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
// the application of the ?: operator

#include "stdio.h"

int main(int argc, const char * argv[]){
    // initialize the status of marital
    int married = 1;
    // judge whether the guys or lady is married
    printf("Marital status is: %s \n", married? "unmarried" : "married");
}
