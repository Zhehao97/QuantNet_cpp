//
//  main.c
//  Exercise 4
//
//  Created by Zhehao Li on 2020/2/12.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "stdio.h"

int main(int argc, const char * argv[]) {
    
    float temp_start = 0;
    float temp_end = 300;
    float temp_step = 20;
    
    float Fahrenheit = temp_start;
    float Celsius = 5 * (Fahrenheit - 32) / 9;
    
    printf("Fahrenheit, Celsius \n");
    
    while (Fahrenheit <= temp_end) {
        
        printf("%10.1f, %.1f \n", Fahrenheit, Celsius);
        
        Fahrenheit += temp_step;
        Celsius += 5 * temp_step / 9;
    }
}
