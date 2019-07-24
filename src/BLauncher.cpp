#include "BLauncher.h"
#include "ui_BLauncher.h"

BLauncher::BLauncher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BLauncher)
{
    ui->setupUi(this);
}

BLauncher::~BLauncher()
{
    delete ui;
}
