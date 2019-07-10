#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <QImage>
using namespace  std;

class image
{
    public:
        string name;
        string path;
        string label;
    public:
        image(string n="none", string p="none",string l="none");
        ~image();
};

#endif // IMAGE_H
