//
//  main.cpp
//  CPP_4.6
//
//  Created by Zhehao Li on 2020/4/2.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  STL Algorithm

#include <numeric>              // Numeric algorithms
#include <functional>           // Function objects -- Functors
#include <algorithm>            // STL algorithms
#include <vector>
#include <string>
#include <iostream>

using namespace std;



/* Generic functions that can be used with STL algorithms */
// Generic print function for vectors
template <typename Type> void print(const vector<Type> & l, const string & comment){
    
    typename vector<Type>::const_iterator i;        // must use a const iterator here -- passing argument is const reference
    
    cout << comment << ": ";
    for (i = l.begin(); i != l.end(); ++i){
        cout << *i << ",";
    }
    cout << endl;
}

// Modifier function
template <typename Type> void MultiplyByTwo(Type & t){
        t *= 2;
}

// Selector function
template <typename Type> Type Square(const Type & t){
        return t * t;
}



/*  Main program  */
int main(int argc, const char * argv[]) {
    
    /* A. NUMERIC ALGORITHMS */
    // Initialization
    int size = 4;
    vector<int> vec(size);                      // Copy constructor of template class vector
    for (int i = 0; i < vec.size(); ++i){
        vec[i] = i + 1;
    }
    vec[1] = 5;
    print(vec, string("original vector vec: "));

    // Accumulate: Computing the result of one sequence.
    int initVal = 1;                                            // Must be initialised to a value
    int acc1 = accumulate(vec.begin(), vec.end(), initVal);     // Add initVal to all elements
    cout << "Sum 1: " << acc1 << endl;

    // Multiply each element by initVal and sum them                            // multiplies<Type> -> a template class
    int acc2 = accumulate(vec.begin(), vec.end(), initVal, multiplies<int>());  // multiplies<int> -> a regular class of template class
    cout << "Sum 2: " << acc2 << endl;                                          // multiplies<int>() -> an object of class, acted like a function
            
    // Sums of products + initVal
    int ip1 = inner_product(vec.begin(), vec.end(), vec.begin(), initVal);
    cout << "Inner product1: " << ip1 << endl;
    
    // Using two predefined Function Object using inner and outer operations
    vector<int> vec2(vec);
    double ip2 = inner_product(vec.begin(), vec.end(), vec2.begin(), 1,
                               multiplies<int>(),       // inner
                               plus<int>());            // outer
    cout << "Inner product2: " << ip2 << endl;

    
    /* B. NONMODIFYING ALGORIHMS */
    // Count the number of elements equal to a given value.
    double val = 99;
    cout << "Number of elements equal to " << val << " = " << count(vec.begin(), vec.end(), val) << endl;

    // Serching for elements; find the first element in a container equal to a given value;
    int searchValue = 99;
    vector<int>::iterator posS = find(vec.begin(), vec.end(),  searchValue);

    // Test if value has been found
    if (posS != vec.end())
    {
        cout << "***Value: " << *posS << endl;
    }
    else
    {
        cout << "***Value not found\n";
    }

    
    /* C MODIFYING ALGORIHMS */
    // Modifier, user-defined function
    for_each(vec.begin(), vec.end(), MultiplyByTwo<int>);
    print(vec, string("Modifier, for_each(): "));

    // Modifier, user-defined function
    transform(vec.begin(), vec.end(), vec.begin(), Square<int>);    // Unary operation
    print(vec, string("Modifier, transform(): "));

    // Replacing elements
    int M = 10;
    vector<char> vecChar(M, 'd');

    char oldChar = 'd';
    char newChar = 'D';
    replace(vecChar.begin(), vecChar.end(), oldChar, newChar);
    print(vecChar, string("After replace (all):"));

    
    /* D. MUTATING ALGORITHMS */
    // Reversing the order of elements
    reverse(vec.begin(), vec.end());
    print(vec, string("Modifier, vector reversed: "));

    // Rotating elements in a sequence
    vector<int> myVec(8);
    for (int i = 0; i < myVec.size(); ++i)
    {
        myVec[i] = i + 1;
    }

    cout << "Number of shifts (< 0 to right, > 0 to left): ";
    int shift;
    cin >> shift;

    // Call 1 function?

    if (shift > 0){
//        template <class ForwardIterator>
//        void rotate (ForwardIterator first, ForwardIterator middle,
//                     ForwardIterator last);
        rotate(myVec.begin(), myVec.begin() + shift, myVec.end());
        print(myVec, string("Modifier, vector rotated: "));
    }
    else{
        rotate(myVec.begin(), myVec.end() + shift, myVec.end());
        print(myVec, string("Modifier, vector rotated: "));
    }
    
    return 0;
}
