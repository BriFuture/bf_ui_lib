#ifndef BPROGRAMSHARER_H
#define BPROGRAMSHARER_H

#include <QObject>
#include <QApplication>
#include <QSettings>

#include "builib_global.h"

class BUILIBSHARED_EXPORT BProgramSharer
{
public:
    BProgramSharer(const QString programName);
    void exportProgramPath(const QCoreApplication *app);
    void exportMainWindowId(const QString &id);
    void exportPID();

    QString findProgram(const QString &programName, const QString &defaultPath = QString());

    void open();
    void close();
    void sync();
    QString getWid() const;

private:
    QSettings *set = nullptr;
    QString wid;
    QString programName;
};

#endif // BPROGRAMSHARER_H
