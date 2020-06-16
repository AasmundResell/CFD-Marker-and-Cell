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
    std::ofstream fileDragForce;
    std::ofstream fileLiftForce;
    fileDragForce.open("drag.txt");
    fileLiftForce.open("lift.txt");
    if (!fileLiftForce || !fileDragForce)
        std::cout << "file for drag or lift not found";

    makeVTFfiles(file, fileResP, fileResPSI, fileResV);

    clock_t tStart = clock();

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
                flowAroundVPlateBC(V);
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

        
        if( t % 10 == 0)
        {
            calculateAverage(V, U);

            streamFunction(V, U, h);

            writeResults(U, file, fileResP, fileResPSI, fileResV, step);

            step++;
        }

        calculateForce(choice,V,fileDragForce, fileLiftForce);
        
    }

    printf("Time taken: %.2fs\n", (float)(clock() - tStart) / CLOCKS_PER_SEC);
  
    delete(div);

    appendVTFsteps(file, fileResP, fileResPSI, fileResV);

    fileDragForce.close();
    fileLiftForce.close();


}


