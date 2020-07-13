//
//  main.c
//  Exercise 1
//
//  Created by Zhehao Li on 2020/2/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Create a function Swap() using Pointer

#include <stdio.h>

// function to swap two int number
void swap(int* x, int* y){
    
    int temp;               // create a int object to store the value
    temp = *x;               // store the value of x
    *x = *y;                  // swap the value, the address of x doen't change
    *y = temp;               // swap the value, the address of y doen't change
}

int main(int argc, const char * argv[]) {
    
    // initialising the data
    int i = 123;
    int j = 456;
    
    // before swaping
    printf("Before Swaping \n");
    printf("i = %d \n", i);
    printf("j = %d \n", j);
    
    // swap
    swap(&i, &j);
    
    // after swaping
    printf("After Swaping \n");
    printf("i = %d \n", i);
    printf("j = %d \n", j);
    
    return 0;
}
