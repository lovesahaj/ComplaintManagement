#ifndef ADMINALLCOMPLAINTS_H
#define ADMINALLCOMPLAINTS_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QSql>
#include <QSqlDatabase>

namespace Ui {
class adminAllComplaints;
}

class adminAllComplaints : public QDialog
{
    Q_OBJECT

public:
    explicit adminAllComplaints(QWidget *parent = nullptr);
    ~adminAllComplaints();

private:
    Ui::adminAllComplaints *ui;
    QSqlDatabase *mydb;
    QSqlQueryModel *qModel;
};

#endif // ADMINALLCOMPLAINTS_H
