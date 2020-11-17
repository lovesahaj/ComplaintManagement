#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filecomp.h"
#include "adminloginwindow.h"

#include <QtWidgets>
#include <QApplication>

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

void MainWindow::on_quitButton_pressed()
{
    QApplication::quit();
}

void MainWindow::on_loginAdmin_clicked()
{
    adminLogin = new adminLoginWindow(this);
    adminLogin->setModal(true);
    hide();
    adminLogin->exec();
}

void MainWindow::on_fileComplaint_clicked()
{
    fileDialog = new fileComp(this);
    fileDialog->setModal(true);
    hide();
    fileDialog->exec();
}
