//
//  StackEmptyException.hpp
//  Exercise 5
//
//  Created by Zhehao Li on 2020/3/27.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef StackEmptyException_hpp
#define StackEmptyException_hpp

#include "StackException.hpp"

namespace ZhehaoLi {

    namespace Exception {
        
        class StackEmptyException: public StackException{};
    
    }
}
#endif /* StackEmptyException_hpp */
