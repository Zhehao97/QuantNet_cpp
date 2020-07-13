//
//  main.c
//  Exercise 6
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "stdio.h"

int main(int argc, const char * argv[]) {
    
    unsigned int count_0 = 0;
    unsigned int count_1 = 0;
    unsigned int count_2 = 0;
    unsigned int count_3 = 0;
    unsigned int count_4 = 0;
    unsigned int count_other = 0;
    
    char c = '\0';
    
    printf("Please Enter some number");
    
    while ( (c = getchar()) != 26 && c != EOF ){
        
        switch (c) {
                
            case '0':
                count_0++;
                break;
                
            case '1':
                count_1++;
                break;
            
            case '2':
                count_2++;
                break;
                
            case '3':
                count_3++;
                break;
                
            case '4':
                count_4++;
                break;
                
            default:
                count_other++;
                break;
        }
    }
    
    printf("The Number of 0 is: %d \n", count_0);
    printf("The Number of 1 is: %d \n", count_1);
    printf("The Number of 2 is: %d \n", count_2);
    printf("The Number of 3 is: %d \n", count_3);
    printf("The Number of 4 is: %d \n", count_4);
    printf("The Number of other characters is: %d \n", count_other);
    
    return 0;
}
