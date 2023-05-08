#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_New_clicked();

    void on_Open_2_clicked();

    void on_Next_clicked();

    void on_Next2_clicked();

    void on_Drawing_7_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton *button;
};
#endif // MAINWINDOW_H
