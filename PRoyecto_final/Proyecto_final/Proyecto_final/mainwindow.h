#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QImage>
#include <iostream>
#include "linked_list.h"
#include "image.h"
#include "binary_file.h"
using namespace  std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    linked_list <image> lista;
    QPixmap p;
    linked_list<image>::iterator it_g;
    QString s1;
    string s;
    binary_file save_list_b;

    ~MainWindow();

private slots:
    void on_Mostrardatos_clicked();
    void on_pic_next_clicked();
    void on_pic_prev_clicked();
    void on_add_clicked();
    void on_delete_2_clicked();
    void on_delete_3_clicked();
    //void on_delete_t_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
