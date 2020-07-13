//
//  main.cpp
//  Exercise 1
//
//  Created by Zhehao Li on 2020/4/3.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include <list>
#include <vector>
#include <map>
#include <string>
#include <iostream>

int main(int argc, const char * argv[]) {
    
    std::list<double> my_list;
    std::vector<double> my_vec;
    std::map<std::string, double> my_map;
    
    my_list.push_back(10.1);
    my_list.push_front(20.2);
    my_list.push_back(30.3);
    
    std::cout << "The front of list: " << my_list.front() << "\n";
    std::cout << "The back of list: " << my_list.back() << "\n";
    
    for (int i = 0; i < 8; i++) {
        my_vec.push_back(i + 1.1);
    }
    
    for (int i = 0; i < my_vec.size(); i++) {
        std::cout << my_vec[i] << ",";
    }
    std::cout << std::endl;
    
    // First insert function version (P && val), return pair<iterator, bool>
    my_map.insert( std::pair<std::string, double>("hello", 123.45) );
    my_map.insert( std::pair<std::string, double>("world", 345.67) );
    
    // Second insert function version (hint position, P && val), return iterator
    // Notice that this is just a hint and does not force the new element to be inserted at that position
    std::map<std::string, double>::const_iterator it = my_map.end();
    my_map.insert( it, std::pair<std::string, double>("c++", 987.65) );
    
    // Third insert function version (InputIterator_first, InputIterator_last), no return
    std::map<std::string, double> another_map;
    another_map.insert(my_map.begin(), my_map.find( "world" ));
    
    // Ouput
    std::map<std::string, double>::const_iterator itt;
    for (itt = my_map.begin(); itt != my_map.end(); itt++) {
        std::cout << itt -> first << " => " << itt -> second << "\n";
    }
    
    for (itt = another_map.begin(); itt != another_map.end(); itt++) {
        std::cout << itt -> first << " => " << itt -> second << "\n";
    }
    
    std::cout << "hello => " << another_map[ "hello" ] << std::endl;
    
    return 0;
}
