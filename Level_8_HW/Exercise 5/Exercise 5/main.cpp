//
//  main.cpp
//  Exercise 5
//
//  Created by Zhehao Li on 2020/4/17.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Exercise 5 Statistical Functions

#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions.hpp>             // For non-member functions of distributions

#include <vector>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    using namespace boost::math;

    // 1. Create exponential distribution object
    double scaleParameter = 0.5;
    exponential_distribution<> myExponential(scaleParameter);          // Default type is 'double'
    cout << "Mean: " << mean(myExponential) << ", standard deviation: " << standard_deviation(myExponential) << endl;

    // 1.1 Distributional properties
    double x = 3.6;
    cout << "pdf: " << pdf(myExponential, x) << endl;
    cout << "cdf: " << cdf(myExponential, x) << endl;

    // 1.2 Choose precision
    cout.precision(10); // Number of values behind the comma

    // 1.3 Other properties
    cout << "\n*** Poisson Distribution ***\n";
    cout << "mean: "                    << mean(myExponential)              << endl;
    cout << "variance: "                << variance(myExponential)          << endl;
    cout << "median: "                  << median(myExponential)            << endl;
    cout << "mode: "                    << mode(myExponential)              << endl;
    cout << "kurtosis excess: "         << kurtosis_excess(myExponential)   << endl;
    cout << "kurtosis: "                << kurtosis(myExponential)          << endl;


    
    // 2. Poisson distribution
    double lmbda = 3.0;                                 // Mean
    poisson_distribution<> myPoisson(lmbda);            // Default type is 'double'

    double val = 13.0;
    cout << "Exponential pdf: " << pdf(myPoisson, val) << endl;
    cout << "Exponential cdf: " << cdf(myPoisson, val) << endl;

    vector<double> pdfList;
    vector<double> cdfList;

    double start = 0.0;
    double end = 10.0;
    long   N = 30;        // Number of subdivisions

    val = 0.0;
    double h = (end - start) / double(N);
    
    // Push the pdf and cdf value into vectors
    for (long j = 1; j <= N; ++j){
        pdfList.push_back(pdf(myPoisson, val));
        cdfList.push_back(cdf(myPoisson, val));

        val += h;
    }
    
    cout << "\n********\n" << endl;

    // Print the vector of pdf
    cout << "Poisson pdf:" << endl;
    for (long j = 0; j < pdfList.size(); ++j){
        cout << pdfList[j] << ", ";
    }

    cout << "\n********\n" << endl;

    // Print the vector of cdf
    cout << "Poisson cdf:" << endl;
    for (long j = 0; j < cdfList.size(); ++j){
        cout << cdfList[j] << ", ";
    }
    
    return 0;
}
