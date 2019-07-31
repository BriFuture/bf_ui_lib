#ifndef BLOADINGWIDGET_H
#define BLOADINGWIDGET_H

#include <QDialog>
#include <QTimer>
#include <QProgressBar>
#include <QStringList>

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

    inline void setAutoClose(bool ac) {
        m_autoClose = ac;
    }

    inline void setId(int id) {
        m_id = id;
    }

    inline int id() const {
        return m_id;
    }

    void setPreDetails(const QStringList &sl);

    void setWaitMillSeconds(int ms);

    void setProgress(int percent);

    void setAction(const QString &action);

    void setDetailVisible(bool visible);
    void appendDetail(const QString &detail);

    void setBtnFrameVisible(bool visible);

    void setBufferTime(int bufferPercent);
    void setStackTop(bool top);
signals:
    void cancled();
    void timeout(int id = 0);
    void bufferTimeOut(int id = 0);

public slots:
    void start(const QString &action = QString());
    void stop();
    void resume();
    void reset();
    void finish();

    void clearDetail();

    void progressMoveOn();

private slots:
    void on_closeBtn_clicked();

private:
    Ui::BLoadingDialog *ui = nullptr;
    QTimer progressTimer;
    int m_maxWaitingMs = -1;
    int elapsedMs;
    int m_bufferPercent;

    QStringList preDetails;
    int preDetailSeg;
    int preDetailSegLen;

    bool m_autoClose = false;

    int m_id = 0;
};

#endif // BLOADINGWIDGET_H
