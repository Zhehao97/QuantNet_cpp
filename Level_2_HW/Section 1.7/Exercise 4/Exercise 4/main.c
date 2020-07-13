//
//  main.c
//  Exercise 4
//
//  Created by Zhehao Li on 2020/2/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  A function DayName() which can print the day of a given day-number.

#include <stdio.h>

void DayName(int i);                                            // Declare the function;

int main(int argc, const char * argv[]) {
    
    int idx = 1;                                                // Initialize day number;
    DayName(idx);                                               // Call the function;
        
    return 0;
}

void DayName(int i){                                            // Call by reference -- pointer to array of 10 ints;
    
    char Days[7][10] = {"Sunday", "Monday",
                        "Tuesday", "Wednesday",
                        "Thursday", "Friay", "Saturday"
                        };                                      // Creat a constant char multiple dimension array;
    
    if ( (i < 8) && (i > 0) ) {                                 // Check if the day-number is between 1 and 7;
    printf("Day %d is %s \n", i, Days[i - 1] );                 // Print the results;
    }
    else{
        printf("Error, the day doesn't exist! \n");             // Raise error;
    }
}
