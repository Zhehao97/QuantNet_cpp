//
//  main.c
//  Exercise 3
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  the application of switch-case statement


#include "stdio.h"

int main(int argc, const char * argv[]) {
    
    // initialize the counters of char, word, and line
    int char_count = 0;
    int word_count = 0;
    int line_count = 0;
    char c = '\0';
    
    int char_flag = 0;                  // flag of char
    int space_flag = 0;                 // flag of whitespace: space, tab and newline
    

    while ((c=getchar()) !=4 && c!=EOF){
        
        switch (c) {
            case ' ':                   // c = space
                if (char_flag == 1) {   // if the previous charater is non-whitespace
                    word_count++;       // update number of word
                    char_flag = 0;      // update the flag of char
                }
                space_flag = 1;         // update the flag of whitespace
                break;
                
            case '\t':                  // c = tab
                if (char_flag == 1) {   // if the previous charater is non-whitespace
                    word_count ++;      // update number of word
                    char_flag = 0;      // update the flag of char
                }
                space_flag = 1;         // update the flag of whitespace
                break;
                
            case '\n':                  // c = newlinee
                if (char_flag == 1) {   // if the previous charater is non-whitespace
                    word_count ++;      // update number of word
                    char_flag = 0;      // update the flag of char
                }
                line_count++;           // update the flag of whitespace
                break;
            
            case EOF:
                break;
                
            default:
                char_count++;           // c = non-whitespace char
                char_flag = 1;          // update the flag of char
                space_flag = 0;         // update the flag of space
                break;
        }
    }
    
    // output the results
    printf("Number of Characters: %d \n", char_count);
    printf("Number of Words: %d \n", word_count);
    printf("Number of Lines: %d \n", line_count);
    
    return 0;
}
