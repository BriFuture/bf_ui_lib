#ifndef BUIUTIL_H
#define BUIUTIL_H

#include <QObject>
#include <QApplication>
#include <QStyle>

class BUiUtil
{
public:
    BUiUtil();
    void setApplication(const QApplication &app);

private:
    QStyle *style = nullptr;
};

#endif // BUIUTIL_H
