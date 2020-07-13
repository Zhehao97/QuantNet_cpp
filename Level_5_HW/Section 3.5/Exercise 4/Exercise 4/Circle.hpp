//
//  Circle.hpp
//  Exercise 6
//
//  Created by Zhehao Li on 2020/2/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include "Point.hpp"
#include <string>

namespace ZhehaoLi {

    namespace CAD {
        
        class Circle: public Shape{
            
        private:
            CAD::Point centerPoint;
            double radius;
            
        public:
            // Constructor
            Circle();                                           // Default constructor           (*****)
            Circle(const Point &cp, const double &r);           // Consturctor with two arguments
            Circle(const Circle &c);                            // Copy constructor              (*****)

            // Destructor
            ~Circle();                                          // (*****)
            
            // Member operator overloading
            Circle & operator = (const Circle & source);        // Asignment operator            (*****)
            
            // Accessing functions
            CAD::Point CentralPoint() const;
            double Radius() const;
            double Diameter() const;
            double Area() const;
            double Circumference() const;
            std::string ToString() const;
            void Draw() const;
            
            // Modifiers
            void CentralPoint(const CAD::Point &cp);
            void Radius(const double &r);
            
            // Global Operator overloading
            friend std::ostream & operator << (std::ostream & os, const Circle & c);
            
        };

        // Global operator overloading
        //std::ostream & operator << (std::ostream & os, const Circle & c);    // Send to ostream
    
    }
}



#endif /* Circle_hpp */
