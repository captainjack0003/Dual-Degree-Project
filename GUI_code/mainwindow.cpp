#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmcreator.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_New_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Open_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}




void MainWindow::on_Next_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}


void MainWindow::on_Next2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}


void MainWindow::on_Drawing_7_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}

