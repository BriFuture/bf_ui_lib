#ifndef BLOADINGWIDGET_H
#define BLOADINGWIDGET_H

#include <QDialog>
#include <QTimer>
#include <QProgressBar>

#include "builib_global.h"

namespace Ui {
class BLoadingDialog;
}

class BUILIBSHARED_EXPORT BLoadingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BLoadingDialog(QWidget *parent = 0);
    ~BLoadingDialog();

    inline void setWaitSeconds(int seconds) {
        setWaitMillSeconds(seconds * 1000);
    }

    void setWaitMillSeconds(int ms);

    void setProgress(int percent);

    void setAction(const QString &action);

    void setDetailVisible(bool visible);
    void appendDetail(const QString &detail);
signals:
    void cancled();

public slots:
    void start();
    void stop();
    void resume();

    void progressMoveOn();

private slots:
    void on_closeBtn_clicked();

private:
    Ui::BLoadingDialog *ui = nullptr;
    QTimer progressTimer;
    int m_maxWaitingMs = -1;
    int elapsedMs;
};

#endif // BLOADINGWIDGET_H
