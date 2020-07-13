//
//  main.cpp
//  CPP_4.3
//
//  Created by Zhehao Li on 2020/3/25.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Standard Template Library Practice


#include <vector>
#include <list>
#include <iostream>

using namespace std;                                            // STL is in namespace std


// Template function
template <typename Type> void print(const vector<Type> & vec){  // Vector<Type> is a template class of type
    
    cout << "Size of vector is " << vec.size() << "\n[";

    // You need to use typename to tell the compiler that vector<type>::iterator is a type,
    // otherwise the compiler will assume it's a variable or function.
    typename vector<Type>::const_iterator it;                   // vec is a const reference argument --> need const_iterator
    for (it = vec.cbegin(); it != vec.cend(); ++it){
        cout << *it << ",";                                     // Dereference the iterator to get the value in vector
    }

    cout << "]\n";
}


int main(int argc, const char * argv[]) {
    
    int n = 10;
    double val = 3.14;
    vector<double> vec2(n, val);                                // Create n copies of val

    cout << "Size of vector2 " << vec2.size() << endl;          // Vector<Type> is an array of Type

    print(vec2);

    
    vec2[0] = 2.0;                                              // Access elements of the vector by using the indexing operator []
    vec2[1] = 456.76;                                           // Change some values here and there

    long last_element = vec2.size() - 1;                        // The size of vector may be very huge
    vec2[last_element] = 55.66;
    vec2.push_back(16);                                         // Vector can only add / remove value at the back of array

    
    print(vec2);                                                // Test template function

    
    vec2.reserve(1000);                                         // Requests that the vector capacity be at least enough to contain n elements.
    cout << "Size of vector2 " << vec2.size() << endl;
    cout << "Capacity: " << vec2.capacity() << endl;
    cout << "Hardware Capacity: " << vec2.max_size() << endl;

    
    vec2.clear();                                               // Removes all elements in the vector (which are destroyed), leaving the container with a size of 0.
    cout << "Size of vector2 " << vec2.size() << endl;
    cout << "Capacity: " << vec2.capacity() << endl;
    cout << "Hardware Capacity: " << vec2.max_size() << endl;

    
    list<double> myList;                                        // List<Type> is a doubly-linked list of Type
    myList.push_back(22.0);                                     // Can add values at anywhere in the list
    myList.push_front(33);
    cout << myList.size() << endl;
    
    
    return 0;
}
