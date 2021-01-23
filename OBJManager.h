//
// Created by senpai on 12/23/20.
//

#ifndef PROJECT_OBJMANAGER_H
#define PROJECT_OBJMANAGER_H

#include <vector>
#include <string>
#include "Vector3D.h"
#include "Raster.h"

class OBJManager
{
private:
    void static DrawParallelLine(Vector3D start, Vector3D end,Raster &raster);
public:
    OBJManager();
    std::vector<Vector3D> vertices;
    void LoadObjFile(std::string filename);
    void DrawObjModel(Raster &raster);
    void PrintVertices();
    void ScaleObjModel(Vector3D vector);
    void ScaleObjModel(float x, float y, float z);
    void RotateObjModel(float angle, char axis);
    void TranslateObjModel(Vector3D vector);
    void TranslateObjModel(float x, float y, float z);
    void ProjectObjModel(float focalLen);
};

#endif //PROJECT_OBJMANAGER_H
