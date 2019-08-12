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

namespace Ui {
    class BcConsole;
}

namespace Uih {
class BConsoleHelper;
}

class BConsole : public QWidget
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

protected:
    void copyRawData(const QByteArray &tmpText);
protected Q_SLOTS:
    void saveLog(bool line = true);

    QString currentTimeStr();
    void showRawData();
private:
    Ui::BcConsole *ui = nullptr;
    Uih::BConsoleHelper *uih = nullptr;
};

#endif // CONSOLE_H
