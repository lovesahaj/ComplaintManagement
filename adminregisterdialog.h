#ifndef ADMINREGISTERDIALOG_H
#define ADMINREGISTERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>

const QString SECURITY_CODE = "123456";

namespace Ui {
class adminRegisterDialog;
}

class adminRegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit adminRegisterDialog(QWidget *parent = nullptr);
    ~adminRegisterDialog();

private slots:
    void on_cancelButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::adminRegisterDialog *ui;
};

#endif // ADMINREGISTERDIALOG_H
