#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPixmap>
#include <iostream>
#include "image.h"
#include "linked_list.h"
#include "binary_file.h"
#include <QFileDialog>
#include "bst.h"
using namespace  std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //save_list_b.load_array(lista);
    image a("Auroras","/home/daniela/Escritorio/pics/des_13","auroras_boreales");
    lista.push_back(a);
    image_tree.insert(a.name,a);
    save_list_b.save_array(lista);
    it_g= lista.begin();
    p = QPixmap("/home/daniela/Escritorio/fondo");
    ui->label_fondo->setPixmap(p);
    s_=(*it_g).path;
    s1 = QString::fromStdString(s_);
    p= QPixmap(s1);
    ui->label_pic->setPixmap(p);
    labels_total.push_back((*it_g).label);
    string q_tmp= (*it_g).label;
    QString s=QString::fromStdString(q_tmp);
    ui->comboBox->addItem(s);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Mostrardatos_clicked()
{
    string s= (*it_g).label;
    string s_p= (*it_g).path;
    string s_n= (*it_g).name;
    QString s1 = QString::fromStdString(s);
    QString s2 = QString::fromStdString(s_p);
    QString s3 = QString::fromStdString(s_n);
    QString st=s1+"<p>"+s2+"<p>"+s3;

    ui->label_text->setText(st);
}
void MainWindow::on_pic_next_clicked()
{

    if(it_g!=lista.end()){
        ++it_g;
    }
    else {
        it_g=lista.begin();
    }
    s_=(*it_g).path;
    s1=QString::fromStdString(s_);
    p=QPixmap(s1);
    ui->label_pic->setPixmap(s1);
}
void MainWindow::on_pic_prev_clicked()
{
    if(it_g!=lista.begin()){
        --it_g;
    }
    else{
        it_g=lista.end();
    }
    s_=(*it_g).path;
    s1=QString::fromStdString(s_);
    p=QPixmap(s1);
    ui->label_pic->setPixmap(s1);

}

void MainWindow::on_pushButton_clicked()
{
    QString atmp= ui->label_->text();
    new_i.label=atmp.toStdString();
    //labels_total.push_back(atmp);
}
void MainWindow::on_add_clicked()
{

    QString txt_label;
    QString txt_path;
    QString txt_name;
    txt_label=ui->label_->text();
    txt_name=ui->name_->text();
    if((new_i.label) != (txt_label.toStdString())){
        new_i.label=txt_label.toStdString();
    }
    new_i.name=txt_name.toStdString();
    txt_path = QFileDialog::getOpenFileName(this, "Open image","/home/daniela/Escritorio/pics");
    new_i.path=txt_path.toStdString();
    lista.push_back(new_i);
    image_tree.insert(new_i.name,new_i);
    labels_total.push_back(new_i.label);
    string a=labels_total[labels_total.size()-1];
    QString a_tmp=QString::fromStdString(a);
    ui->comboBox->addItem(a_tmp);
    save_list_b.save_array(lista);
}

void MainWindow::on_delete_t_clicked()
{
    lista.remove_this(it_g);
    save_list_b.save_array(lista);
}


void MainWindow::on_find_clicked()
{
    QString t=ui->line_edit->text();
    string f=t.toStdString();
    image image_tmp = image_tree.find(f);
    QString s_image= QString::fromStdString(image_tmp.path);
    p=QPixmap(s_image);
    ui->label_pic->setPixmap(p);
}

void MainWindow::on_edit_i_clicked()
{
    QString ed_l = ui->label_->text();
    QString ed_n = ui->name_->text();
    (*it_g).label=ed_l.toStdString();
    (*it_g).label=ed_l.toStdString();
    QString ed_p=QFileDialog::getOpenFileName(this, "Select image","/home/daniela/Escritorio/pics");
    (*it_g).path=ed_p.toStdString();
    save_list_b.save_array(lista);
}
