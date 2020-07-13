//
//  main.c
//  Exercise 2
//
//  Created by Zhehao Li on 2020/2/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Create a function Length() to compute the length of the string.

#include <stdio.h>
#include <string.h>
#define MAXLINE 30

// String Length Declaration
int Length(char str[]);

int main(int argc, const char * argv[]) {
    
    char string[MAXLINE + 1];       // Line of maxium 30 chars + '\0'
    int c;                          // The input character
    int i = 0;                      // The counter
    
    // Print intro text
    printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);
    
    // Get the characters
    while ( (c = getchar()) != EOF && i < MAXLINE ) {
        
        // Append entered character to string
        if (c != '\n') {
            string[i++] = (char) c;
        }
    }
    string[i] = '\0';               // String must be closed with '\0'
    printf("String length is %d (Length) \n", Length(string));
    printf("String length is %d (strlen) \n", (unsigned)strlen(string));      // Check if the Length() matches with strlen()
    
    return 0;
}


int Length(char str[]){
    int idx = 0;                    // Counter and Index of String
    while (str[idx] != '\0') {      // Loop until '\0' appears
        idx++;                      // Increase the counter
    }
    return idx;                     // Return the counter
}
