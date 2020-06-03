#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip> 

#define n 30

#define IX(x, y) ((x) + (y)*(n+2))
#define JX(x, y) ((x) + (y)*(n))

struct Field
{
    double u[(n+2)*(n+2)] = {0};
    double v[(n+2)*(n+2)] = {0};
    double p[(n+2)*(n+2)] = {0};

};

struct Field_Val
{
//#define IX(x, y) ((x) + (y)*(n))
    double u[n*n] = {0};
    double v[n*n] = {0};
    double p[n*n] = {0};
    double psi[(n+1)*(n+1)] = {0}; // stream function values
};

double interpolate();

bool stability(double h, double Re,double dt);

void calculateFlowField(double Re,double h, int tmax, double dt, Field& V,Field_Val&  U, int itmax, double beta, double epsilon, int choice);

void calVel(double h, double Re, double dt, Field &V);

void cavityBoxBC(Field &V);

void flowAroundSquareBC(Field &V);

void flowOverPlateBC(Field &V);

void piter(double h, double dt, double beta, double epsi, Field &V,int &iflag, double* div);

void calculate_average(const Field& V, Field_Val& U);

void streamfunction(const Field& V, Field_Val& U, double h);

int choice();

void make_VTF_files(std::ofstream &file, std::ofstream &pFile, std::ofstream &psiFile, std::ofstream &vFile);

void write_results(Field_Val F, std::ofstream &file, std::ofstream &pFile, std::ofstream &psiFile, std::ofstream &vFile, int step);

void append_VTF_steps(std::ofstream &file,  std::ofstream &pFile, std::ofstream &psiFile, std::ofstream &vFile);

void calculateForce(int situation, const Field& V, std::ofstream &fFile);

