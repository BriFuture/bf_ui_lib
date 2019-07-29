#include "BUiUtil.h"
#include <QFile>

BUiUtil::BUiUtil()
{

}

void BUiUtil::setApplication(QApplication &app)
{
    style = app.style();
    QFile styleFile(":/res/bui.qss");
    styleFile.open(QFile::ReadOnly | QFile::Text);
    QString style = QString::fromUtf8(styleFile.readAll());
    app.setStyleSheet(style);
    styleFile.close();
}

void BUiUtil::polish(QWidget *w)
{

}
