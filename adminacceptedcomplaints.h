#ifndef ADMINACCEPTEDCOMPLAINTS_H
#define ADMINACCEPTEDCOMPLAINTS_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QSql>
#include <QSqlDatabase>


namespace Ui {
class adminAcceptedComplaints;
}

class adminAcceptedComplaints : public QDialog
{
    Q_OBJECT

public:
    explicit adminAcceptedComplaints(QWidget *parent = nullptr);
    ~adminAcceptedComplaints();

private:
    Ui::adminAcceptedComplaints *ui;
    QSqlDatabase *mydb;
    QSqlTableModel *tModel;
};

#endif // ADMINACCEPTEDCOMPLAINTS_H
