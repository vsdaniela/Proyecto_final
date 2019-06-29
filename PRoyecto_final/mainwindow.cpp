#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPixmap>
#include <QMessageBox>
#include <iostream>
#include <QBitmap>
#include "imagen.h"
#include "linked_list.h"
#include "binary_file.h"
using namespace  std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imagen a(1,"/home/daniela/Escritorio/pics/des_","Uno");
    imagen b(2,"/home/daniela/Escritorio/pics/des_2","Dos");
    imagen c(3,"/home/daniela/Escritorio/pics/des_3","Tres");
    imagen d(4,"/home/daniela/Escritorio/pics/des_4","Cuatro");
    imagen e(5,"/home/daniela/Escritorio/pics/des_5","Cinco");
    lista.push_back(a);
    lista.push_back(b);
    lista.push_back(c);
    lista.push_back(d);
    lista.push_back(e);
    save_list_b.save_array(lista);
    it_g= lista.begin();
    p = QPixmap("/home/daniela/Escritorio/fondo");
    ui->label_fondo->setPixmap(p);
    string s;
    QString s1;
    if(it_g!=lista.end()){
       s=(*it_g).path;
       s1 = QString::fromStdString(s);
       p= QPixmap(s1);
       ui->label_pic->setPixmap(p);
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Mostrardatos_clicked()
{
    string s= (*it_g).name;
    string ss= (*it_g).path;
    //int x=(*it_g).id;
    QString s1 = QString::fromStdString(s);
    QString s2 = QString::fromStdString(ss);

    ui->label_text->setText(s1);
}
void MainWindow::on_pic_next_clicked()
{
    ++it_g;
    if(it_g!=lista.end()){
       s=(*it_g).path;
       s1 = QString::fromStdString(s);
       p= QPixmap(s1);
       ui->label_pic->setPixmap(p);
    }
    else {
        it_g=lista.begin();
    }
}
void MainWindow::on_pic_prev_clicked()
{

    if(it_g!=lista.begin()){
        --it_g;
        s=(*it_g).path;
        s1=QString::fromStdString(s);
        p=QPixmap(s1);
        ui->label_pic->setPixmap(s1);
    }
    else{
        it_g=lista.end();
    }
}


void MainWindow::on_add_clicked()
{

}
