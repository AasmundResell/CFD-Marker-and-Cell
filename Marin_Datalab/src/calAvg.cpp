#include "header.h"

void calculateAverage(const Field& V, Field_Val &U)
{
for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
        U.u[JX(j,i)] = (V.u[IX(i,j+1)]+V.u[IX(i+1,j+1)])/2;
        U.v[JX(j,i)] = (V.v[IX(i+1,j)]+V.v[IX(i+1,j+1)])/2;
        U.p[JX(j,i)] = V.p[IX(i+1,j+1)];
        }
    }
}
