//
//  main.c
//  Exercise 1
//
//  Created by Zhehao Li on 2020/2/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Create a struct called Article

#include <stdio.h>
#include <string.h>                     // We need strcpy()

// Define a struct called Article
struct Article {
    long art_num;
    long qnty;
    char dscp[21];
};

void Print(struct Article * pp);

int main(int argc, const char * argv[]) {
    
    // Create a new object
    struct Article arti;
    
    // Initialising the contents of object
    arti.art_num = 849013543;
    arti.qnty = 232;
    strcpy(arti.dscp, "This is an article");
    
    // Passing the address of struct object
    Print(&arti);
    
    return 0;
}

void Print(struct Article * pp){
    // Print out the contents of Article object
    printf("Article number: %ld \n", pp->art_num);
    printf("Quantity: %ld \n", pp->qnty);
    printf("Description: %s \n", pp->dscp);
}
