#ifndef BUILIB_H
#define BUILIB_H

#include "builib_global.h"
#include <QString>
#include <QApplication>

class BUILIBSHARED_EXPORT BUILib
{

public:
    BUILib();
    static int getMajorVer();

    static int getMinorVer();

    static int getPatchVer();

    static QString getVersion();

    static QString aboutBuiLib();

    static void beautifyApp(QApplication &a);
};

#endif // BUILIB_H
