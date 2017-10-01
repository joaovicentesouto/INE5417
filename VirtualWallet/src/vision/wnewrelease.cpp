#include "wnewrelease.h"
#include "ui_wnewrelease.h"

WNewRelease::WNewRelease(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WNewRelease)
{
    ui->setupUi(this);
}

WNewRelease::~WNewRelease()
{
    delete ui;
}
