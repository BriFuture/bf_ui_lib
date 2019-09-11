#include "BLauncher.h"
#include "ui_BLauncher.h"

#include <math.h>
#include <QDebug>

#define ProgressRefreshMs 10

BLauncher::BLauncher(const QPixmap &pixmap, QWidget *parent) :
    QSplashScreen(parent),
    ui(new Ui::BLauncher)
{
    ui->setupUi(this);
    setPixmap(pixmap);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_AlwaysStackOnTop);
    progressTimer.setInterval(ProgressRefreshMs);
    progressTimer.setSingleShot(false);

    connect(&progressTimer, &QTimer::timeout, this, &BLauncher::refreshProgressBar);
//    installEventFilter(this);
}

BLauncher::~BLauncher()
{
    delete ui;
}

void BLauncher::appendMessage(const QString &msg, const QString &color)
{
    showMessage(msg);
    ui->msgTextEdit->insertHtml(QString("<br><font color='%1'>%2</font>\n").arg(color).arg(msg));
    ui->msgTextEdit->moveCursor(QTextCursor::End);
}

// progress from 1 to 1000
void BLauncher::startProgress(int progress, int estMs)
{
    finishLast();

    if(progress < 1) {
        progress = 1;
    }
    maxProgressPercent += progress;
    lastProgressPercent = ui->bLauncherProgressBar->value();
    if(estMs < 0) {
        estMs = 50;
    }
    maxWaitingMs = estMs;
    elaspedMs = 0;
    progressStep = (progress * ProgressRefreshMs + 0.0) / estMs;
    if(progressStep < 0.1) {
        progress = 0.1;
    }
    progressTimer.start();
}

void BLauncher::setEndMsg(const QString &endMsg)
{
    if(!m_endMsg.isEmpty()) {
        appendMessage(m_endMsg);
    }
    m_endMsg = endMsg;
}


void BLauncher::refreshProgressBar()
{
    if(elaspedMs > maxWaitingMs) {
        progressTimer.stop();
        finishLast();
    }
    elaspedMs += ProgressRefreshMs;
    if(progressMoveon) {
        lastProgressPercent += progressStep;
//        qDebug() << ceil(lastProgressPercent) << lastProgressPercent << progressStep;
        ui->bLauncherProgressBar->setValue(ceil(lastProgressPercent));
        maxProgressPercent -= progressStep;

    } else {

    }
}

void BLauncher::finishLast()
{
    if(!m_endMsg.isEmpty()) {
        appendMessage(m_endMsg, "green");
        m_endMsg.clear();
    }
    if(maxProgressPercent > 0) {
        lastProgressPercent += maxProgressPercent;
        ui->bLauncherProgressBar->setValue(ceil(lastProgressPercent));
        maxProgressPercent = 0;
    }
}

bool BLauncher::eventFilter(QObject *watched, QEvent *event)
{
    if(watched != this) {
        return false;
    }
    if((event->type() == QEvent::MouseButtonPress) ||
             (event->type() == QEvent::MouseButtonDblClick) ||
             (event->type() == QEvent::MouseButtonRelease) ||
             (event->type() == QEvent::KeyPress) ||
             (event->type() == QEvent::KeyRelease))
         return true;
    return false;
}


