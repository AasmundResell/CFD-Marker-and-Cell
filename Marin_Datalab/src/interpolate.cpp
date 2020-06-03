#include "header.h"
#include <algorithm>

/*
the SOR subroutine gives different weights to the Gauss-Seidel and the previous iterate
//Its purpose is to change the iterate during calculations to increase the computational time
Omega has to be bigger than one to speed up the convergence, thus the name over relaxation
*/


//Linear interpolation to find the omega parameter

double interpolate()
{

    const int size = 9;
    int nn[9] = {0, 5, 10, 20, 30, 40, 60, 100, 500};
    double oo[9] = {1.7, 1.78, 1.86, 1.92, 1.95, 1.96, 1.97, 1.98, 1.99};

    double omega;
    //returns the closest previous position's
    int pos = static_cast<int>(std::upper_bound(nn, nn + size, n) - nn-1);
    std::cout << "position: " << pos  <<std::endl;
      //linear interpolation to obtain omega

    omega = oo[pos+1] +  static_cast<int>((double)n-nn[pos+1])*(oo[pos]-oo[pos+1])/((double)nn[pos]-(double)nn[pos+1]);
    std::cout << "Omega: " << omega  <<std::endl;


    return omega;
}
