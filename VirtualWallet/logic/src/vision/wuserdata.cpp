#include "wuserdata.h"
#include "ui_wuserdata.h"

WUserData::WUserData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WUserData)
{
    ui->setupUi(this);
}

WUserData::~WUserData()
{
    delete ui;
}
