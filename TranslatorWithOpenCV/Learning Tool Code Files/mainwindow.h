#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "translate_search.h"


//#include "ProcessImage.hpp"
#include <iostream>
#include <string>
//#include "StringCorrection.hpp"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_imgC_clicked();



    std::string* on_pushButton_clicked();

    void on_searchB_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
