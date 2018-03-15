#ifndef TASK_H
#define TASK_H

#include <QObject>
#include "relauncherexec.h"

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);

signals:

public slots:
private:
    relauncherExec rlE;

};

#endif // TASK_H
