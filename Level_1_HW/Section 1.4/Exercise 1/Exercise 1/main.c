//
//  main.c
//  Exercise 1
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//
//


#include "stdio.h"

int main(int argc, const char * argv[]) {
    
    // initialize the counters of char, word, and line
    int char_count = 0;
    int word_count = 0;
    int line_count = 0;
    char c = '\0';
    
    int char_flag = 0;              // flag of char
    int space_flag = 0;             // flag of whitespace: space, tab and newline
    
    while ((c=getchar()) !=4 && c!=EOF)
    {
        if (c != ' ' && c != '\n' && c != '\t')
        {
            char_count++;           // any non-whitespace count as a character
            char_flag = 1;          // update the number of characters
            space_flag = 0;         // set the flag to 0
        }
        else
        {
            space_flag = 1;         // encounter a whitespace, set the flag to 1
            
            if (char_flag == 1) {
                word_count++;       // update the number of words
                char_flag = 0;
            }
            
            if (c == '\n') {
                line_count++;       // update the number of lines
            }
        }
    }
    
    printf("Number of Characters: %d \n", char_count);
    printf("Number of Words: %d \n", word_count);
    printf("Number of Lines: %d \n", line_count);
    
    return 0;
}

