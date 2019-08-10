#include <BcWidgets/BcConsole.h>
#include "ui_bcconsole.h"

#include <QTime>
#include <QPalette>
#include <QMutex>
#include <QDebug>

namespace Uih {
class BcConsoleHelper {
public:
    QByteArray tempRawData;
    int maxTempRawDataLen = 4096;
    int recvRawDataLen = 0;
    QTimer rawDataTimer;
    QMutex mut;

    void setupUi(BcConsole *c) {
        tempRawData.resize(maxTempRawDataLen);

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
BcConsole::BcConsole(QWidget *parent): BcEasyWidget(parent),
    ui( new Ui::BcConsole ),
    uih(new Uih::BcConsoleHelper)
{
    ui->setupUi( this );
    uih->setupUi(this);
    QObject::connect(&uih->rawDataTimer, &QTimer::timeout, this, &BcConsole::showRawData);
    uih->rawDataTimer.start();

    ui->textField->setReadOnly( true );
    ui->lineTextField->setReadOnly(true);
    ui->isHex->hide();

    connect( ui->clearBtn, &QPushButton::clicked, ui->textField, &QPlainTextEdit::clear);
    connect( ui->clearBtn, &QPushButton::clicked, ui->lineTextField, &QPlainTextEdit::clear);
    connect( ui->saveBtn,  &QPushButton::clicked, [=] {
        this->saveLog();
    });

    connect( ui->autoEnd, &QCheckBox::clicked, [=](bool checked) {
        if( checked )
            ui->textField->moveCursor( QTextCursor::End );
    });

    connect(ui->tabWidget, &QTabWidget::tabBarClicked, [=](int index) {
        bool line = index == 0;
        emit dataModeChanged(line);
        ui->isHex->setVisible(!line);
        if(line) {
            ui->saveBtn->setText(tr("Save Line Data"));
        } else {
            ui->saveBtn->setText(tr("Save Raw Data"));
        }
    });
}

BcConsole::~BcConsole()
{
    delete ui;
    delete uih;
}

void BcConsole::beautify()
{
    ui->lineTextField->setProperty("console", true);
    style()->unpolish(ui->lineTextField);
    style()->polish(ui->lineTextField);
}

void BcConsole::retranslateUi()
{
    ui->retranslateUi(this);
}


/**
 * !brief  将 textEdit 中的内容保存到指定文件中
 */
void BcConsole::saveLog(bool line) {
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
            file.write(ui->textField->toPlainText().toLatin1());   //写文件
        file.close();    //关文件
        file.deleteLater();
    }
}

/**
 * @brief Console::onDataSent
 * @param tmpText
 * 发送数据到下位机时，将其输出到文本框中
 */
void BcConsole::onSendData(const QByteArray &tmpText) {
    QByteArray t = QString("[Query] %0").arg( currentTimeStr() ).toLatin1();
    ui->lineTextField->appendPlainText( t.append( tmpText ) );
}


/** 设置操作按钮/复选框等是否可见 */
void BcConsole::settingsVisible(bool visible)
{
    ui->settingGroup->setVisible( visible );
}

void BcConsole::setRawDataRefreshMs(int ms)
{
    if(ms < 50) {
        ms = 50;
    }
    uih->rawDataTimer.start(ms);
}

void BcConsole::setRawDataBufferSize(int bytes)
{
    if(bytes < 4096) {
        bytes = 4096;
    }
    uih->tempRawData.resize(bytes);
    uih->maxTempRawDataLen = bytes;
}


/** 接收到一行数据 */
/** 将接收到的数据显示在 textEdit 中 */
void BcConsole::onRecvLineData(const QByteArray &tmpText) {
    if( !this->isVisible()) {
        return;
    }
    QByteArray display = currentTimeStr().toLatin1();
    display.append(tmpText);
    display.replace("\r\n", "\\r\\n");
    ui->lineTextField->appendPlainText( display  );  // 会在某条语句后面加上回车换行，并更新光标位置
//    ui->textField->append( display );          // 不添加回车换行，但自动移动光标
    if(!ui->autoEnd->isCheckable()) {
        ui->lineTextField->moveCursor( QTextCursor::PreviousBlock );  // 移动光标至先前的位置
    }
}

/** 接收原始数据 */
void BcConsole::onRecvRawData(const QByteArray &tmpText) {
    if( !this->isVisible()) {
        return;
    }
    copyRawData(tmpText);
}

/** 返回时间字符串，若 datetimeBox 未勾选，则不会返回时间字符串 */
QString BcConsole::currentTimeStr() {
    QString c;
    if( ui->datetimeBox->isChecked() ) {
        QString time = QTime::currentTime().toString( "hh:mm:ss.zzz" );
        c = QString("[%0]  ").arg( time );
    }
    return c;
}

void BcConsole::showRawData() {

    //    ui->textField->appendPlainText( display  );  // 会在某条语句后面加上回车换行，并更新光标位置
    if(uih->recvRawDataLen > 0) {
        ui->textField->moveCursor(QTextCursor::End);
        bool hex = ui->isHex->isChecked();
        uih->mut.lock();
        if(hex) {
            ui->textField->insertPlainText(QString(uih->tempRawData.left(uih->recvRawDataLen).toHex()));          // 不添加回车换行，但自动移动光标
        }
        else {
            ui->textField->insertPlainText(QString(uih->tempRawData.left(uih->recvRawDataLen)));          // 不添加回车换行，但自动移动光标
        }
//        qDebug() << "tempRawData" << uih->tempRawData;
        uih->recvRawDataLen = 0;
        uih->mut.unlock();

        ui->textField->moveCursor(QTextCursor::End);
        if(!ui->autoEnd->isCheckable()) {
            ui->textField->moveCursor(QTextCursor::PreviousBlock);  // 移动光标至先前的位置
        }
    }
}

void BcConsole::copyRawData(const QByteArray &tmpText) {
    int len = tmpText.length();
    uih->mut.lock();
    memcpy(uih->tempRawData.data() + uih->recvRawDataLen, tmpText.data(), static_cast<size_t>(len));
//    qDebug() << tmpText << len;
    uih->recvRawDataLen += len;
    uih->mut.unlock();
    if(uih->recvRawDataLen > uih->maxTempRawDataLen - 1024) {
        showRawData();
    }
}
