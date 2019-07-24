#ifndef BUILIB_H
#define BUILIB_H

#include "builib_global.h"
#include <QString>

class BUILIBSHARED_EXPORT BuiLib
{

public:
    BuiLib();
    static int getMajorVer();

    static int getMinorVer();

    static int getPatchVer();

    static QString getVersion();

    static QString aboutBuiLib();
};

#endif // BUILIB_H
