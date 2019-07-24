#include "BuiLib.h"

BuiLib::BuiLib()
{

}

QString BuiLib::getVersion()
{
    return QString("%1.%2.%3").arg(getMajorVer()).arg(getMinorVer()).arg(getPatchVer());
}

QString BuiLib::aboutBuiLib()
{
    return QString("BriFuture's Custom UI Library.\n Version: %1").arg(getVersion());
}

int BuiLib::getMajorVer()
{
    return _BUI_LIB_MAJOR_VER;
}

int BuiLib::getMinorVer()
{
    return _BUI_LIB_MINOR_VER;
}

int BuiLib::getPatchVer()
{
    return _BUI_LIB_PATCH_VER;
}
