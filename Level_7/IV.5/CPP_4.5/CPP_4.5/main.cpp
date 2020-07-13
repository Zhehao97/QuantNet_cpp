//
//  main.cpp
//  CPP_4.5
//
//  Created by Zhehao Li on 2020/4/2.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test iterators of STL containers

#include <iostream>
#include <list>
using namespace::std;

void print(const list<int> & myList){           // const reference argument
//    list<int>::iterator i;                      // cannot compile
    list<int>::const_iterator i;                // must use const_iterator
    for (i = myList.cbegin(); i != myList.cend(); i++) {
        cout << *i << ",";
    }
}

int main(int argc, const char * argv[]) {
    int a[10] = {12, 3, 25, 7, 11, 213, 7, 123 ,29, -31};
    
    // List iterator
    list<int> list1;
    
    for (int i = 0; i < 10; i++) {
        list1.push_back(a[i]);
    }
    
    print(list1);
    
    return 0;
}
