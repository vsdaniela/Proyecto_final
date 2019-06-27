#include "imagen.h"
#include <iostream>
#include <QPixmap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
imagen::imagen(int i, string p, string n): id(i), path(p), name(n)
{
}
imagen::~imagen()
{
}
