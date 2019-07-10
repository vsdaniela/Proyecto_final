#include "image.h"
#include <iostream>
#include <QPixmap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
image::image(string n, string p, string l): name(n), path(p), label(l)
{
}
image::~image()
{
}
