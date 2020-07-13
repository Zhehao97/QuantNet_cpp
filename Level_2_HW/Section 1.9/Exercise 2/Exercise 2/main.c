//
//  main.c
//  Exercise 2
//
//  Created by Zhehao Li on 2020/2/20.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Application of Input and Output to file.


#include <stdio.h>

 #define BUFLENGTH 255                                      // Buffer size should be at least 255 to accommodate the old maximum filepath size.

int main(int argc, const char * argv[]) {
    
    int c;                                                  // Create a int object to store the char
    char buffer[BUFLENGTH];                                 // Creeat a char array object to store the name of file
    FILE * fp;                                              // Create a file pointer
    
    printf("Please enter the file name: \n");               // Display the infomation

    gets_s(buffer, sizeof(buffer));                         // Simply use gets_s() instead of scanf() for the filename,
                                                            // which automatically discard the newline from the input buffer.

//    scanf("%s", buffer);                                    // Read the file name
//    while ( (getchar()) != '\n');                           // Flushes the standard input (clears the input buffer)
    
    fp = fopen(buffer, "w");                                // Open a file, only write
    
    while ( (c = getchar()) != 1 ){
        fputc(c, fp);                                       // Output all the char in the (line) buffer to file
    }
    printf("\nCTRL+A is correct ending\n");                 // On Mac OS, ENTER should be typed after CTRL-A to end the loop.
    
    fclose(fp);
    
    return 0;
}


// fgets(): It reads a line from the specified stream and stores it into the string pointed to by str. It stops when either (n-1) characters are read, the newline character is read, or the end-of-file is reached, whichever comes first.
    
    // 1. It is safe to use because it checks the array bound.

// gets(): Reads characters from the standard input (stdin) and stores them as a C string into str until a newline character or the end-of-file is reached.

    // 1. It is not safe to use because it does not check the array bound.
