#include "header.h"

void piter(double h, double dt,
 double beta, double epsi, Field &V, int &iflag, double* div)
{
    double delp;
    iflag = 0;

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            *div = (V.u[IX(i,j)]-V.u[IX(i-1,j)])/h + (V.v[IX(i,j)]-V.v[IX(i,j-1)])/h;

            if (std::fabs(*div) >= epsi)
            {
                iflag = 1;
            }
            delp = -beta*(*div);
            V.p[IX(i,j)] = V.p[IX(i,j)] + delp;
            V.u[IX(i,j)] = V.u[IX(i,j)] + delp*dt/h;
            V.u[IX(i-1,j)] = V.u[IX(i-1,j)] - delp*dt/h;
            V.v[IX(i,j)] = V.v[IX(i,j)] + delp*dt/h;
            V.v[IX(i,j-1)] = V.v[IX(i,j-1)] - delp*dt/h;

        }
    }
}
