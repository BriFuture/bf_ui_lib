#ifndef BUIUTIL_H
#define BUIUTIL_H

#include <QObject>
#include <QApplication>
#include <QStyle>
#include <QWidget>
#include "builib_global.h"

class BUILIBSHARED_EXPORT BUiUtil
{
public:
    static void setWidgetStyle(QWidget *w, const QString &stylefile);

    BUiUtil();
    void setApplication(QApplication &app);
    void polish(QWidget *w);

private:
    QStyle *style = nullptr;
};

#endif // BUIUTIL_H
