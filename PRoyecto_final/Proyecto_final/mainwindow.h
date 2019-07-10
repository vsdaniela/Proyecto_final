#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QImage>
#include <iostream>
#include "linked_list.h"
#include "image.h"
#include "binary_file.h"
#include <vector>
#include "bst.h"
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
    bst <string,image> image_tree;
    QString s1;
    string s_;
    binary_file save_list_b;
    vector <string> labels_total;
    QString t_label;
    image new_i;

    ~MainWindow();

private slots:
    void on_Mostrardatos_clicked();
    void on_pic_next_clicked();
    void on_pic_prev_clicked();
    void on_add_clicked();
    void on_delete_t_clicked();

    void on_pushButton_clicked();

    void on_find_clicked();

    void on_edit_i_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
