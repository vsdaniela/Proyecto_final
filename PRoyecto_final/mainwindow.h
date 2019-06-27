#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QImage>
#include <iostream>
#include "linked_list.h"
#include "imagen.h"
using namespace  std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    linked_list <imagen> lista;
    QPixmap p;
    linked_list<imagen>::iterator it_g;
    QString s1;
    string s;
    ~MainWindow();

private slots:
    void on_Mostrardatos_clicked();
    void on_pic_next_clicked();
    void on_pic_prev_clicked();

    void on_add_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
