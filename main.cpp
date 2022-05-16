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

#include "src/raytracer.h"

int main()
{
    const char * const inputFile[5] =
    {
        "src/scene1.txt",
        "src/scene2.txt",
        "src/scene3.txt",
        "src/scene4.txt",
        "src/scene5.txt",
    };
    const char * const outputFile[5] =
    {
        "Raytracer_output1.bmp",
        "Raytracer_output2.bmp",
        "Raytracer_output3.bmp",
        "Raytracer_output4.bmp",
        "Raytracer_output5.bmp",
    };

    for (int i = 0; i < 5; ++i)
    {
        Raytracer raytracer;
        raytracer.SetInput(inputFile[i]);
        raytracer.SetOutput(outputFile[i]);

        raytracer.Run();

        std::cout << "Output file saved at '" << std::filesystem::absolute(outputFile[i]) << "'." << std::endl;
    }
    return 0;
}