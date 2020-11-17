#include "adminregisterdialog.h"
#include "ui_adminregisterdialog.h"

adminRegisterDialog::adminRegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminRegisterDialog)
{
    ui->setupUi(this);
}

adminRegisterDialog::~adminRegisterDialog()
{
    delete ui;
}

void adminRegisterDialog::on_cancelButton_clicked()
{
    QDialog::close();
}

void adminRegisterDialog::on_registerButton_clicked()
{
    QString name = ui->nameEdit->text();
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    QString phoneNo = ui->phoneNoEdit->text();
    QString email = ui->emailEdit->text();
    QString sc = ui->securityCodeEdit->text();

    if(sc != SECURITY_CODE) {
        QMessageBox::warning(this, "Wrong Security Code", "Security Code doesn't match");
    }
    else {
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QMYSQL");
        mydb.setHostName("localhost");
        mydb.setUserName("root");
        mydb.setPassword("Love@1225");
        mydb.setDatabaseName("ComplaintManagement");

        if(mydb.open()) {
            ui->statusLabel->setText("Connected to Database");
            QSqlQuery qry;
            qry.prepare(QString("INSERT INTO admins(name, username, password, phoneNo, email) values(:name, :username, :password, :phoneNo, :email)"));
            qry.bindValue(":name", name);
            qry.bindValue(":username", username);
            qry.bindValue(":password", password);
            qry.bindValue(":phoneNo", phoneNo);
            qry.bindValue(":email", email);

            if(qry.exec()) {
                QMessageBox::information(this, "Registered Successfully", "Return to login page");
                QDialog::close();
            }
            else
                QMessageBox::critical(this, "Query not passed", qry.lastError().text());
            mydb.close();
        }
        else
            QMessageBox::critical(this, "Not Able to Connect to Database", mydb.lastError().text());
    }
}
