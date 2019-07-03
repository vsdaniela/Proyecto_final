#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <QImage>
using namespace  std;

class image
{
    public:
        int id;
        string path;
        string label;
    public:
        image(int i=0, string p="none",string l="none");
        ~image();
};

#endif // IMAGE_H
