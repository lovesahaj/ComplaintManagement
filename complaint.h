#ifndef COMPLAINT_H
#define COMPLAINT_H
#include <fstream>
#include <iostream>
#include <QSqlDatabase>
#include <QSql>
#include <QtSql>
#include <QMessageBox>

using namespace std;

class Complaint
{
    string name, email, phoneNo, address;
    string category, compDetail;
public:
    Complaint();
    void setName(string name);
    void setEmail(string email);
    void setPhoneNo(string phoneNo);
    void setAddress(string address);
    void setCategory(string category);
    void setCompDetail (string compDetail);
//    friend void operator<<(ofstream &, Complaint);
    friend void operator<<(ostream &, Complaint);
    bool printToDatabase();
};

#endif // COMPLAINT_H
