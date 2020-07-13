//
//  main.cpp
//  Exercise 2
//
//  Created by Zhehao Li on 2020/4/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Exercise 2 Tuple

#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_io.hpp"
#include <iostream>
#include <string>

typedef boost::tuple<std::string, unsigned int, long> Person;       // (name, age, length cm)

void PrintPerson(const Person & p){
    std::cout << p << std::endl;
    std::cout << "Name:"   << p.get<0>() << ", ";
    std::cout << "Age:"    << p.get<1>() << ", ";
    std::cout << "Length:" << p.get<2>() << "\n\n";
}

int main(int argc, const char * argv[]) {
    
    // Create some Person objects
    Person p1(std::string("Bruce"), 46, 177);
    Person p2(std::string("Daniel"), 26, 182);
    Person p3(std::string("Lee"), 60, 186);
    
    // Output these objects
    PrintPerson(p1);
    PrintPerson(p2);
    PrintPerson(p3);
    
    // Increment the age of Daniel
    for (int i = 0; i < 3; i++) {
        p2.get<1>() += 3;
        PrintPerson(p2);
    }
    
    return 0;
}
