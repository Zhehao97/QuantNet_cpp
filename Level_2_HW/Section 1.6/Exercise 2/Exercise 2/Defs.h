//
//  Defs.h
//  Exercise 2
//
//  Created by Zhehao Li on 2020/2/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The Application of Preprocessor
//  Define the MaxValue Marcos in headerfile


#ifndef Defs_h
#define Defs_h

#define MAX2(x, y) ( (x) > (y) ? (x) : (y) )                        // create a marco that computes the max value given two arguments
#define MAX3(x, y, z) ( (MAX2(x, y)) > (z) ? (MAX2(x, y)) : (z) )   // create a marco that computes the max value given three arguments

#endif /* Defs_h */
