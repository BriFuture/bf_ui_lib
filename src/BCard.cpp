#include "BCard.h"
#include "ui_BCard.h"

BCard::BCard(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::BCard)
{
    ui->setupUi(this);
    setFrameShape(QFrame::StyledPanel);
    ui->detail->setWordWrap(true);
}

BCard::~BCard()
{
    delete ui;
}

void BCard::setCardTitle(const QString &title)
{
    ui->title->setText(title);
}

void BCard::setCardDetial(const QString &text)
{
    ui->detail->setText(text);
}

void BCard::setActionBtnText(const QString &text)
{
    ui->actionBtn->setText(text);
}

void BCard::setImage(const QPixmap &img)
{
    ui->image->setPixmap(img);
}

void BCard::setImageMaxSize(const QSize &size)
{
    ui->image->setMaximumSize(size);
}

QPushButton *BCard::button() const
{
    return ui->actionBtn;
}
