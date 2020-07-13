//
//  main.c
//  Exercise 2
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  the application of recurrsive

#include <stdio.h>

long long factorials(unsigned int n);

int main(int argc, const char * argv[]) {
    
    unsigned int N = 34;
    // output the results
    printf("The factorials of %d is: %lld \n", N, factorials(N));
    return 0;
}

// the factorials calculation function
long long factorials(unsigned int n){
    if (n == 0) {
        return 1;                       // stop recursive
    }
    else{
        return (n * factorials(n-1));   // recursive function
    }
}
