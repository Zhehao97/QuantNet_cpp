//
//  main.cpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/4/4.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Template function STL iterators

#include <list>
#include <vector>
#include <map>
#include <iostream>


// General Template Function (one parameter)
template <typename Container> double Sum(const Container & my_arr){
    double S = 0;
    typedef typename Container::value_type Con_Type;                    // Define a type name
    if (typeid(Con_Type) == typeid(double)) {                           // Check if the value type of container is double
        typename Container::const_iterator it;                          // create an const iterator
        for (it = my_arr.begin(); it != my_arr.end(); it++) {
            S += *it;
        }
    }
    return S;
}

// Specialized Template Function (one parameter) for Map
template <typename Key, typename Value> double Sum(const std::map<Key, Value> & my_arr){
    double S = 0;
    if (typeid(Value) == typeid(double)) {                              // Check if the value type of container is double
        typename std::map<Key, Value>::const_iterator it;               // create an const iterator
        for (it = my_arr.begin(); it != my_arr.end(); it++) {
            S += it -> second;
        }
    }
    return S;
}



// General Template Function (two parameter)
template <typename InputIterator> double Sum(InputIterator first, InputIterator last){
    double S = 0;
    typedef typename InputIterator::value_type Iter_Type;               // Define a type name
    if (typeid(Iter_Type) == typeid(double)) {                          // Check if the value type of iterator is double
        if (first != last) {                                            // Check if the address is the same
            while (first != last) {
               S += *first;
               first++;
           }
       }
    }
    return S;
}


// Specialized Template Function (two parameter) for Map
template <typename Key, typename Value> double Sum(typename std::map<Key, Value>::const_iterator first,
                                                   typename std::map<Key, Value>::const_iterator last){
    double S = 0;
    if (typeid(Value) == typeid(double)) {                              // Check if the value type of container is double
        if (first != last) {                                            // Check if the address is the same
            while (first != last) {
                S += first -> second;
                first++;
            }
        }
    }
    return S;
}



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
        my_vec.push_back(i + 1.1);
    }
    
    /* Fill the value of map */
    // First insert function version (P && val), return pair<iterator, bool>
    my_map.insert( std::pair<std::string, double>("hello", 123.45) );
    my_map.insert( std::pair<std::string, double>("world", 345.67) );
    
    // Second insert function version (hint position, P && val), return iterator
    std::map<std::string, double>::const_iterator it = my_map.end();
    my_map.insert( it, std::pair<std::string, double>("c++", 987.65) );
    
    // Third insert function version (InputIterator_first, InputIterator_last), no return
    std::map<std::string, double> another_map;
    another_map.insert(my_map.begin(), my_map.find( "world" ));
    
    /* Output */
    // General template func (one parameter)
    std::cout << Sum(my_list) << std::endl;
    std::cout << Sum(my_vec) << std::endl;
    
    // Specialized template func (one parameter)
    std::cout << Sum(my_map) << std::endl;
    
    // General template func (two parameter)
    std::cout << Sum(my_list.begin(), my_list.end()) << std::endl;
    std::cout << Sum(my_vec.begin(), my_vec.end()) << std::endl;
    
    // Specialized template func (two parameter)
    std::cout << Sum<std::string, double>(my_map.begin(), my_map.end()) << std::endl;

    
    return 0;
}
