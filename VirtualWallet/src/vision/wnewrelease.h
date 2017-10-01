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
    void update();

signals:
    void goToHome();

private:
    Ui::WNewRelease *ui;
    Facade * facade;
};

#endif // WNEWRELEASE_H
