#ifndef WREPORT_H
#define WREPORT_H

#include <QWidget>
#include <string>
#include <list>
#include "./src/control/Facade.h"
#include "./src/resources/linked_list.h"

using namespace project;

namespace Ui {
class WReport;
}

class WReport : public QWidget
{
    Q_OBJECT

public:
    explicit WReport(QWidget *parent = 0);
    ~WReport();

    void setFacade(Facade &_facade);

private slots:
    void on_ValueBox_1_valueChanged(double arg1);
    void on_ValueBox_2_valueChanged(double arg1);

    void tableBuilder();

    void on_AccTable_clicked(const QModelIndex &index);

    void on_TypesTable_clicked(const QModelIndex &index);

    void on_PayTable_clicked(const QModelIndex &index);

    void on_AllAccs_clicked();

    void on_AllTypes_clicked();

    void on_AllPay_clicked();

    void on_Clean_clicked();

    void on_DateEdit_1_dateChanged(const QDate &date);

    void on_DateEdit_2_dateChanged(const QDate &date);

private:
    Ui::WReport *ui;
    Facade * facade;

    structures::LinkedList<std::string> accounts;
    structures::LinkedList<std::string> typesReleases;
    structures::LinkedList<std::string> typesPayments;
};

#endif // WREPORT_H
