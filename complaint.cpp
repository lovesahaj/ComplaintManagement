#include "complaint.h"

Complaint::Complaint() {

}

void Complaint::setName(string name) {
    this->name = name;
}

void Complaint::setEmail(string email) {
    this->email = email;
}

void Complaint::setPhoneNo(string phoneNo) {
    this->phoneNo = phoneNo;
}

void Complaint::setAddress(string address) {
    this->address = address;
}

void Complaint::setCategory(string category) {
    this->category = category;
}

void Complaint::setCompDetail(string compDetail) {
    this->compDetail = compDetail;
}

//void operator<< (ofstream &out, Complaint c) {
//    out.open("Complaints.csv", std::ofstream::out | std::ofstream::app);
//    out     << c.name << ", "
//            << c.email << ", "
//            << c.phoneNo << ", "
//            << c.address << ", "
//            << c.category << ", "
//            << c.compDetail << "\n";
//}

void operator<< (ostream &out, Complaint c) {
    out     << c.name << ", "
            << c.email << ", "
            << c.phoneNo << ", "
            << c.address << ", "
            << c.category << ", "
            << c.compDetail << "\n";
}

bool Complaint::printToDatabase() {
    QSqlQuery qry;
    qry.prepare("INSERT INTO Complaints(name, email, phoneNo, address, category, description) value(:name, :email, :phoneNo, :address, :category, :description)");
    qry.bindValue(":name", QString::fromStdString(name));
    qry.bindValue(":email", QString::fromStdString(email));
    qry.bindValue(":phoneNo", QString::fromStdString(phoneNo));
    qry.bindValue(":address", QString::fromStdString(address));
    qry.bindValue(":category", QString::fromStdString(category));
    qry.bindValue(":description", QString::fromStdString(compDetail));

    if(qry.exec()){
        return true;
    }
    else {
        throw qry.lastError().text();
        return false;
    }
}
