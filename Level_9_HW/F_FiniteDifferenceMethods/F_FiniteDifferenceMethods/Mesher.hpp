//
//  Mesher.hpp
//  VI.5 Finite Difference Methods
//
//  Created by Zhehao Li on 2020/5/15.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Declaratioin of class Mesher (网格器) for Finte Difference Method

#ifndef Mesher_hpp
#define Mesher_hpp

#include <vector>

class Mesher{
    
private:
    double a, b;                            // location in space
    
public:
    // Constructors ----------------------------------------------------
    // Default constructor
    Mesher(): a(0.0), b(1.0){
        //
    }
    
    // Constructor with value
    Mesher(double A, double B): a(A), b(B){
        //
    }
    
    // Copy constructor
    Mesher(const Mesher & source): a(source.a), b(source.b){
        //
    }
    
    // Destructor ------------------------------------------------------
    ~Mesher(){
        //
    }
    
    
    // Assignement Operator --------------------------------------------
    Mesher & operator = (const Mesher & source){
        
        if (this == &source) {
            return *this;
        }
        a = source.a;
        b = source.b;
        return *this;
    }
    
    // Accessing Functions --------------------------------------------
    std::vector<double> Xarr(int MaxStep){
        
        double h = (b - a) / double (MaxStep);
        std::vector<double> result(MaxStep + 1, a);
        
        for (unsigned int j = 1; j < result.size(); j++) {
            result[j] = result[j-1] + h;
        }
        return result;
    }
    
};

#endif /* Mesher_hpp */
