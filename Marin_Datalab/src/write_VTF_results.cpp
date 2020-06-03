#include "header.h"

void write_results(Field_Val F, std::ofstream &file, std::ofstream &pFile, std::ofstream &psiFile, std::ofstream &vFile, int step)
{
    file << "\n*RESULTS "<< step*3-2 <<"\n%DIMENSION 1\n%PER_NODE  #1\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            file << F.p[JX(i,j)] << "\n";
        }
    }

    file << "\n*RESULTS "<< step*3-1 <<"\n%DIMENSION 1\n%PER_NODE  #1\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            file << F.psi[JX(i+1,j+1)] << "\n";
        }
    }

    file << "\n*RESULTS "<< step*3 <<"\n%DIMENSION 3\n%PER_NODE #1\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            file << F.u[JX(i,j)] << " " << F.v[JX(i,j)] <<" 0.0\n";
        }
    }

    pFile << "\n%STEP "<< step << "\n" << step*3-2;

    psiFile << "\n%STEP "<< step<<"\n"<< step*3-1;

    vFile << "\n%STEP "<< step<<"\n"<< step*3;
}

void append_VTF_steps(std::ofstream &file, std::ofstream &pFile, std::ofstream &psiFile, std::ofstream &vFile)
{
    //Purpose: Append the step blocks at the end of the VTF file
    pFile.close();
    psiFile.close();
    vFile.close();

    std::ifstream iP("results_pressure.txt");
    std::ifstream iPSI("results_streamfunction.txt");
    std::ifstream iV("results_velocity.txt");

    if (!iP.is_open() || !iPSI.is_open() || !iV.is_open() )
    {
        std::cout << "file not found";
    }
    else
    {
        file << iP.rdbuf();
        file << iPSI.rdbuf();
        file << iV.rdbuf();
    }
    iP.close();
    iPSI.close();
    iV.close();
    file.close();
}
