#include "header.h"
#include <time.h>
#include <math.h>


int main(int argc, char **argv)
{
    //constant variables
    const double epsilon = 1e-6;
    const double Re = 1000;
    const int tmax = 30;
    const double dt = 0.001;
    const int itmax = 2000;
    const double h = 1.0/n;
    const double omega = interpolate();
    const double beta = omega*h*h/(4*dt);

    //chooses flow situation
    int ch = choice();

    std::string stab;
    if (stability(h,Re,dt))
        stab = "success";
    else
        stab = "failure";


    std::cout << "stability: " << stab <<std::endl;


    Field F;

    Field_Val E;

    calculateFlowField(Re,h, tmax,dt, F,E, itmax, beta, epsilon, ch);

    return 0;

}
