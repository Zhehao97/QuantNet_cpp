 //
//  main.cpp
//  1 - Shared Pointers
//
//  Created by Zhehao Li on 2020/4/15.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test Shared Pointers

#include "Point.hpp"
#include "boost/shared_ptr.hpp"
#include <vector>
using namespace std;

/* These classes are an upgrade from raw pointers to shared pointers */
class C1{
private:
    //double* d; OLD WAY
    boost::shared_ptr<double> d;

public:
    C1(boost::shared_ptr<double> value) : d(value) {}           // Constructor
    virtual ~C1() { cout << "\n C1 destructor \n"; }              // Destructor
    void print() const { cout << "Value " << *d; }              // Access function
};


class C2{
private:
    //double* d; // OLD WAY
    boost::shared_ptr<double> d;

public:
    C2(boost::shared_ptr<double> value) : d(value) {}
    virtual ~C2() { cout << "\n C2 destructor \n"; }
    void print() const { cout << "Value " << *d; }
};


class D1{
private:
    boost::shared_ptr<Point> p;

public:
    D1(boost::shared_ptr<Point> value) : p(value) {}
    virtual ~D1() { cout << "\n D1 destructor \n";}
    void print() const { cout << "\nValue " << *p; }
};


class D2{
private:
    boost::shared_ptr<Point> p;

public:
    D2(boost::shared_ptr<Point> value) : p(value) {}
    virtual ~D2() { cout << "\n D2 destructor \n"; }
    void print() const { cout << "\nValue " << *p; }
};


class Base{
private:
    
public:
    Base() { }
    virtual ~Base() { cout << "Base destructor\n\n"; }
    virtual void print() const = 0;                           // Pure virtual member function
};


class Derived : public Base{ // Derived class
private:
        
public:
    Derived() : Base() { }
    ~Derived() { cout << "\nDerived destructor\n"; }
    void print() const { cout << "Derived object\n"; }
};


// Simple creator (FACTORY) function (工厂函数)
boost::shared_ptr<Base> createBase(){
    // In later versions return other derived types
    boost::shared_ptr<Base> result(new Derived());      // Create derived class Derived()

    return result;
}


void doIt(){
    {
        cout << "Built-in types:\n";
        boost::shared_ptr<double> commonValue(new double (3.1415));
        cout << "Reference count: " << commonValue.use_count() << endl;

        {
            C1 object1(commonValue);
            object1.print();
        }// C1 is destructed

        C2 object2(commonValue);
//        object2.print();
    }// C2 is destructed

    cout << "\nUser-defined types:\n";

    // Now with user-defined types, Create dynamic memory
    boost::shared_ptr <Point> myPoint (new Point(1.0, 23.3));
    
    cout << "Reference count: " << myPoint.use_count() << endl;
    {
        D1 point1(myPoint);
        cout << "Reference count: " << myPoint.use_count() << endl;
        D1 point2(myPoint);
        cout << "Reference count: " << myPoint.use_count() << endl;
        //point1.print();

    }// point1, point2 are destructed
    
    cout << "Reference count: " << myPoint.use_count() << endl;
    {
        D2 object3(myPoint);
        //object3.print();
        cout << "Reference count: " << myPoint.use_count() << endl;
    }// object3 is destructed
    
    cout << "Reference count: " << myPoint.use_count() << endl;


    // Use in STL containers
    typedef std::vector< boost::shared_ptr<Base> > ContainerType;
    typedef ContainerType::iterator iterator;

    
    // Create a vector of objects
    ContainerType con;
    const int N = 4;
    for (int j = 0; j < N; ++j)
    {
        con.push_back(createBase());
    }

    // Now iterate and print
    iterator myIter;
    for (myIter = con.begin(); myIter != con.end(); ++myIter)
    {

        (*myIter) -> print();
    }
    
    cout << "\ndoIt is ending..." << endl;
}// Automatically delete the elements in the vector con


int main(int argc, const char * argv[]) {
    // insert code here...
    doIt();
    return 0;
}
