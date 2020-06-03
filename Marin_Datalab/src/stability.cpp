#include "header.h"
#include <vector>


using namespace std;

bool stability(double h, double Re, double dt)
{
    vector<double> a = { h, Re * h * h / 4, 2 / Re };
    double min = a[0];
    if (min > a[1]) 
        min = a[1];
    if (min > a[2])
        min = a[2];
   
    if(dt > min)
    {
        cout << "Warning! dt should be less than "<< min << '/n';
        return 0;
    }
    return 1;

}

