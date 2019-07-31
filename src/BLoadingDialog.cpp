#include "BLoadingDialog.h"
#include "ui_BLoadingDialog.h"

#define ProgressTimerMs 30

BLoadingDialog::BLoadingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BLoadingDialog)
{
    ui->setupUi(this);
    elapsedMs = 0;
    m_maxWaitingMs = 100 * ProgressTimerMs;
    ui->progressBar->setRange(0, 100);

    progressTimer.setSingleShot(false);
    progressTimer.setInterval(ProgressTimerMs);
    connect(&progressTimer, &QTimer::timeout, this, &BLoadingDialog::progressMoveOn);
}

BLoadingDialog::~BLoadingDialog()
{
    delete ui;
}

void BLoadingDialog::setWaitMillSeconds(int ms)
{
    if(ms <= 0) {
        ui->progressBar->setMaximum(0);
    } else {
        ui->progressBar->setMaximum(100);
    }
    m_maxWaitingMs = ms;
}

void BLoadingDialog::setProgress(int percent)
{
    if(percent < 0) {
        percent = 0;
    } else if(percent > 100) {
        percent = 100;
    }
    ui->progressBar->setValue(percent);
}

void BLoadingDialog::setAction(const QString &action)
{
    ui->actionLabel->setText(action);
}

void BLoadingDialog::setDetailVisible(bool visible)
{
    ui->detailEdit->setVisible(visible);
    adjustSize();
    setFixedSize(size());
}

void BLoadingDialog::appendDetail(const QString &detail)
{
    ui->detailEdit->append(detail);
}

void BLoadingDialog::start()
{
    elapsedMs = 0;
    progressTimer.start();
}

void BLoadingDialog::stop()
{
    progressTimer.stop();
}

void BLoadingDialog::resume()
{
    progressTimer.start();
}


void BLoadingDialog::progressMoveOn()
{
    elapsedMs += ProgressTimerMs;
    int per = static_cast<int>(elapsedMs  * 100.0 / m_maxWaitingMs);
    if(per > 100) {
        progressTimer.stop();
    }
    ui->progressBar->setValue(per);
}

void BLoadingDialog::on_closeBtn_clicked()
{
    emit cancled();
    elapsedMs = 0;
    progressTimer.stop();
}
