//
//  main.c
//  Exercise 3
//
//  Created by Zhehao Li on 2020/2/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include <stdio.h>

#define PRD(a) ( printf("%d", a) )      // Print decimal
#define NL ( printf("\n") )             // Print new line

// Create and initialse array
int a[] = {0, 1, 2, 3, 4};

int main(int argc, const char * argv[]){
    
    int i;
    int* p;
    
    for (i = 0; i <= 4; i++) PRD( a[i] );                           // 1. Output: 0, 1, 2, 3, 4
    NL;
    
    for (p = &a[0]; p <= &a[4]; p++) PRD( *p );                     // 2. Output: 0, 1, 2, 3, 4
    NL;
    NL;
    
    for (p = &a[0], i = 0; i <= 4; i++) PRD( p[i] );                // 3. Output: 0, 1, 2, 3, 4
    NL;
    
    for (p = a, i = 0; p + i <= a + 4; p++, i++) PRD( *(p + i) );   // 4. Output: 0, 2, 4
    NL;
    NL;
    
    for (p = a + 4; p >= a; p--) PRD( *p );                         // 5. Output: 4, 3, 2, 1, 0
    NL;
    
    for (p = a + 4, i = 0; i <= 4; i++) PRD( p[-i] );               // 6. Output: 4, 3, 2, 1, 0
    NL;
    
    for (p = a + 4; p >= a; p--) PRD( a[p - a] );                   // 7. Output: 4, 3, 2, 1, 0
    NL;
    
    return 0;
}
