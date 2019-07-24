#include "BAboutDialog.h"
#include "ui_BAboutDialog.h"
#include "BuiLib.h"

BAboutDialog::BAboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BAboutDialog)
{
    ui->setupUi(this);
    ui->buiDesc->setText(QString("Support By \n%1").arg(BuiLib::aboutBuiLib()));
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint);
    setWindowModality(Qt::WindowModal);
    setFixedSize(size());
    ui->buiLogo->setPixmap(QPixmap(":/res/logo/logo.jpg"));
    connect(ui->okBtn, &QPushButton::clicked, this, &QDialog::close);
}

BAboutDialog::~BAboutDialog()
{
    delete ui;
}

void BAboutDialog::setLogo(const QPixmap &pix)
{
    ui->logo->setPixmap(pix);
}

void BAboutDialog::setDesc(const QString &desc)
{
    ui->programDescLabel->setText(desc);
}

void BAboutDialog::setOwnership(const QString &desc)
{
    ui->ownerLabel->setText(desc);
}

void BAboutDialog::setRichDetail(const QString &detail)
{
    ui->details->insertHtml(detail);
}

void BAboutDialog::setDetail(const QString &detail)
{
    ui->details->setText(detail);
}

void BAboutDialog::addDetail(const QString &detail)
{
    ui->details->append(detail);
}

void BAboutDialog::setDetailVisible(bool visible)
{
    ui->details->setVisible(visible);
    adjustSize();
    setFixedSize(size());
}
