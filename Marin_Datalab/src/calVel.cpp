#include "header.h"

void calVel( double h, double Re, double dt, Field& V)
{
	double fux, fuy, fvx, fvy, visu, visv;
    //Calculation of tentative velocities for the known pressure
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
			fux = 1 / h * 0.25 * ((V.u[IX(i + 1,j)] + V.u[IX(i,j)]) * (V.u[IX(i + 1,j)] + V.u[IX(i,j)]) - (V.u[IX(i,j)] + V.u[IX(i - 1,j)]) * (V.u[IX(i,j)] + V.u[IX(i - 1,j)]));
			fuy = 1 / h * 0.25 * ((V.v[IX(i + 1,j)] + V.v[IX(i,j)]) * (V.u[IX(i,j + 1)] + V.u[IX(i,j)]) - (V.v[IX(i,j - 1)] + V.v[IX(i + 1,j - 1)]) * (V.u[IX(i,j - 1)] + V.u[IX(i,j)]));
			fvx = 1 / h * 0.25 * ((V.u[IX(i,j + 1)] + V.u[IX(i,j)]) * (V.v[IX(i + 1,j)] + V.v[IX(i,j)]) - (V.u[IX(i - 1,j)] + V.u[IX(i - 1,j + 1)]) * (V.v[IX(i,j)] + V.v[IX(i - 1,j)]));
			fvy = 1 / h * 0.25 * ((V.v[IX(i,j + 1)] + V.v[IX(i,j)]) * (V.v[IX(i,j + 1)] + V.v[IX(i,j)]) - (V.v[IX(i,j)] + V.v[IX(i,j - 1)]) * (V.v[IX(i,j)] + V.v[IX(i,j - 1)]));

			visu = (V.u[IX(i + 1,j)] + V.u[IX(i - 1,j)] + V.u[IX(i,j + 1)] + V.u[IX(i,j - 1)] - 4.0 * V.u[IX(i,j)]) / (Re * h * h);
			visv = (V.v[IX(i + 1,j)] + V.v[IX(i - 1,j)] + V.v[IX(i,j + 1)] + V.v[IX(i,j - 1)] - 4.0 * V.v[IX(i,j)]) / (Re * h * h);

			V.u[IX(i,j)] = V.u[IX(i,j)] + dt * ((V.p[IX(i,j)] - V.p[IX(i + 1,j)]) / h - fux - fuy + visu);
			V.v[IX(i,j)] = V.v[IX(i,j)] + dt * ((V.p[IX(i,j)] - V.p[IX(i,j + 1)]) / h - fvx - fvy + visv);

		}
    }
}




