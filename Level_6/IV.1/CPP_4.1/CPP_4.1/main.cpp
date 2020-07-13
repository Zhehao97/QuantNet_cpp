//
//  main.cpp
//  CPP_4.1
//
//  Created by Zhehao Li on 2020/3/25.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test of Generic Programming

#include "GenericInequalities.cpp"              // Needed because it is templated
#include <iostream>                             // Console input and output
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    

//    int d1, d2;
//    double d1, d2;
    string d1, d2;
    
    cout << "Give the first numberic object: ";          // Prompt the user for input.
    cin >> d1;
    cout << "Give the second numberic object: ";
    cin >> d2;

    char c;    // Character type
    cout << "Which function a) Max() or b) Min()? ";
    cin >> c;
    
    if (c == 'a'){
//        cout << "Max value is: " << Max<int>(d1, d2) << endl;
//        cout << "Max value is: " << Max<double>(d1, d2) << endl;
        cout << "Max value is: " << Max<string>(d1, d2) << endl;
    }
    else{
//        cout << "Min value is: " << Min<int>(d1, d2) << endl;
//        cout << "Min value is: " << Min<double>(d1, d2) << endl;
        cout << "Min value is: " << Min<string>(d1, d2) << endl;
    }

    long dA = 12334; long dB = 2; long dC = -3;
    cout << "\nMax and min of three numeric object: " << endl;
    cout << "Max value is: " << Max<long>(dA, dB, dC) << endl;
    cout << "Min value is: " << Min<long>(dA, dB, dC) << endl;
    
    return 0;
}
