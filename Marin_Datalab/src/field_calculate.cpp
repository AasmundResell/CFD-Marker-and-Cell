#include "header.h"
using namespace std;

void calculateFlowField(double Re,double h, int tmax, double dt, Field& V, Field_Val& U,
 int itmax, double beta, double epsilon, int choice)
{
    int t, iflag, iter;

    int step = 1;
    double* div = new double(0.0);

    //VTF-Files
    std::ofstream file;
    std::ofstream fileResP;
    std::ofstream fileResPSI;
    std::ofstream fileResV;

    //Force-File
    std::ofstream fileResForce;
    fileResForce.open("force.txt");

    if (!fileResForce)
        std::cout << "file not found";

    make_VTF_files(file, fileResP, fileResPSI, fileResV);

    for (t = 0; t <= tmax/dt; t++) //main time loop
    {
        calVel(h, Re, dt, V);
        for (iter = 1; iter <= itmax; iter++) //Applying boundary conditions for the velocities
        {
            if (choice == 1)
            {
                cavityBoxBC(V);
            }
            if (choice == 2)
            {
                flowAroundSquareBC(V);
            }
            if (choice == 3)
            {
                flowOverPlateBC(V);
            }
            
            piter(h, dt, beta, epsilon, V, iflag, div); //calculating new pressure

            if (iflag == 0) { break; }
            
        }
        if (iter >= itmax)
        {
            printf("Warning! Time t = %f, iter = %d ,div = %f\n" ,t*dt ,iter, *div) ;
        }
        else
        {
            printf("Time t = %f iter = %d \n",t*dt, iter);
        }

        if( t % 100 == 0)
        {
            calculate_average(V, U);

            streamfunction(V, U, h);

            write_results(U, file, fileResP, fileResPSI, fileResV, step);

            step++;
        }

        calculateForce(choice,V,fileResForce);

    }

    delete(div);

    append_VTF_steps(file, fileResP, fileResPSI, fileResV);

    fileResForce.close();

}


