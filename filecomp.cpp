#include "filecomp.h"
#include "ui_filecomp.h"
#include <QMessageBox>
#include "complaint.h"
#include "fstream"
#include <iostream>

fileComp::fileComp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fileComp)
{
    ui->setupUi(this);
    QStringList cate = {"Product/Service Related Complaint",
                       "Customer Support Service Glitches",
                       "First-time complaint",
                       "Reoccuriing Issues",
                       "Marketing Miscues",
                       "Angry Rants",
                       "Fake Grivances"};
    ui->categoryInput->addItems(cate);
}

fileComp::~fileComp()
{
    delete ui;
}

void fileComp::on_cancelButton_clicked()
{
    QDialog::close();
}

void fileComp::on_doneButtone_clicked()
{
    QString name = ui->nameInput->text();
    QString address = ui->addressInput->text();
    QString phoneNo = ui->phoneInput->text();
    QString email = ui->emailInput->text();
    QString category = ui->categoryInput->currentText();
    QString text = ui->compDetailInput->toPlainText();

    Complaint C1;
    C1.setName(name.toStdString());
    C1.setEmail(email.toStdString());
    C1.setAddress(address.toStdString());
    C1.setCategory(category.toStdString());
    C1.setPhoneNo(phoneNo.toStdString());
    C1.setCompDetail(text.toStdString());

    std::cout << C1;

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QMYSQL");
    mydb.setHostName("localhost");
    mydb.setUserName("root");
    mydb.setPassword("Love@1225");
    mydb.setDatabaseName("ComplaintManagement");

    if(mydb.open()) {
        ui->status->setText("Connected");
        try {
            C1.printToDatabase();
        }  catch (QString x) {
            QMessageBox::warning(this, "Not Able to insert", x);
        }
        QMessageBox::information(this, "Accepted", "Complaint Registed Successfully");
    }
    else {
        QMessageBox::warning(this, "Not Able to Connect", mydb.lastError().text());
    }

//    ofstream out;
//    out << C1;
//    QDialog::close();
    mydb.close();
    QDialog::close();
}
