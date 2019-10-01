#include <BConsole.h>
#include "ui_BConsole.h"

#include <QTime>
#include <QPalette>
#include <QDebug>

namespace Uih {
class BConsoleHelper {
public:
    int maxTempRawDataLen = 1024;
    int recvRawDataLen = 0;
    QTimer rawDataTimer;

    void setupUi(BConsole *c) {

        rawDataTimer.setInterval(80);
        rawDataTimer.setSingleShot(false);
    }
};
}

/*!
 * \class Console
 * \ingroup ui
 * \inherits EasyWidget
 * \author BriFuture
 *
 * \brief 控制台界面
 *
 * It is the console widget to see all data between this qt program
 * and serial port, of course, it could save content in textbrowser
 * into local file, which could be helper in actually using.
 *
 * \code
 *   // in method of parent widget
 *   BcConsole *c = new BcConsole(this);
 *   connect( this, &ParentWidget::recvLine, c, &BcConsole::onRecvLineData);
 *   connect( this, &ParentWidget::recvraw,  c, &BcConsole::onRecvRawData );
 *   connect( this, &ParentWidget::sendData, c, &BcConsole::onSendData );
 *   // 接收到的原始数据，整行数据和发送到下位机的数据都会显示在界面上
 * \endcode
 */
BConsole::BConsole(QWidget *parent): QWidget(parent),
    ui( new Ui::BConsole ),
    uih(new Uih::BConsoleHelper)
{
    ui->setupUi( this );
    uih->setupUi(this);
    QObject::connect(&uih->rawDataTimer, &QTimer::timeout, this, &BConsole::showRawData);
    uih->rawDataTimer.start();

    ui->rawField->setReadOnly( true );
    ui->lineTextField->setReadOnly(true);
    ui->isHex->hide();
    ui->hexField->hide();

    connect( ui->clearBtn, &QPushButton::clicked, [=] {
        ui->rawField->clear();
        ui->lineTextField->clear();
        ui->hexField->clear();
        ui->sendField->clear();
    });
    connect( ui->saveBtn,  &QPushButton::clicked, [=] { this->saveLog(); });
    connect(ui->isHex, &QCheckBox::clicked, [=](bool checked) { ui->hexField->setVisible(checked); });

    connect( ui->specCharBox, &QCheckBox::clicked, [=](bool checked) {
        if( checked )
            ui->rawField->moveCursor( QTextCursor::End );
    });

    connect(ui->tabWidget, &QTabWidget::tabBarClicked, this, &BConsole::onTabBarClicked );
    tempRawData.resize(uih->maxTempRawDataLen);

}

BConsole::~BConsole()
{
    delete ui;
    delete uih;
}

void BConsole::beautify()
{
    ui->lineTextField->setProperty("console", true);
    style()->unpolish(ui->lineTextField);
    style()->polish(ui->lineTextField);
}

void BConsole::retranslateUi()
{
    ui->retranslateUi(this);
}


/**
 * !brief  将 textEdit 中的内容保存到指定文件中
 */
void BConsole::saveLog(bool line) {
    QString filename = QFileDialog::getSaveFileName(this, "LogTextBrowser", "", "*.txt");//设置文件
    //filename+=".txt";
    if( !filename.isEmpty() )
    {
        QFile file(filename);  //为文件取内存
        file.open(QFile::WriteOnly);  //打开文件
        bool toLineDataSave = (ui->tabWidget->currentIndex() == 0);
        if(toLineDataSave)
            file.write(ui->lineTextField->toPlainText().toLatin1());   //写文件
        else
            file.write(ui->rawField->toPlainText().toLatin1());   //写文件
        file.close();    //关文件
        file.deleteLater();
    }
}

void BConsole::onTabBarClicked(int index)
{
    bool line = (index == 0);
    emit dataModeChanged(line);
    ui->isHex->setVisible(!line);
    if(line) {
        ui->saveBtn->setText(tr("Save Line Data"));
        lastHexEnabled = ui->isHex->isChecked();
        ui->isHex->setChecked(false);  // performance issue，切换到 line 模式，禁用 hex 转换
    } else {
        ui->saveBtn->setText(tr("Save Raw Data"));
        ui->isHex->setChecked(lastHexEnabled);
    }
}

/**
 * @brief Console::onDataSent
 * @param tmpText
 * 发送数据到下位机时，将其输出到文本框中
 */
void BConsole::onSendData(const QByteArray &tmpText) {
    QByteArray t = currentTimeStr().toLatin1();
    ui->sendField->appendPlainText( t.append( tmpText ) );
}


/** 设置操作按钮/复选框等是否可见 */
void BConsole::settingsVisible(bool visible)
{
    ui->settingGroup->setVisible( visible );
}

void BConsole::setRawDataRefreshMs(int ms)
{
    if(ms < 50) {
        ms = 50;
    }
    uih->rawDataTimer.start(ms);
}

void BConsole::setRawDataBufferSize(int bytes)
{
    if(bytes < 4096) {
        bytes = 4096;
    }
    tempRawData.resize(bytes);
    uih->maxTempRawDataLen = bytes;
}


void BConsole::setTabRawData()
{
    ui->tabWidget->setCurrentIndex(1);
    onTabBarClicked(1);
}


/** 接收到一行数据 */
/** 将接收到的数据显示在 textEdit 中 */
void BConsole::onRecvLineData(const QByteArray &tmpText) {
    if( !this->isVisible()) {
        return;
    }
    ui->lineTextField->moveCursor(QTextCursor::End);
    ui->lineTextField->insertPlainText("\n" + currentTimeStr());          // 不添加回车换行，但自动移动光标
//    ui->lineTextField->insertPlainText("TEst");
    QByteArray display = tmpText;
    bool hide = ui->specCharBox->isChecked();
    if(hide) {
        display.replace("\r\n", "");
        display.replace('\0', "");
        display.replace('\xff', "");
    } else {
        display.replace("\r\n", "\\n");
        display.replace('\0', "\\x00");
        display.replace('\xff', "\\ff");
    }
//    qDebug () << display << hide;
    ui->lineTextField->insertPlainText(display);  // 会在某条语句后面加上回车换行，并更新光标位置
    ui->lineTextField->moveCursor(QTextCursor::End);
}



/** 返回时间字符串，若 datetimeBox 未勾选，则不会返回时间字符串 */
QString BConsole::currentTimeStr() {
    QString c;
    if( ui->datetimeBox->isChecked() ) {
        QString time = QTime::currentTime().toString( "hh:mm:ss.zzz" );
        c = QString("[%0]  ").arg( time );
    }
    return c;
}


void BConsole::setRawDataFormat(bool hex)
{
    ui->hexField->setVisible(hex);

    ui->hexField->moveCursor(QTextCursor::End);
    ui->rawField->moveCursor(QTextCursor::End);
    ui->isHex->setChecked(hex);
}

/*! 接收原始数据 */
void BConsole::onRecvRawData(const QByteArray &tmpText) {
    if(!this->isVisible()) {
        return;
    }
    if(ui->lineTextField->isVisible() && ui->stopRaw->isChecked()) {
        return;
    }
    copyRawData(tmpText);
}

void BConsole::showRawData() {

    //    ui->rawField->appendPlainText( display  );  // 会在某条语句后面加上回车换行，并更新光标位置
    if(uih->recvRawDataLen == 0) {
        return;
    }
    ui->rawField->moveCursor(QTextCursor::End);
    bool hex = ui->isHex->isChecked();
    if(hex) {
        int count = 0;
        qDebug() << uih->recvRawDataLen;
        // 64 characters is displayed each line
        while(count + 64 < uih->recvRawDataLen) {
            ui->hexField->appendPlainText(QString(tempRawData.mid(count, 64).toHex()));
            count += 64;
        }
        if(count < uih->recvRawDataLen) {
            ui->hexField->insertPlainText(QString(tempRawData.mid(count, uih->recvRawDataLen - count).toHex()));
        }
    }

    ui->rawField->insertPlainText(QString(tempRawData.left(uih->recvRawDataLen)));          // 不添加回车换行
    ui->rawField->moveCursor(QTextCursor::End);

    uih->recvRawDataLen = 0;
}

void BConsole::copyRawData(const QByteArray &tmpText) {

    int len = tmpText.length();
    memcpy(tempRawData.data() + uih->recvRawDataLen, tmpText.data(), static_cast<size_t>(len));
//    qDebug() << tmpText << len;
    uih->recvRawDataLen += len;
    if(uih->recvRawDataLen > uih->maxTempRawDataLen - 512) {
        showRawData();
    }
}
