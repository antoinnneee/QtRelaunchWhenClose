#include "mainwindow.h"
#include <QApplication>
#include "task.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bool consoleMode = false;
    if (consoleMode)
    {
        Task    *task = new Task(&a);
    }
    else
    {
        MainWindow *task = new MainWindow;
        task->show();
    }

    return a.exec();
}
