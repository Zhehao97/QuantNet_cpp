//
//  main.cpp
//  CPP_2.4
//
//  Created by Zhehao Li on 2020/3/7.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#include "Complex.hpp"
#include <iostream>
using namespace std;

int main()
{

    Complex z1(-23.0, 5.3);
    Complex z2(2.0, 3.0);

    Complex z3 = z1 * z2;
    z3 = z2 + z1 * 2.0;
    Complex z4 = 2.0 * z3;
    Complex z5 = - z3;

    cout << z1;
    cout << z3;
    cout << z5; cout << "****\n";

    
    Complex z6 = z2 * 2.0;
    Complex z7 = 2.0 * z2;
    Complex z8 = z2 * 2.0;
    Complex z9= z6* z7;

    cout << z6;
    cout << z7;
    cout << z8;cout << "****\n";

    Complex z10 = z1.add(z2);                               // z1 + z2
    cout << z10;

    Complex z0(1.0, 2.0);
    z4 = z3 = z1 = z0;                                      // Reference !!!!!!!!!!!!!!!!
    cout << "Chain: " << z0 << z1 << z3 << z4;

    z4 += z1;                                               // Multiply z4 by z1 and modify it
    cout << z4;

    cout << "modulus: " << modul(z4) << endl;
    
    return 0;
}

