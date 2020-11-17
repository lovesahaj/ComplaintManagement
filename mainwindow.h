#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adminloginwindow.h"
#include "filecomp.h"


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
    void on_quitButton_pressed();

    void on_loginAdmin_clicked();

    void on_fileComplaint_clicked();

private:
    Ui::MainWindow *ui;
    adminLoginWindow *adminLogin;
    fileComp *fileDialog;
};
#endif // MAINWINDOW_H
