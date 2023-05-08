#include "dbmcreator.h"
#include "ui_dbmcreator.h"

dBMCreator::dBMCreator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dBMCreator)
{
    ui->setupUi(this);
}

dBMCreator::~dBMCreator()
{
    delete ui;
}


void dBMCreator::on_Drawing_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

