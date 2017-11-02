#ifndef WREPORT_H
#define WREPORT_H

#include <QWidget>

namespace Ui {
class WReport;
}

class WReport : public QWidget
{
    Q_OBJECT

public:
    explicit WReport(QWidget *parent = 0);
    ~WReport();

private:
    Ui::WReport *ui;
};

#endif // WREPORT_H
