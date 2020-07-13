//
//  main.cpp
//  VI.4 Monte Carlo Simulation
//
//  Created by Zhehao Li on 2020/5/4.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test for Monte Carlo Simulation on option pricing
// HardCoded.cpp
//
//  We take CEV model with a choice of the elaticity parameter
//  and the Euler method. We give option price and number of times
//  S hits the origin.
//


#include "OptionData.hpp"
#include "RNG/NormalGenerator.hpp"
#include "Geometry/Range.cpp"
#include <cmath>
#include <iostream>

template <class T> void print(const std::vector<T>& myList)
{  // A generic print function for vectors
    
    std::cout << std::endl << "Size of vector is " << myList.size() << "\n[";

    // We must use a const iterator here, otherwise we get a compiler error.
    typename std::vector<T>::const_iterator i;
    for (i = myList.begin(); i != myList.end(); ++i)
    {
            std::cout << *i << ",";

    }

    std::cout << "]\n";
}

namespace SDEDefinition
{ // Defines drift + diffusion + data

    OptionData* data;                // The data for the option MC

    double drift(double t, double X)
    { // Drift term
    
        return (data->r)*X; // r - D
    }

    
    double diffusion(double t, double X)
    { // Diffusion term
    
        double betaCEV = 1.0;
        return data->sig * pow(X, betaCEV);
        
    }

    double diffusionDerivative(double t, double X)
    { // Diffusion term, needed for the Milstein method
    
        double betaCEV = 1.0;
        return 0.5 * (data->sig) * (betaCEV) * pow(X, 2.0 * betaCEV - 1.0);
    }
} // End of namespace


int main()
{
    std::cout <<  "1 factor MC with explicit Euler\n";
    OptionData myOption;
    myOption.K = 65.0;
    myOption.T = 0.25;
    myOption.r = 0.08;
    myOption.sig = 0.3;
    myOption.type = -1;    // Put -1, Call +1
    double S_0 = 60;
    
    long N = 100;
    std::cout << "Number of subintervals in time: ";
    std::cin >> N;

    // Create the basic SDE (Context class)
    Range<double> range (0.0, myOption.T);
    double VOld = S_0;
    double VNew = S_0;

    std::vector<double> x = range.mesh(N);
    

    // V2 mediator stuff
    long NSim = 50000;
    std::cout << "Number of simulations: ";
    std::cin >> NSim;

    double k = myOption.T / double (N);
    double sqrk = sqrt(k);

    // Normal random number
    double dW;
    double price = 0.0;    // Option price

    // NormalGenerator is a base class
    NormalGenerator * myNormal = new BoostNormal();

    using namespace SDEDefinition;
    SDEDefinition::data = &myOption;

    std::vector<double> res;
    int coun = 0; // Number of times S hits origin

    // A.
    for (long i = 1; i <= NSim; ++i)
    { // Calculate a path at each iteration
            
        if ((i/10000) * 10000 == i)
        {// Give status after each 1000th iteration

                std::cout << i << std::endl;
        }

        VOld = S_0;
        for (unsigned long index = 1; index < x.size(); ++index)
        {

            // Create a random number
            dW = myNormal->getNormal();
                
            // The FDM (in this case explicit Euler)
            VNew = VOld  + (k * drift(x[index-1], VOld))
                        + (sqrk * diffusion(x[index-1], VOld) * dW);

            VOld = VNew;

            // Spurious values
            if (VNew <= 0.0) coun++;
        }
            
        double tmp = myOption.myPayOffFunction(VNew);
        price += (tmp)/double(NSim);
    }
    
    // D. Finally, discounting the average price
    price *= exp(-myOption.r * myOption.T);

    // Cleanup; V2 use scoped pointer
    delete myNormal;

    std::cout << "Price, after discounting: " << price << ", " << std::endl;
    std::cout << "Number of times origin is hit: " << coun << endl;

    return 0;
}
