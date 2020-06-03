#include "header.h"

void streamfunction(const Field& V, Field_Val &U, double h)
{
    double psi [(n+1)*(n+1)] = {0};

    for(int i = 1;i < n+1; i++)
    {
        psi[JX(i,0)] = psi[JX(i-1,0)] - V.v[IX(i,0)]*h;
    }

    for(int i = 0; i < n+1; i++)
    {
        for(int j= 1; j < n+1; j++)
        {
            psi[JX(i,j)] = psi[JX(i,j-1)]+V.u[IX(i,j)]*h;
        }
    }

    for (int i = 0; i <= n ; i++)
    {
        for (int j = 0 ; j <= n; j++ )
        {
            U.psi [JX(i,j)] = -psi[JX(j,i)] ;
        }
    }
}
