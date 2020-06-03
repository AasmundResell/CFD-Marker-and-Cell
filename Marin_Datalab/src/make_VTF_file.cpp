#include "header.h"

void make_VTF_files(std::ofstream &file, std::ofstream &pFile, std::ofstream &psiFile, std::ofstream &vFile)
{

    file.open("glview.vtf");
    pFile.open("results_pressure.txt");
    psiFile.open("results_streamfunction.txt");
    vFile.open("results_velocity.txt");

      if (!file.is_open() ||!pFile.is_open() ||!psiFile.is_open() ||!vFile.is_open())
    {
        std::cout << "file not found";
    }


    //adding the acii header
      file << "*VTF-1.00\n\n!Setup of nodes \n*NODES 1\n%NO_ID\n";

    //setting up all the nodes, without specifying the nodes ID becomes sequentially numbered
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
        file  << j<< ". "<< i << ". " << 0.0 << ".\n";
        }
    }

   file << "\n*ELEMENTS 1\n%NODES #1\n%QUADS\n";
   for (int i = 0; i < n-1; i++)
   {
        for(int j = 1; j < n; j++)
        file << i*n + j << " "<< i*n + (j+1) << " " << (i+1)*(n) + (j+1) << " " << (i+1)*n + j << "\n";
   }

    //assemble the geometry<< " " << i*(n+1)+j
    file << "\n\n*GLVIEWGEOMETRY 1\n%ELEMENTS\n1\n";

    pFile << "\n*GLVIEWSCALAR 1\n%NAME \"Pressure\"";

    psiFile << "\n*GLVIEWSCALAR 2\n%NAME \"Streamfunction\"";

    vFile << "\n*GLVIEWVECTOR 1\n%NAME \"Velocity\"";

}



