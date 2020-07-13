//
//  main.cpp
//  Exercise 3
//
//  Created by Zhehao Li on 2020/4/4.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  STL Algorithms

#include <list>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

/* A Global Function */
bool IsSmall (double i) { return (i < 26.2); }      // --> Called by Function Pointer


/* A Class Overloaded the Round Bracket Operator */
class IsSMALL{
private:
    int my_benchmark;
public:
    // Constructor
    IsSMALL(int n): my_benchmark(n) {}
    
    // Operator overload
    bool operator() (int arr_num) const{            // --> Called by Function object
        return (arr_num < my_benchmark);
    }
};


int main(int argc, const char * argv[]) {
    
    std::list<double> my_list;
    std::vector<double> my_vec;
    std::map<std::string, double> my_map;
    
    /* Fill the value of list */
    my_list.push_back(10.1);
    my_list.push_front(20.2);
    my_list.push_back(30.3);
    
    /* Fill the value of vector */
    for (int i = 0; i < 8; i++) {
        my_vec.push_back(3 * i + 11.1);
    }
    
    /* Fill the value of map */
    // First insert function version (P && val), return pair<iterator, bool>
    my_map.insert( std::pair<std::string, double>("hello", 12.345) );
    my_map.insert( std::pair<std::string, double>("world", 23.456) );
    
    // Second insert function version (hint position, P && val), return iterator
    std::map<std::string, double>::const_iterator it = my_map.end();
    my_map.insert( it, std::pair<std::string, double>("c++", 9.876) );
    
    // Third insert function version (InputIterator_first, InputIterator_last), no return
    std::map<std::string, double> another_map;
    another_map.insert(my_map.begin(), my_map.find( "world" ));
    
    /* Output */
    long list_count = count_if (my_list.begin(), my_list.end(), IsSmall);       // Pass by Function Pointer
    long vec_count = count_if (my_vec.begin(), my_vec.end(), IsSmall);          // Pass by Function Pointer
    long map_count = count_if (my_map.begin(), my_map.end(), IsSmall);          // Pass by Function Pointer
    
    std::cout << "my_list contains " << list_count  << " values samller than 26.2.\n";
    std::cout << "my_vec contains " << vec_count  << " values samller than 26.2.\n";
//    std::cout << "my_map contains " << map_count  << " values samller than 26.0.\n";

    double bchmark = 26.2;
    list_count = count_if (my_list.begin(), my_list.end(), IsSMALL(bchmark));   // Pass by Function Object (Functor)
    vec_count = count_if (my_vec.begin(), my_vec.end(), IsSMALL(bchmark));      // Pass by Function Object (Functor)
//    map_count = count_if (my_map.begin(), my_map.end(), IsSMALL(bchmark));      // Pass by Function Object (Functor)
    
    std::cout << "my_list contains " << list_count  << " values samller than " << bchmark << "\n";
    std::cout << "my_vec contains " << vec_count  << " values samller than " << bchmark << "\n";
//    std::cout << "my_map contains " << map_count  << " values samller than " << bchmark << "\n";

    return 0;
}
