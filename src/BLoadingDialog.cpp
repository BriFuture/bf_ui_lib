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

void BLoadingDialog::setPreDetails(const QStringList &sl)
{
    preDetails = sl;
    preDetailSegLen = static_cast<int>(100.0 / sl.length());
    if(preDetailSegLen < 1) {
        preDetailSegLen = 1;
    }
    preDetailSeg = 0;
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

void BLoadingDialog::progressMoveOn()
{
    elapsedMs += ProgressTimerMs;
    double percent = elapsedMs  * 100.0 / m_maxWaitingMs;
    int per = static_cast<int>(percent);
    if(per > 100 + m_bufferPercent) {
        progressTimer.stop();
        if(m_autoClose) {
            close();
        }
        emit bufferTimeOut(m_id);
    } else if(per > 100) {
        emit timeout(m_id);
    }

    if(per > preDetailSeg * preDetailSegLen) {
        if(preDetailSeg < preDetails.length())
            ui->detailEdit->append(preDetails.value(preDetailSeg) + "...");
        preDetailSeg += 1;
    }

    ui->progressBar->setValue(per);
}

void BLoadingDialog::setBtnFrameVisible(bool visible)
{
    ui->btnFrame->setVisible(visible);
    adjustSize();
    setFixedSize(size());
}

void BLoadingDialog::setBufferTime(int bufferPercent)
{
    if(bufferPercent < 0) {
        bufferPercent = 0;
    }
    m_bufferPercent = bufferPercent;
}

void BLoadingDialog::setStackTop(bool top)
{
    if(top) {
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    } else {
        setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
    }
}

void BLoadingDialog::start(const QString &action)
{
    if(!action.isNull()) {
        ui->actionLabel->setText(action);
    }
    show();
    ui->progressBar->setValue(0);
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

void BLoadingDialog::reset()
{
    elapsedMs = 0;
    progressTimer.stop();
    ui->progressBar->setValue(0);
}

void BLoadingDialog::finish()
{
    elapsedMs = m_maxWaitingMs;
}

void BLoadingDialog::clearDetail()
{
    ui->detailEdit->clear();
}

void BLoadingDialog::on_closeBtn_clicked()
{
    emit cancled();
    elapsedMs = 0;
    progressTimer.stop();
    close();
}
