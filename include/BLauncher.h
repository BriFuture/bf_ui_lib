#ifndef BLAUNCHER_H
#define BLAUNCHER_H

#include <QWidget>
#include <QSplashScreen>
#include <QPixmap>
#include <QTimer>

#include "builib_global.h"

namespace Ui {
class BLauncher;
}

class BUILIBSHARED_EXPORT BLauncher : public QSplashScreen
{
    Q_OBJECT

public:
    explicit BLauncher(const QPixmap &pixmap = QPixmap(), QWidget *parent = 0);
    ~BLauncher();

    void appendMessage(const QString &msg, const QString &color=QString("black"));

    // moveonMode: from last percent(p) to (p + progressPercent)
    void startProgress(int progress, int estMs = 1000);

    inline void setProgressMode(bool moveon) {
        progressMoveon = moveon;
    }

    void setEndMsg(const QString &endMsg);

protected slots:
    void refreshProgressBar();
    void finishLast();

private:
    bool eventFilter(QObject *watched, QEvent *event);
    Ui::BLauncher *ui = nullptr;
    QTimer progressTimer;
    bool progressMoveon = true;
    int maxWaitingMs = 0;
    int elaspedMs = 0;
    double maxProgressPercent = 0.0;
    double lastProgressPercent = 0.0;
    double progressStep = 1.0;

    QString m_endMsg;
};

#endif // BLAUNCHER_H
