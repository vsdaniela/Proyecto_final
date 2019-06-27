#ifndef IMAGEN_H
#define IMAGEN_H
#include <iostream>
#include <QImage>
using namespace  std;

class imagen
{
    public:
        int id;
        string path;
        string name;
    public:
        imagen(int i=0, string p="none",string n="none");
        void Show(imagen & x);
        ~imagen();
};

#endif // IMAGEN_H
