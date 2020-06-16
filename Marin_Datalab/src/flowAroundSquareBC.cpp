#include "header.h"

void flowAroundSquareBC(Field &V)
{
    for (int j = 0; j <= n+1; j++)
    {
        //Ingoing flow
        V.v[IX(0,j)] = 0.0;
        V.u[IX(0,j)] = 1.0; 

        //Outgoing flow
        V.u[IX(n+1,j)] = V.u[IX(n,j)];
        V.v[IX(n+1,j)] = -V.v[IX(n,j)];

        if (j >= n/3 && j <= n*2/3) //Set all boundaries for the box to zero
        {
            V.u[IX(n/3,j)] = 0.0;
            V.v[IX(n/3,j)] = -V.v[IX(n/3+1,j)];
            V.u[IX(n*2/3,j)] = 0.0;
            V.v[IX(n*2/3+1,j)] = -V.v[IX(n*2/3,j)];
            V.u[IX(j,n/3)] = -V.u[IX(j,n/3+1)];
            V.v[IX(j,n/3)] = 0.0;
            V.u[IX(j,n*2/3+1)] = -V.u[IX(j,n/3)];
            V.v[IX(j,n*2/3)] = 0.0;
        }

   //     Upper & lower part
        V.u[IX(j,0)] = -V.u[IX(j,1)];
        V.v[IX(j,0)] = 0.0;
        V.u[IX(j,n+1)] = -V.u[IX(j,n)];
        V.v[IX(j,n)] = 0.0;
    }
}
