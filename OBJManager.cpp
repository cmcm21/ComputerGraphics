//
// Created by senpai on 12/23/20.
//

#include "OBJManager.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>

OBJManager::OBJManager(){}

void OBJManager::LoadObjFile(std::string filename)
{
    FILE *file = fopen(filename.c_str(),"r");
    if(file == nullptr)
    {
        printf("impossible to read file");
        return;
    }
    while (1)
    {
        char lineHeader[128];
        int res = fscanf(file,"%s",lineHeader);
        if(res == EOF)
            break;
        else if(strcmp(lineHeader,"v") == 0)
        {
            float x, y,z;
            fscanf(file, "%f %f %f\n", &x, &y, &z);
            vertices.push_back(Vector3D(x,y,z));
        }
    }
}

void OBJManager::PrintVertices()
{
    for(Vector3D vertex :vertices)
        std::cout << "<" << vertex.x << ", " << vertex.y << ", " << vertex.z
                  << ">" << std::endl;
    std::cout << "List of vertices size: "<< vertices.size() << std::endl;
}

void OBJManager::DrawObjModel(Raster &raster)
{
    auto it = vertices.begin();
    while(it != vertices.end())
    {
        Vector3D start = *it;
        it++;
        if(it == vertices.end())
            raster.DrawLine(start.x,start.y,vertices[0].x,vertices[0].y);
        else
            raster.DrawLine(start.x,start.y,it->x,it->y);
    }
    raster.Write();
}

void OBJManager::ScaleObjModel(Vector3D vector)
{
    for(int i = 0; i < vertices.size(); i++)
        vertices[i] = Scale(vertices[i],vector);
}

void OBJManager::ScaleObjModel(float x, float y, float z)
{
    for(auto & vertice : vertices)
        vertice = Scale(vertice,x,y,z);
}

void OBJManager::RotateObjModel(float angle,char axis)
{
    for(auto & vertice : vertices)
        vertice = Rotate(vertice,angle,axis);
}

void OBJManager::TranslateObjModel(Vector3D vector)
{
    for(auto & vertice : vertices)
        vertice = Translate(vertice,vector);
}

void OBJManager::TranslateObjModel(float x, float y, float z)
{
    for(auto & vertice : vertices)
        vertice = Translate(vertice,x,y,z);
}

void OBJManager::ProjectObjModel(float focalLen)
{
    for(auto & vertice : vertices)
        vertice = Project(vertice,focalLen);
}

void OBJManager::DrawParallelLine(Vector3D start, Vector3D end, Raster &raster)
{
    raster.DrawLine(start.x,start.y,end.x,end.y);
}