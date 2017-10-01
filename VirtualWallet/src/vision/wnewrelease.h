#ifndef WNEWRELEASE_H
#define WNEWRELEASE_H

#include <QWidget>

namespace Ui {
class WNewRelease;
}

class WNewRelease : public QWidget
{
    Q_OBJECT

public:
    explicit WNewRelease(QWidget *parent = 0);
    ~WNewRelease();

private:
    Ui::WNewRelease *ui;
};

#endif // WNEWRELEASE_H
