//
// Created by senpai on 12/23/20.
//

#include "Raster.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>


Raster::Raster(int width, int height)
{
    this->width = width;
    this->height = height;
    origin_x = width/2;
    origin_y = height/2;

    data = new unsigned char **[width];
    for(int i = 0; i < width; i++)
    {
        data[i] = new unsigned char *[height];
        for(int j = 0; j < height; j++)
            data[i][j] = new unsigned char[3];
    }

    for(int i = 0; i < width; i++)
        for(int j = 0; j < height; j++)
            for(int k = 0; k < 3; k++)
                data[i][j][k] = 0;
}

void Raster::SetPixel(int point_x, int point_y)
{
    int x = origin_x + point_x;
    int y = origin_y + point_y;
    if(x >= width || y >= height)
        return;

    data[x][y][0] = defaultColor.r;
    data[x][y][1] = defaultColor.g;
    data[x][y][2] = defaultColor.b;
}

void Raster::Write()
{
    std::ofstream myFile(fileName);
    myFile << "P6\n" << width << " " << height << " 255\n";
    for(int y = 0; y < height; y++)
        for(int x = 0; x < width; x++)
        {
            myFile << data[x][y][0];
            myFile << data[x][y][1];
            myFile << data[x][y][2];
        }
    myFile.close();
}


void Raster::DrawLine(float start_x,float start_y,float end_x,float end_y)
{
    float x = start_x;
    float y = start_y;
    float dx = std::abs(end_x - start_x);
    float dy = std::abs(end_y - start_y);
    int s1 = (end_x - start_x) < 0 ? -1 :1;
    int s2 = (end_y - start_y) < 0 ? -1 :1;
    bool swap;

    if(dy > dx)
    {
        int aux = dx;
        dx = dy;
        dy = aux;
        swap = true;
    }
    else
        swap = false;

    int error = 2 * dy - dx;
    int a = 2*dy;
    int b = 2*dy - 2*dx;

    for(int i = 1; i < dx; i++)
    {
        if(error < 0)
        {
            if(swap)
                y = y + s2;
            else
                x = x + s1;
            error = error + a;
        }
        else
        {
            y = y + s2;
            x = x + s1;
            error = error + b;
        }
        SetPixel(round(x),round(y));
    }
}

Raster::~Raster()
{
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
            delete [] data[i][j];

        delete[] data[i];
    }
    delete []data;
}
