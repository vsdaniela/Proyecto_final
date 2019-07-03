#include "image.h"
#include <iostream>
#include <QPixmap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
image::image(int i, string p, string l): id(i), path(p), label(l)
{
}
image::~image()
{
}
