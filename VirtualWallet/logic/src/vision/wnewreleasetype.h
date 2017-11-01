#ifndef WNEWRELEASETYPE_H
#define WNEWRELEASETYPE_H

#include <QWidget>
#include <string>
#include <list>
#include "./src/control/Facade.h"

using namespace project;

namespace Ui {
class WNewReleaseType;
}

class WNewReleaseType : public QWidget
{
    Q_OBJECT

public:
    explicit WNewReleaseType(QWidget *parent = 0);
    ~WNewReleaseType();

    void setFacade(Facade & _facade);

public slots:
    void tableBuilder();

private slots:
    void on_Clean_clicked();

    void on_Confirm_clicked();

    void on_TypeList_clicked(const QModelIndex &index);

    void on_Delete_clicked();

signals:
    void build();

private:
    Ui::WNewReleaseType *ui;
    Facade * facade;
};

#endif // WNEWRELEASETYPE_H
