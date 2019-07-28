#ifndef BUIUTIL_H
#define BUIUTIL_H

#include <QObject>
#include <QApplication>
#include <QStyle>
#include <QWidget>

class BUiUtil
{
public:
    BUiUtil();
    void setApplication(const QApplication &app);
    void polish(QWidget *w, )

private:
    QStyle *style = nullptr;
};

#endif // BUIUTIL_H
