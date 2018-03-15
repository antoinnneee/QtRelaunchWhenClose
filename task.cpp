#include "task.h"

Task::Task(QObject *parent) : QObject(parent)
{
    rlE.setInterval(2000);
    rlE.setexecutableName("raspiCCSender");
    rlE.setexecutableCom("/home/pi/.config/BARTHE_CONFIG/raspiCCSender");
    rlE.start();
}
