//
//  main.cpp
//  CPP_1.9
//
//  Created by Zhehao Li on 2020/2/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  TestAggregates.cpp
//
//  Defining aggregate structures. We model data that pertains to plain options.
//  The struct can be used in pricing algorithms as a simple data store.

#include <iostream>
#include "OptionData.h"
using namespace std;

#define sqr(x) ( x * x )

union Name
{
  char firstName[10];
  char lastName[10];
};

struct MyStruct
{
  char c[5];
  short s;
};

char *my_strcpy(char *destination, char *source);

int main(int argc, const char * argv[]) {
    
    // 1.1 Creat a single object on the Heap
    int n = 1;
    OptionData* myData = (OptionData*)malloc(n * sizeof(OptionData));   // case void* to OptionData* (pointer)

    (*myData).K = 100.0;
    (*myData).T = 1.0;
    (*myData).r = 0.12;
    (*myData).sig = 0.1;
    (*myData).D = 0.03;
    (*myData).beta = 0.1;
    (*myData).type = +1;

    // 1.1 Print the OptionData struct
//    print(*myData);                   // if not print, the *myData doesn't generate, no need to destroy


    // 2.1 Creat a multiple objects on the Heap
    n = 4;
//    OptionData* myDataArray = (OptionData*)malloc(n * sizeof(OptionData));  // C style
    OptionData* myDataArray = new OptionData[n];                            // CPP style


    // 2.2 Intialise the array
    for (int j = 0; j < n; ++j) {

        myDataArray[j] = *myData;

        // Modify expiry
        myDataArray[j].T = double (j) + 0.5;
    }

    // 2.3 Print the array
    for (int j = 0; j < n; ++j) {

//        print(myDataArray[j]);    // If we use CPP style -- new to allocate object, it will geneerate no matter if they are printed (called)
    }

    // 3. Deallocate memory
    free(myData);               // C style
//    free(myDataArray);          // C style
    delete [] myDataArray;      // CPP style, multiple objects, use []
        
    return 0;
}



// strcpy function
char *my_strcpy(char *destination, char *source)
{
    char *start = destination;
 
    while(*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
 
    *destination = '\0'; // add '\0' at the end
    return start;
}
