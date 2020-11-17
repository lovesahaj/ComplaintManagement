#include "adminloginwindow.h"
#include "ui_adminloginwindow.h"
#include <QMessageBox>

bool isAdmin(std::string u, std::string p);

adminLoginWindow::adminLoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminLoginWindow)
{
    ui->setupUi(this);
}

adminLoginWindow::~adminLoginWindow()
{
    delete ui;
}

void adminLoginWindow::on_cancelButton_clicked()
{
    QDialog::close();
}

void adminLoginWindow::on_pushButton_clicked()
{
    QString username = ui->userIDEdit->text();
    QString password = ui->passwordEdit->text();

    if(isAdmin(username, password)) {
        QMessageBox::information(this, "Login", "Welcome"); // TODO
        // Create a dialog box for admin here
        adminDialog dia;
        dia.setModal(true);
        hide();
        dia.exec();
    }
    else{
        QMessageBox::warning(this, "Login", "Username or Password not correct");
    }
}

bool adminLoginWindow::isAdmin(QString username, QString pass){
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QMYSQL");
    mydb.setHostName("localhost");
    mydb.setUserName("root");
    mydb.setPassword("Love@1225");
    mydb.setDatabaseName("ComplaintManagement");

    if(mydb.open()) {
        QSqlQuery qry;
        qry.prepare(QString("SELECT * FROM admins WHERE username = :user AND password = :pass"));
        qry.bindValue(":user", username);
        qry.bindValue(":pass", pass);

        if (!qry.exec()) {
                    QMessageBox::warning(this, "Failed", "Query Failed to Execute");
                }
                else {
                    while(qry.next()) {
                        QString usernameDB = qry.value(2).toString();
                        QString passDB = qry.value(3).toString();

                        if(usernameDB == username && passDB == pass) {
                            return true;
                        }
                        else {
                            return false;
                        }
                    }
                }
    }
    else {
        QMessageBox::warning(this, "Not Able to Connect", mydb.lastError().text());
        QDialog::close();
    }
    mydb.close();
    return false;
}

void adminLoginWindow::on_registerButton_clicked()
{
    adminRegisterDialog ard;
    ard.setModal(true);
    ard.exec();
    QDialog::close();
    this->setModal(true);
    this->exec();
}

void adminLoginWindow::on_loginButton_clicked()
{

}


