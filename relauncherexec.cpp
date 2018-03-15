#include "relauncherexec.h"
#include <QProcess>
#include <QDebug>

relauncherExec::relauncherExec(QObject *parent) : QObject(parent)
{
    setInterval(RELOADTIME);
    connect(&m_reload, SIGNAL(timeout()), this, SLOT(exec()));
}

void    relauncherExec::exec()
{
    qWarning() << "start Exec";
    QProcess    p1;

    p1.start("/bin/bash", QStringList()<< "-c"
             << QString(" ps -C ").append(m_execName).append(" -o pid="));
    bool retval = false;
    qWarning() << QString(" ps -C ").append(m_execName).append(" -o pid=");
    QByteArray buf;
    while ((retval = p1.waitForFinished()));
    buf = p1.readAll();
    qWarning() << buf;

    if (!buf.count())
    {
        qWarning() << "app not found, relaunch app : " <<  m_execCom;
//        p1.start();
        QProcess::startDetached("/bin/bash", QStringList()<< "-c"
                                << QString(m_execCom));
        while ((retval = p1.waitForFinished()));
        qWarning() <<p1.readAll();

    }
}
