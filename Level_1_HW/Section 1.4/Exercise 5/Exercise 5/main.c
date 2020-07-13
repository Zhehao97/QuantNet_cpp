//
//  main.c
//  Exercise 5
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "stdio.h"

int main(int argc, const char * argv[]) {
    
    float temp_start = 0;
    float temp_end = 19;
    float temp_step = 1;
    
    float Celsius = temp_start;
    float Fahrenheit = 9 * Celsius / 5 + 32;
    
    printf("Celsius, Fahrenheit \n");
    
    while (Celsius <= temp_end) {
        
        printf("%7.1f, %.1f \n", Celsius, Fahrenheit);
        
        Celsius += temp_step;
        Fahrenheit += 9 * temp_step / 5;
    }
}
