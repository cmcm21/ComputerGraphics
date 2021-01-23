//
// Created by senpai on 12/23/20.
//

#ifndef PROJECT_VECTOR3D_H
#define PROJECT_VECTOR3D_H

struct Vector3D
{
    float x;
    float y;
    float z;
    Vector3D(float x, float y,float z):x(x),y(y),z(z) {}
    Vector3D():x(0),y(0),z(0){}
};


Vector3D &MatrixMultiplication(float matrix[3][3],Vector3D &vector);
Vector3D &MatrixMultiplicacion(float matrix[4][4],Vector3D &vector);
Vector3D &Translate(Vector3D &vector,float x,float y, float z);
Vector3D &Translate(Vector3D &vectorOrigin,Vector3D translationVector);
Vector3D Rotate(Vector3D &vector,float rotation,char axis);
Vector3D &Scale(Vector3D &vector,float scale_x,float scale_y,float scale_z);
Vector3D &Scale(Vector3D &vector,Vector3D scaleVector);
Vector3D &Project(Vector3D &vector, float focalLen);


#endif //PROJECT_VECTOR3D_H
