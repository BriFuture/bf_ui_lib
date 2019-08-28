#include "BUpdator.h"
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>
#include <QProcessEnvironment>
#include <QDebug>

const QString BUpdator::LevelAlpha = "alpha";
const QString BUpdator::LevelBeta = "beta";
const QString BUpdator::LevelStable = "stable";
const QString BUpdator::LevelEmergence = "emergence";

BUpdator::BUpdator(QObject *parent) : QObject(parent)
{
    setRemoteMaxAttemp();
    setLocalTempDir();
    setRemoteUsername("", "");
    process = new QProcess(this);
    connect(process, &QProcess::stateChanged, this, &BUpdator::onStateChange);
}

void BUpdator::setLocalProgramName(const QString &pn)
{
    localSchema.insert("programName", pn);
}

void BUpdator::setLocalDisplayName(const QString &name)
{
    localSchema.insert("displayName", name);
}

void BUpdator::setLocalProgramDir(const QString &dir)
{
    localSchema.insert("programDir", dir);
}

void BUpdator::setLocalTempDir(const QString &tdir)
{
    localSchema.insert("tmpDir", tdir);
}

void BUpdator::setLocalCurrentVersion(const QString &ver)
{
    localSchema.insert("currentVersion", ver);
}

void BUpdator::setLocalCurrentVersion(int major, int minor, int patch)
{
    localSchema.insert("currentMajorVer", major);
    localSchema.insert("currentMinorVer", minor);
    localSchema.insert("currentPatchVer", patch);
}

void BUpdator::setRemoteMaxAttemp(int attemp)
{
    remoteSchema.insert("maxAttemp", attemp);
}

void BUpdator::setRemoteMetainfo(const QStringList &urls)
{
    QJsonArray arr = QJsonArray::fromStringList(urls);
    remoteSchema.insert("remoteMetainfo", arr);
}

/*
void BcUpdator::setRemotePort(const QList<int> &ports)
{
    QJsonArray arr;
    foreach (int p, ports) {
        arr.append(QJsonValue(p));
    }
    remoteSchema.insert("remotePort", arr);
}

void BcUpdator::setRemoteMetainfoLoc(const QString &loc)
{
    remoteSchema.insert("metainfoLocation", loc);
}
*/

void BUpdator::setRemoteUserAgend(const QString &ua)
{
    remoteSchema.insert("userAgend", ua);
}

void BUpdator::setRemoteUsername(const QString &un, const QString &pw)
{
    remoteSchema.insert("username", un);
    remoteSchema.insert("password", pw);
}

void BUpdator::setRemoteLeastLevel(const QString &level)
{
    remoteSchema.insert("leastLevel", level);
}



void BUpdator::save(const QString &name)
{
    QJsonObject schema;
    schema.insert("local", localSchema);
    schema.insert("remote", remoteSchema);
    QJsonDocument doc(schema);
    QFile f(name);
    if(f.open(QFile::WriteOnly)) {
        f.write(doc.toJson());
    } else {
        qWarning() << "Unable to open file: " << name;
    }
    f.close();
    f.deleteLater();
}

void BUpdator::start(const QString &updator, const QString &config, bool background)
{
    if(running) {
        qInfo() << "Process is running";
        return;
    }
    qInfo() << "Starting Updator";
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    process->setProcessEnvironment(env);
    QStringList args = QStringList() << "-f" << config;
    if(background) {
        args.append("-b");
    }
    process->startDetached(updator, args);
}

void BUpdator::onStateChange(const QProcess::ProcessState state)
{
    qDebug() << state;
    if(state == QProcess::Running) {
        running = true;
    } else {
        running = false;
    }
}
