/*****************************************************************//**
 * \file   main_raytracer.cpp
 * \brief  Raytracing main
 * 
 * \author Kevin Pruvost (pruvostkevin0@gmail.com)
 * \date   May, 14 2022
 *********************************************************************/

#include <iostream>
#include <filesystem>

#include <omp.h>

#include "Raytracing_Implementation/raytracer.h"

int main()
{
    const char * const inputFile = "Raytracing_Implementation/scene3.txt";
    const char * const outputFile = "Raytracer_output3.bmp";

    Raytracer raytracer;
    raytracer.SetInput(inputFile);
    raytracer.SetOutput(outputFile);

    raytracer.Run();

    std::cout << "Output file saved at '" << std::filesystem::absolute(outputFile) << "'." << std::endl;
    return 0;
}