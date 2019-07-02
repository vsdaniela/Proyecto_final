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
    //save_list_b.load_array(lista);
    imagen a(1,"/home/daniela/Escritorio/pics/des_","Uno");
    imagen b(2,"/home/daniela/Escritorio/pics/des_2","Dos");
    imagen c(3,"/home/daniela/Escritorio/pics/des_3","Tres");
    imagen d(4,"/home/daniela/Escritorio/pics/des_4","Cuatro");
    imagen e(5,"/home/daniela/Escritorio/pics/des_5","Cinco");
    imagen f(6,"/home/daniela/Escritorio/pics/des_6","Seis");
    imagen g(7,"/home/daniela/Escritorio/pics/des_7","Siete");
    imagen h(8,"/home/daniela/Escritorio/pics/des_8","Ocho");
    lista.push_back(a);
    lista.push_back(b);
    lista.push_back(c);
    lista.push_back(d);
    lista.push_back(e);
    lista.push_back(f);
    lista.push_back(g);
    lista.push_back(h);
    save_list_b.save_array(lista);
    it_g= lista.begin();
    p = QPixmap("/home/daniela/Escritorio/fondo");
    ui->label_fondo->setPixmap(p);
    s=(*it_g).path;
    s1 = QString::fromStdString(s);
    p= QPixmap(s1);
    ui->label_pic->setPixmap(p);
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Mostrardatos_clicked()
{
    string s= (*it_g).label;
    string ss= (*it_g).path;
    //int x=(*it_g).id;
    QString s1 = QString::fromStdString(s);
    QString s2 = QString::fromStdString(ss);

    ui->label_text->setText(s1);
}
void MainWindow::on_pic_next_clicked()
{

    if(it_g!=lista.end()){
        ++it_g;
    }
    else {
        it_g=lista.begin();
    }
    s=(*it_g).path;
    s1 = QString::fromStdString(s);
    p= QPixmap(s1);
    ui->label_pic->setPixmap(p);
}
void MainWindow::on_pic_prev_clicked()
{
    if(it_g!=lista.begin()){
        --it_g;
    }
    else{
        it_g=lista.end();

    }
    s=(*it_g).path;
    s1=QString::fromStdString(s);
    p=QPixmap(s1);
    ui->label_pic->setPixmap(s1);
}
void MainWindow::on_add_clicked()
{
    imagen new_i;
    QString txt_label;
    QString txt_path;
    int num_id;
    txt_label=ui->label_->text();
    txt_path=ui->path_->text();
    num_id=ui->id_->text().toInt();
    new_i.label=txt_label.toStdString();
    new_i.path=txt_path.toStdString();
    new_i.id=num_id;
    lista.push_back(new_i);
    save_list_b.save_array(lista);
}
