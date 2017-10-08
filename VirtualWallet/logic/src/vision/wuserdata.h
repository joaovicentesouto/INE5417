#ifndef WUSERDATA_H
#define WUSERDATA_H

#include <QWidget>

namespace Ui {
class WUserData;
}

class WUserData : public QWidget
{
    Q_OBJECT

public:
    explicit WUserData(QWidget *parent = 0);
    ~WUserData();

private:
    Ui::WUserData *ui;
};

#endif // WUSERDATA_H
