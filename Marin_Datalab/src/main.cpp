#include "header.h"

int main(int argc, char **argv)
{
    //constant variables
    const double epsilon = 1e-6;
    const double Re = 100;
    const int tmax = 3;
    const double dt = 0.001;
    const int itmax = 1000;
    const double h = 1.0/n;
    const double omega = interpolate();
    const double beta = omega*h*h/(4*dt);

    //chooses flow situation
    int ch = choice();

	Field F;

	Field_Val E;

    if (stability(h, Re, dt))
    {
	    std::cout << "stability: success" << std::endl;
		calculateFlowField(Re, h, tmax, dt, F, E, itmax, beta, epsilon, ch);
    }
    else
    {
    	std::cout << "stability: failure" << std::endl;
    }
    
    return 0;

}   
