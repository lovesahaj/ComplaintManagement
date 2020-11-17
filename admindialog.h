#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>
#include <QSql>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "complaint.h"
#include <QSqlQueryModel>
#include "adminallcomplaints.h"
#include "adminacceptedcomplaints.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QDateTime>

namespace Ui {
class adminDialog;
}

class adminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit adminDialog(QWidget *parent = nullptr);
    ~adminDialog();

private slots:
    void on_selectID_currentIndexChanged(int index);

    void on_findID_clicked();

    void on_doneButton_clicked();

    void on_cancelButton_clicked();

    void on_allComplaintsButton_clicked();

    void on_acceptedComplaitsButton_clicked();

    void on_printButton_clicked();

private:
    Ui::adminDialog *ui;
    QSqlDatabase *mydb;
};

#endif // ADMINDIALOG_H
