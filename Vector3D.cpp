//
// Created by senpai on 12/23/20.
//
#include "Vector3D.h"
#include <cmath>

Vector3D Rotate(Vector3D &vector,float angle, char axis)
{
    float s = std::sin(angle);
    float c = std::cos(angle);
    Vector3D resultVector;

    if(axis == 'x')
    {
        float matrix[3][3] = {
                1.0f, 0.0f, 0.0f,
                0.0f,  c,   -s,
                0.0f,  s,    c
        };
        resultVector = MatrixMultiplication(matrix,vector);
    }
    else if(axis == 'y')
    {
        float matrix[3][3] = {
                c,    0.0f, s,
                0.0f, 1.0f, 0.0f,
                -s,    0.0f, c
        };
        resultVector = MatrixMultiplication(matrix,vector);
    }
    else if(axis == 'z')
    {
        float matrix[3][3] = {
                c,   -s,    0.0f,
                s,    c,    0.0f,
                0.0f, 0.0f, 1.0f
        };
        resultVector = MatrixMultiplication(matrix,vector);
    }
    return resultVector;
}

Vector3D &Scale(Vector3D &vector,float scale_x,float scale_y,float scale_z)
{
    float matrix[3][3] = {
            scale_x,  0.0f,    0.0f,
            0.0f,     scale_y, 0.0f,
            0.0f,     0.0f,    scale_z
    };
    return MatrixMultiplication(matrix,vector);
}

Vector3D &Scale(Vector3D &vector,Vector3D scale)
{
    float matrix[3][3] = {
            scale.x,  0.0f,    0.0f,
            0.0f,     scale.y, 0.0f,
            0.0f,     0.0f,    scale.z
    };
    return MatrixMultiplication(matrix,vector);
}

Vector3D &Translate(Vector3D &vector, float x, float y, float z)
{
    vector.x += x;
    vector.y += y;
    vector.z += z;
    return vector;
}

Vector3D &Translate(Vector3D &vector,Vector3D translation)
{
    vector.x += translation.x;
    vector.y += translation.y;
    vector.z += translation.z;
    return vector;
}

Vector3D &MatrixMultiplication(float matrix[3][3],Vector3D &vector)
{
    float v[3] = {vector.x,vector.y,vector.z};
    float result[3] = {0,0,0};


    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            result[i] += matrix[i][j] * v[j];

    vector.x = result[0];
    vector.y = result[1];
    vector.z = result[2];

    return vector;
}

Vector3D& Project(Vector3D &vector, float f)
{
    float matrix[4][4] = {
            1,0,0,0,
            0,f,0,0,
            0,0,f,0,
            1,0,0,0
    };

    return MatrixMultiplicacion(matrix,vector);
}

Vector3D &MatrixMultiplicacion(float matrix[4][4],Vector3D &vector)
{
   float v[4] = {vector.x, vector.y, vector.z, 1};
   float result[4] = {0,0,0,0};

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            result[i] += matrix[i][j] * v[j];

    vector.x = result[0] / result[3];
    vector.y = result[1] / result[3];
    vector.y = result[2] / result[3];

   return vector;
}
