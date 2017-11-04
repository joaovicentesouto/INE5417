#ifndef WREPORT_H
#define WREPORT_H

#include <QtWidgets/QWidget>
#include <QtCharts>
#include <QGridLayout>
#include <QWidget>
#include <string>
#include <list>

#include "./src/model/Report.h"
#include "./src/control/Facade.h"
#include "./src/resources/linked_list.h"
#include "./src/control/ReportBuilder.h"

using namespace project;
using namespace QtCharts;

namespace Ui {
class WReport;
}

class WReport : public QWidget
{
    Q_OBJECT

public:
    explicit WReport(QWidget * parent = 0);
    ~WReport();

    void setFacade(Facade * _facade);

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
    void on_Confirm_clicked();
    void on_Rep_Back_clicked();

private:
    Ui::WReport * ui;
    Facade * facade;
    Report * report{nullptr};

    structures::LinkedList<int> accounts;
    structures::LinkedList<int> typesReleases;
    structures::LinkedList<std::string> typesPayments;

    QChartView *chartView{nullptr};
};

#endif // WREPORT_H
