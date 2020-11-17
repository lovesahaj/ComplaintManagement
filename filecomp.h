#ifndef FILECOMP_H
#define FILECOMP_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class fileComp;
}

class fileComp : public QDialog
{
    Q_OBJECT

public:
    explicit fileComp(QWidget *parent = nullptr);
    ~fileComp();

private slots:
    void on_cancelButton_clicked();

    void on_doneButtone_clicked();

private:
    Ui::fileComp *ui;
};

#endif // FILECOMP_H
