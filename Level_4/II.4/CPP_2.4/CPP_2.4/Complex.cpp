//
//  Complex.cpp
//  CPP_2.4
//
//  Created by Zhehao Li on 2020/3/7.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  The implementation of class Complex

#include "Complex.hpp"
#include <iostream>
#include <cmath>
using namespace std;

/*----------------------------------------------------------------------------------------------------------------*/
// Friend functions
/*----------------------------------------------------------------------------------------------------------------*/

Complex mpi(const Complex & z){                                 // Multiply z by i == sqrt(-1)
    return Complex(-z.y, z.x);
}

/*----------------------------------------------------------------------------------------------------------------*/
// Constructors
/*----------------------------------------------------------------------------------------------------------------*/

Complex::Complex(){                                             // Default constructor
    x = 1.0;
    y = 0.0;
}

Complex::Complex(double real){                                  // Special case is real number
    x = real;
    y = 0.0;
}

Complex::Complex(double real, double imag){                     // Cartesian form
    x = real;
    y = imag;
}

Complex::Complex(const Complex & p){                            // Copy constructor
    x = p.x;
    y = p.y;
}

/*----------------------------------------------------------------------------------------------------------------*/
// Destructors
/*----------------------------------------------------------------------------------------------------------------*/

Complex::~Complex(){
    cout << "i like complex numbers, bye\n";
}

/*----------------------------------------------------------------------------------------------------------------*/
// Accessing functions
/*----------------------------------------------------------------------------------------------------------------*/

double Complex::xVal() const{                                           // Const function, accompany with const member
    return x;
}

double Complex::yVal() const{                                           // May not modify the data memeber
    return y;
}

double real(const Complex & c){
    return c.x;                                                         // Access real part of object
}

double imag(const Complex & c){
    return c.y;                                                         // Access imag part of object
}

double rad(const Complex & c){
    return sqrt(c.x * c.x + c.y * c.y);                                 // Distance from the origin
}

double modul(const Complex & c){
    return rad(c);
}

double abs(const Complex & c){
    return rad(c);                                                      // Absolutee value of complex number
}


/*----------------------------------------------------------------------------------------------------------------*/
// Member operator overloading
/*----------------------------------------------------------------------------------------------------------------*/

Complex Complex::operator - () const{                                   // The additive inverse of the current complex number
    return Complex(-x, -y);                                             // Return by value (unitary operator)
}   // (binary operator)

Complex & Complex::operator = (const Complex & c){
    if (this == &c) {                                                   // Avoid doing assign to myself
        return *this;
    }
    else{
        x = c.x;
        y = c.y;
        return *this;                                                   // Return by reference
    }
}   // To make it possible to chain the = and *= operators (E.g.: a=b+=c), it must return the “this” object.

Complex & Complex::operator += (const Complex &c){
    x += c.x;
    y += c.y;
    return *this;                                                       // 'this' is a pointer which contains the address of object
}   // (binary operator)

Complex & Complex::operator *= (const Complex &c){
    Complex tmp = (*this) * c;
    *this = tmp;
    return *this;
}   // (binary operator)

Complex & Complex::operator -= (const Complex &c){
    x -= c.x;
    y -= c.y;
    return *this;
}   // (binary operator)

Complex Complex::add(const Complex &c2) const{                          // Add two complex number
    Complex result;
    result.x = x + c2.x;
    result.y = y + c2.y;
    return result;                                                      // Return by value
}   // (binary operator)

Complex Complex::operator + (const Complex &c2) const{                  // Add two complex number
    return Complex(x + c2.x, y + c2.y);                                 // Copy the value of temporary object
}   // return by value

Complex Complex::operator - (const Complex &c2) const{                  // Subtract two complex numbers
    return Complex(x - c2.x, y - c2.y);                                 // Anonymous object
}   // (binary operator)

Complex Complex::operator * (const Complex &c2) const{                  // Multiply two complex numbers
    return Complex((x * c2.x) - (y * c2.y), (x * c2.y) + (y * c2.x));   // Copy the value of temporary object
}   // (binary operator)


/*----------------------------------------------------------------------------------------------------------------*/
// Functionality
/*----------------------------------------------------------------------------------------------------------------*/

double Complex::distance (const Complex & c2){
    return sqrt((x - c2.x) * (x - c2.x) + (y - c2.y) * (y - c2.y));     // Euclidean distance
}


/*----------------------------------------------------------------------------------------------------------------*/
// Global operator overloading
/*----------------------------------------------------------------------------------------------------------------*/

// Cannot return a Reference to a locally scoped object, since it gets destroyed when the function returns

Complex operator * (const Complex & c, double d){                       // Scaling by a double
    return Complex(c.x * d, c.y * d);                                   // Copy the value of temporary obejct
}

Complex operator * (double d, const Complex & c){                       // Scaling by a double
    return c * d;                                                       // Reuse already made operator
}

Complex operator + (const Complex & c, double d){
    return Complex(c.x + d, c.y);                                       // Return by value, a copy of temporary object
}

Complex operator + (double d, const Complex & c){
    return c + d;                                                       // Reuse already made operator
}

Complex operator - (const Complex & c, double d){
    return Complex(c.x - d, c.y);                                       // Return by value, cannot returny by refernce
}

Complex operator - (double d, const Complex & c){
    return - (c - d);                                                   // Reuse already made operator
}


ostream & operator << (ostream & os, const Complex & cmp){ // Print the complex number

	os << "[" << cmp.x << ", " << cmp.y << "]\n";
	return os;
}
