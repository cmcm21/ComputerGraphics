#include <iostream>
#include "OBJManager.h"
#include "Raster.h"

int main()
{
    OBJManager *obj = new OBJManager();
    Raster raster = Raster(1920,1080);
    obj->LoadObjFile("pistola.obj");
    //obj->ScaleObjModel(500,500,0);
    obj->ProjectObjModel(10);
    obj->DrawObjModel(raster);
    return 0;
}
