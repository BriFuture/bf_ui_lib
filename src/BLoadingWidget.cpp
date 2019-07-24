#include "BLoadingWidget.h"
#include "ui_BLoadingWidget.h"

BLoadingWidget::BLoadingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BLoadingWidget)
{
    ui->setupUi(this);
}

BLoadingWidget::~BLoadingWidget()
{
    delete ui;
}
