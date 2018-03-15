#ifndef RELAUNCHEREXEC_H
#define RELAUNCHEREXEC_H

#include <QObject>
#include <QTimer>

#define RELOADTIME  2000
class relauncherExec : public QObject
{
    Q_OBJECT
public:
    explicit relauncherExec(QObject *parent = nullptr);

signals:

public slots:
    void    setexecutableCom(QString bashCom){m_execCom = bashCom;}
    void    setexecutableName(QString name){m_execName = name;}
    void    setInterval(int ms){m_interval = ms;}
    void    start(int ms){m_interval = ms; start();}
    void    start(){m_reload.start(m_interval);}
    void    exec();

private slots:

private:
    int m_interval;
    QTimer m_reload;
    QString m_execCom;
    QString m_execName;





};

#endif // RELAUNCHEREXEC_H
