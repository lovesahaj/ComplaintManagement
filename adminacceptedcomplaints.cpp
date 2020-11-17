#include "adminacceptedcomplaints.h"
#include "ui_adminacceptedcomplaints.h"

adminAcceptedComplaints::adminAcceptedComplaints(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminAcceptedComplaints)
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
        tModel = new QSqlTableModel;
        tModel->setTable("Complaints");
        tModel->setFilter("accepted = true");
        tModel->select();
        ui->tableView->setModel(tModel);
    }

}

adminAcceptedComplaints::~adminAcceptedComplaints()
{
    mydb->close();
    delete ui;
}
