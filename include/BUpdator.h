#ifndef BUPDATOR_H
#define BUPDATOR_H

#include <QObject>
#include <QJsonObject>
#include <QStringList>
#include <QProcess>
#include "builib_global.h"


class BUILIBSHARED_EXPORT BUpdator : public QObject
{
    Q_OBJECT
public:
    static const QString LevelAlpha;
    static const QString LevelBeta;
    static const QString LevelStable;
    static const QString LevelEmergence;

    explicit BUpdator(QObject *parent = 0);

    void setLocalProgramName(const QString &pn);
    void setLocalDisplayName(const QString &name);
    void setLocalProgramDir(const QString &dir);
    void setLocalTempDir(const QString &tdir = QString("./tmp"));
    void setLocalCurrentVersion(const QString &ver);
    void setLocalCurrentVersion(int major, int minor, int patch);

    void setRemoteMaxAttemp(int attemp = 5);
    void setRemoteMetainfo(const QStringList &urls);
//    void setRemotePort(const QList<int> &ports);
//    void setRemoteMetainfoLoc(const QString &loc);
    void setRemoteUserAgend(const QString &ua);
    void setRemoteUsername(const QString &un, const QString &pw);
    void setRemoteLeastLevel(const QString &level);
signals:

public slots:
    // abs path name
    void save(const QString &name);
    void start(const QString &updator, const QString &config, bool background);

protected slots:
    void onStateChange(const QProcess::ProcessState state);
private:
    QJsonObject localSchema;
    QJsonObject remoteSchema;
    QProcess *process = nullptr;

    bool running = false;
};

#endif // BCUPDATOR_H
