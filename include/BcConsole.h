#ifndef CONSOLE_H
#define CONSOLE_H

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QFile>
#include <QFileDialog>
#include <QCheckBox>
#include <QEvent>
#include <QTextEdit>
#include <QTimer>

#include <BcWidgets/BcEasyWidget.h>

namespace Ui {
    class BcConsole;
}

namespace Uih {
class BcConsoleHelper;
}

class BC_DLL_EXPORT BcConsole : public BcEasyWidget
{
    Q_OBJECT

public:
    explicit BcConsole(QWidget *parent = nullptr);
    ~BcConsole();
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

protected:
    void copyRawData(const QByteArray &tmpText);
protected Q_SLOTS:
    void saveLog(bool line = true);

    QString currentTimeStr();
    void showRawData();
private:
    Ui::BcConsole *ui = nullptr;
    Uih::BcConsoleHelper *uih = nullptr;
};

#endif // CONSOLE_H
