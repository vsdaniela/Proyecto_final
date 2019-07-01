#include "imagen.h"
#include <iostream>
#include <QPixmap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
imagen::imagen(int i, string p, string l): id(i), path(p), label(l)
{
}
imagen::~imagen()
{
}
