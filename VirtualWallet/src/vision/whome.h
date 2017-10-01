#ifndef WHOME_H
#define WHOME_H

#include <QWidget>
#include "./src/control/Facade.h"
#include "waccount.h"

using namespace project;

namespace Ui {
class WHome;
}

class WHome : public QWidget
{
    Q_OBJECT

public:
    explicit WHome(QWidget *parent = 0);
    ~WHome();

    void setFacade(Facade &_facade);

public slots:
    void update();

private:
    Ui::WHome *ui;
    Facade *facade;
};

#endif // WHOME_H
