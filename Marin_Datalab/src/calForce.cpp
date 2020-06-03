#include "header.h"

void calculateForce(int choice,const Field& V, std::ofstream &fFile)
{
    double forceX = 0;
    double forceY = 0;

    if (choice == 2)
    {
       //plate

    }
    if (choice == 3)
    {
        //box
        for(int i = n/3; i <= 2*n/3; i++)
        {
        forceX = forceX + V.p[IX(n/3,i)]+V.p[IX(2*n/3,i)];
        forceY = forceY + V.p[IX(i,n/3)]+V.p[IX(i,2*n/3)];

        }
    }

    fFile << "FX = " << forceX << "\n" << "FY = " << forceY << "\n";

}
