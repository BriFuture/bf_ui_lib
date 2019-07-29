#include "BProgramSharer.h"
#include <QDebug>
#include <QDir>

BProgramSharer::BProgramSharer(const QString programName)
{
    this->programName = programName;
    open();
}


void BProgramSharer::exportProgramPath(const QApplication &app)
{
    set->beginGroup("ProgramPath");
    set->setValue(programName, app.applicationFilePath());
    set->endGroup();
}

void BProgramSharer::exportMainWindowId(const QString &id)
{
    set->beginGroup("MainWindowId");
    set->setValue(programName, id);
    wid = id;
    set->endGroup();
    set->sync();
}

void BProgramSharer::exportPID()
{
    set->beginGroup("PID");
    set->setValue(programName, QString::number(static_cast<int>(QApplication::applicationPid())));
    qDebug() << "AppPID" << QApplication::applicationPid();
    set->endGroup();
}

void BProgramSharer::open()
{
    if(set == nullptr) {
        set = new QSettings(QString("%1/bf_programs.ini")
                .arg(QDir::homePath()), QSettings::IniFormat);
    }
}

void BProgramSharer::close()
{
    set->deleteLater();
    set = nullptr;
}

QString BProgramSharer::getWid() const
{
    return wid;
}
