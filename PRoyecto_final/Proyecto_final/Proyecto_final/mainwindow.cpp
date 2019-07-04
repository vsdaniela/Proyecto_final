#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPixmap>
#include <iostream>
#include "image.h"
#include "linked_list.h"
#include "binary_file.h"
#include <QFileDialog>
using namespace  std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //save_list_b.load_array(lista);
    image a(1,"/home/daniela/Escritorio/pics/des_","Patricio");
    image b(2,"/home/daniela/Escritorio/pics/des_2","f");
    image c(3,"/home/daniela/Escritorio/pics/des_3","galaxia");
    image d(4,"/home/daniela/Escritorio/pics/des_4","eclipse");
    image e(5,"/home/daniela/Escritorio/pics/des_5","árbol");
    image f(6,"/home/daniela/Escritorio/pics/des_6","casa");
    image g(7,"/home/daniela/Escritorio/pics/des_7","paisaje");
    image h(8,"/home/daniela/Escritorio/pics/des_8","jx");
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
    string s_p= (*it_g).path;
    int x=(*it_g).id;
    QString s1 = QString::fromStdString(s);
    QString s2 = QString::fromStdString(s_p);
    s1=s1+"<p>"+s2;

    ui->label_text->setText(s1);
    //ui->label_text->setText(s2);
    //ui->label_text->setNum(x);
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
    image new_i;
    QString txt_label;
    QString txt_path;
    int num_id;
    txt_label=ui->label_->text();
    //txt_path=ui->path_->text();
    num_id=ui->id_->text().toInt();
    new_i.label=txt_label.toStdString();
    //new_i.path=txt_path.toStdString();
    new_i.id=num_id;
    txt_path = QFileDialog::getOpenFileName(this, "Open image","/home/daniela/Escritorio/pics");
    new_i.path=txt_path.toStdString();
    lista.push_back(new_i);
    save_list_b.save_array(lista);
}

void MainWindow::on_delete_2_clicked()
{
    lista.remove_front();
    save_list_b.save_array(lista);
}

void MainWindow::on_delete_3_clicked()
{
    lista.remove_back();
    save_list_b.save_array(lista);
}
//delete this

/*void MainWindow::on_delete_t_clicked()
{
    lista.remove_this(*it_g);
}
*/
