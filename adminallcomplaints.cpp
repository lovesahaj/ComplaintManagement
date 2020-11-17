#include "adminallcomplaints.h"
#include "ui_adminallcomplaints.h"

adminAllComplaints::adminAllComplaints(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminAllComplaints)
{
    ui->setupUi(this);
    mydb = new QSqlDatabase;
    *mydb = QSqlDatabase::addDatabase("QMYSQL" , "MySql");
    mydb->setHostName("localhost");
    mydb->setUserName("root");
    mydb->setPassword("Love@1225");
    mydb->setDatabaseName("ComplaintManagement");

    if(!mydb->open()) {
        QMessageBox::critical(this, "Database not Connected", mydb->lastError().text());
        QDialog::close();
    }
    else {
        qModel = new QSqlQueryModel();
        qModel->setQuery("SELECT * FROM Complaints");
        ui->tableView->setModel(qModel);
    }
}

adminAllComplaints::~adminAllComplaints()
{
    mydb->close();
    delete ui;
}
