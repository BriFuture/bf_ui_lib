#include "BUILib.h"
#include <QObject>
#include <QFile>
#include <QDebug>

BUILib::BUILib()
{

}

QString BUILib::getVersion()
{
    return QString("%1.%2.%3").arg(getMajorVer()).arg(getMinorVer()).arg(getPatchVer());
}

QString BUILib::aboutBuiLib()
{
    return QObject::tr("Customized BUI Library.\n Version: %1").arg(getVersion());
}

void BUILib::beautifyApp(QApplication &a)
{
    QFile buiStyle(":/res/bui.qss");
    if(buiStyle.open(QFile::ReadOnly | QFile::Text)) {
        QString style = buiStyle.readAll();
        a.setStyleSheet(style);
    } else {
        qWarning() << "[bui] Fail to beautify App";
    }
}

int BUILib::getMajorVer()
{
    return _BUI_LIB_MAJOR_VER;
}

int BUILib::getMinorVer()
{
    return _BUI_LIB_MINOR_VER;
}

int BUILib::getPatchVer()
{
    return _BUI_LIB_PATCH_VER;
}
