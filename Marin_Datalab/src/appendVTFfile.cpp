#include "header.h"

void appendVTFsteps(std::ofstream& file, std::ofstream& pFile, std::ofstream& psiFile, std::ofstream& vFile)
{
    //Purpose: Append the step blocks at the end of the VTF file
    pFile.close();
    psiFile.close();
    vFile.close();

    std::ifstream iP("results_pressure.txt");
    std::ifstream iPSI("results_streamfunction.txt");
    std::ifstream iV("results_velocity.txt");

    if (!iP.is_open() || !iPSI.is_open() || !iV.is_open())
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

