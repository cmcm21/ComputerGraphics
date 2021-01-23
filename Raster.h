//
// Created by senpai on 12/23/20.
//

#ifndef PROJECT_RASTER_H
#define PROJECT_RASTER_H

#include <string>

struct ColorRGB
{
    unsigned char r;
    unsigned char b;
    unsigned char g;

    ColorRGB(unsigned char red,unsigned char blue, unsigned char green)
    {
        r = red;
        b = blue;
        g = green;
    }
};

class Raster
{
private:
    unsigned char ***data;
    int origin_x;
    int origin_y;
    int width;
    int height;
    const ColorRGB defaultColor = ColorRGB(255,255,255);
    const std::string fileName = "image.ppm";
    void SetPixel(int x,int y);
public:
    Raster(int width, int height);
    void Write();
    void DrawLine(float start_x,float start_y,float end_x,float end_y);
    ~Raster();

};


#endif //PROJECT_RASTER_H
