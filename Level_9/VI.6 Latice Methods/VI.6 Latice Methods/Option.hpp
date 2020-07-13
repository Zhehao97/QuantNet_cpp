//
//  Option.hpp
//  VI.6 Latice Methods
//
//  Created by Zhehao Li on 2020/5/19.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef Option_hpp
#define Option_hpp

#include "Vector.hpp"
#include <algorithm>

class Option{

public:
        
    double r;           // Interest rate
    double sig;         // Volatility
    double K;           // Strike price
    double T;           // Expiry date
    int type;           // 1 == Call, 2 == Put

    double payoff(double S)const{
        if (type == 1){
            return std::max(S - K, 0.0);
        }
        else{
            return std::max(K - S, 0.0);
        }
    }
    
    Vector<double, int> payoffVector(Vector<double, int> sarr){
        
        // We need the form of the lattice at the 'base' of the pyramid. This will be needed when we use backward induction
        Vector<double, int> result (sarr);
        
        for (int i = sarr.MinIndex(); i <= sarr.MaxIndex(); i++) {
            
            result[i] = payoff(sarr[i]);
        }
        return result;
    }
};

#endif /* Option_hpp */
