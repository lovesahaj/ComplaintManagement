#ifndef ADMINLOGINWINDOW_H
#define ADMINLOGINWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include "admindialog.h"
#include "adminregisterdialog.h"

namespace Ui {
class adminLoginWindow;
}

class adminLoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminLoginWindow(QWidget *parent = nullptr);
    ~adminLoginWindow();

private slots:
    void on_cancelButton_clicked();

    void on_pushButton_clicked();

    void on_loginButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::adminLoginWindow *ui;
    bool isAdmin(QString, QString);
};

#endif // ADMINLOGINWINDOW_H
