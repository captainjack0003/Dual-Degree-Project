#ifndef DBMCREATOR_H
#define DBMCREATOR_H

#include <QWidget>

namespace Ui {
class dBMCreator;
}

class dBMCreator : public QWidget
{
    Q_OBJECT

public:
    explicit dBMCreator(QWidget *parent = nullptr);
    ~dBMCreator();

private slots:

    void on_Drawing_clicked();

private:
    Ui::dBMCreator *ui;
};

#endif // DBMCREATOR_H
