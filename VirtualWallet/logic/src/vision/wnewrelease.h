#ifndef WNEWRELEASE_H
#define WNEWRELEASE_H

#include <QWidget>
#include "./src/control/Facade.h"

using namespace project;

namespace Ui {
class WNewRelease;
}

class WNewRelease : public QWidget
{
    Q_OBJECT

public:
    explicit WNewRelease(QWidget *parent = 0);
    ~WNewRelease();

    void setFacade(Facade &_facade);

public slots:
    void tableBuilder();

public slots:
    void update();

private slots:
    void on_Clean_clicked();

    void on_Confirm_clicked();

signals:
    void build();

private:
    Ui::WNewRelease *ui;
    Facade * facade;
};

#endif // WNEWRELEASE_H
