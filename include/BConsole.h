#ifndef BCONSOLE_H
#define BCONSOLE_H

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QFile>
#include <QFileDialog>
#include <QCheckBox>
#include <QEvent>
#include <QTextEdit>
#include <QTimer>

#include "builib_global.h"

namespace Ui {
    class BConsole;
}

namespace Uih {
class BConsoleHelper;
}

class BUILIBSHARED_EXPORT BConsole : public QWidget
{
    Q_OBJECT

public:
    explicit BConsole(QWidget *parent = nullptr);
    ~BConsole();
    void beautify();

signals:
    void visibleChange(bool visible);
    void dataModeChanged(bool line);

public slots:
    void retranslateUi();

    void onRecvLineData(const QByteArray &tmpText);

    void onRecvRawData(const QByteArray &tmpText);

    void onSendData(const QByteArray &tmpText);

    void settingsVisible(bool visible);

    void setRawDataRefreshMs(int ms);
    void setRawDataBufferSize(int bytes);

    void setRawDataFormat(bool hex);
    void setTabRawData();

protected:

    void copyRawData(const QByteArray &tmpText);
protected Q_SLOTS:
    void saveLog(bool line = true);
    void onTabBarClicked(int index);

    QString currentTimeStr();
    void showRawData();
private:
    Ui::BConsole *ui = nullptr;
    Uih::BConsoleHelper *uih = nullptr;
};

#endif // BCONSOLE_H
