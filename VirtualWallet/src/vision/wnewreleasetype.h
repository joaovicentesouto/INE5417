#ifndef WNEWRELEASETYPE_H
#define WNEWRELEASETYPE_H

#include <QWidget>
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

private slots:
    void on_Clean_clicked();

    void on_Confirm_clicked();

signals:
    void goToHome();

private:
    Ui::WNewReleaseType *ui;
    Facade * facade;
};

#endif // WNEWRELEASETYPE_H
