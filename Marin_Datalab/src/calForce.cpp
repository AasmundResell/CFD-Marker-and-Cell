#include "header.h"

void calculateForce(int choice,const Field& V, std::ofstream &dFile, std::ofstream& lFile)
{
    double forceX = 0;
    double forceY = 0;
    if (choice == 2)
    {
        //box
        for(int i = n/3; i <= 2*n/3; i++)
        {
            forceX = forceX + V.p[IX(n/3-1,i)] - V.p[IX(n*2/3+1,i)];
            forceY = forceY + V.p[IX(i, 2 * n / 3 + 1)] - V.p[IX(i, n / 3 - 1)];
        }
    }

    if (choice == 3)
    {
       //plate
       for (int i = n/4; i <= n*3/4; i++)
       {
           forceX = forceX + V.p[IX(n/3, i)] - V.p[IX(n/3+1, i)];
       }
    }
    

    dFile << forceX << "\n";
    lFile << forceY << "\n";

}
