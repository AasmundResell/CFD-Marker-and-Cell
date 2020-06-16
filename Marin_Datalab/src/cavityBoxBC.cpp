#include "header.h"

void cavityBoxBC(Field &V)
{
    for (int j = 0;j <= n+1;j++) //Reduced to one loop to reduce computational time
    {
        //Applying boundaries    to the vertical walls
        V.u[IX(0,j)] = 0.0;
        V.v[IX(0,j)] = -V.v[IX(1,j)];
        V.u[IX(n,j)] = 0.0;
        V.v[IX(n+1,j)] = -V.v[IX(n,j)];
    }
    for (int i = 0; i <= n+1; i++)
    {
        //Applying boundaries to the horizontal walls
        V.v[IX(i,n)] = 0.0;
        V.v[IX(i,0)] = 0.0;
        V.u[IX(i,n+1)] = -V.u[IX(i,n)]+2.0;
        V.u[IX(i,0)] = -V.u[IX(i,1)];
    }
}
