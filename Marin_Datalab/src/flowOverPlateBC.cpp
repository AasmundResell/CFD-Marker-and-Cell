#include "header.h"

void flowOverPlateBC(Field &V)
{
    for(int j = 0; j <= n+1; j++)
    {

        V.v[IX(0,j)] = 0.0;
        V.u[IX(0,j)] = 1.0; //Uniform flow with speed of 1 m/s

        //Outgoing flow
        V.u[IX(n+1,j)] = V.u[IX(n,j)];
        V.v[IX(n+1,j)] = V.v[IX(n+1,j)];

   //     setting the value zero at plate
        if(j > n*1/3 && j <= n*2/3 )
        {
        V.u[IX(n/3,j)] = 0.0;
        V.v[IX(n/3,j)] = -V.v[IX(n/3+1,j)];
        }

   //     Upper & lower part
        V.u[IX(j,0)] = V.u[IX(j,1)];
        V.v[IX(j,0)] = 0.0;
        V.u[IX(j,n+1)] = V.u[IX(j,n)];
        V.v[IX(j,n)] = 0.0;
    }
}
