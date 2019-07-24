#include "BAboutDialog.h"
#include "ui_BAboutDialog.h"

BAboutDialog::BAboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BAboutDialog)
{
    ui->setupUi(this);
}

BAboutDialog::~BAboutDialog()
{
    delete ui;
}
