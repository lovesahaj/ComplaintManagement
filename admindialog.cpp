#include "admindialog.h"
#include "ui_admindialog.h"

adminDialog::adminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDialog)
{
    ui->setupUi(this);
    QStringList cate = {"Product/Service Related Complaint",
                       "Customer Support Service Glitches",
                       "First-time complaint",
                       "Reoccuriing Issues",
                       "Marketing Miscues",
                       "Angry Rants",
                       "Fake Grivances"};
    ui->categorySelect->addItems(cate);
    ui->acceptedSelect->addItems({"Not Accepted", "Accepted"});

    mydb = new QSqlDatabase;
    *mydb = QSqlDatabase::addDatabase("QMYSQL" , "MySql");
    mydb->setHostName("localhost");
    mydb->setUserName("root");
    mydb->setPassword("Love@1225");
    mydb->setDatabaseName("ComplaintManagement");

    if(!mydb->open()){
        QMessageBox::critical(this, "Not Connected To Database", mydb->lastError().text());
    }
    else {
        QStringList ids;
        ui->status->setText("Connected to Database");
        QSqlQuery qry("SELECT COUNT(*) FROM Complaints");
        while(qry.next()) {
            int t = qry.value(0).toInt();
            for (int i = 1; i <= t ; i++) {
                ids.append(QString::number(i));
            }
            ui->selectID->addItems(ids);
        }
    }
    QDateTime local(QDateTime::currentDateTime());
    ui->dateText->setText(local.toString());
}

adminDialog::~adminDialog()
{
    mydb->close();
    delete ui;
}

void adminDialog::on_selectID_currentIndexChanged(int index)
{
    int t = index;
    index = t;
}

void adminDialog::on_findID_clicked()
{
    QString index = ui->selectID->currentText();
    if(!mydb->open()){
        QMessageBox::critical(this, "Not Connected To Database", mydb->lastError().text());
    }
    else {
        QSqlQuery qry("MySql");
        qry.prepare("SELECT name, email, phoneNo, address, category, description, accepted from Complaints where id = :idx");
        qry.bindValue(":idx", index);
        if(!qry.exec()) {
            QMessageBox::warning(this, "Failed", qry.lastError().text());
        }
        else {
            while(qry.next()){
                QString name = qry.value(0).toString();
                QString email = qry.value(1).toString();
                QString phoneNo = qry.value(2).toString();
                QString address = qry.value(3).toString();
                QString category = qry.value(4).toString();
                QString details = qry.value(5).toString();
                bool accepted = qry.value(6).toBool();

                ui->nameEdit->setText(name);
                ui->emailEdit->setText(email);
                ui->phoneEdit->setText(phoneNo);
                ui->addressEdit->setText(address);
                ui->categorySelect->setCurrentText(category);
                ui->descriptionEdit->setText(details);
                ui->acceptedSelect->setCurrentIndex(accepted);
            }
        }
    }
}

void adminDialog::on_doneButton_clicked()
{
    QString name = ui->nameEdit->text();
    QString email = ui->emailEdit->text();
    QString phoneNo = ui->phoneEdit->text();
    QString address = ui->addressEdit->text();
    QString category = ui->categorySelect->currentText();
    QString details = ui->descriptionEdit->toPlainText();
    QString idx = ui->selectID->currentText();
    bool accepted;
    if(ui->acceptedSelect->currentText() == "Accepted")
        accepted = true;
    else
        accepted = false;

    if(!mydb->open()){
        QMessageBox::critical(this, "Not Connected To Database", mydb->lastError().text());
    }
    else {
        QSqlQuery qry("MySql");
        qry.prepare("update Complaints set name = :name, email =:email, phoneNo = :phoneNo, address = :address, category = :category, description = :description, accepted = :accepted where id = :idx");
        qry.bindValue(":name", name);
        qry.bindValue(":email", email);
        qry.bindValue(":phoneNo", phoneNo);
        qry.bindValue(":address", address);
        qry.bindValue(":category", category);
        qry.bindValue(":description", details);
        qry.bindValue(":idx", idx);
        qry.bindValue(":accepted", accepted);

        if(!qry.exec()) {
            QMessageBox::warning(this, "Failed", qry.lastError().text());
        }
        else {
            QMessageBox::information(this, "Sucessful", "Made changes");
        }
    }
}

void adminDialog::on_cancelButton_clicked()
{
    QDialog::close();
}

void adminDialog::on_allComplaintsButton_clicked()
{
    adminAllComplaints allComp;
    allComp.setModal(true);
    allComp.exec();
}

void adminDialog::on_acceptedComplaitsButton_clicked()
{
    adminAcceptedComplaints accComp;
    accComp.setModal(true);
    accComp.exec();
}

void adminDialog::on_printButton_clicked()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog dialog(&printer, this);
    if(dialog.exec() == QDialog::Rejected)
        return;
    QString printFormat = "Name -\t\t" + ui->nameEdit->text() + "\n"
                        + "Email -\t\t" + ui->emailEdit->text() + "\n"
                        + "Phone No. -\t" + ui->phoneEdit->text() + "\n"
                        + "Address - \t" + ui->addressEdit->text() + "\n"
                        + "Category -\t" + ui->categorySelect->currentText() + "\n"
                        + "Description -\t" + ui->descriptionEdit->toPlainText() + "\n"
                        + "Status -\t\t" + ui->acceptedSelect->currentText() + "\n\n\n\n\n"
                        + "Date/Time - \t" + ui->dateText->text() + "\n";
    ui->printerText->setText(printFormat);
    ui->printerText->print(&printer);
}
