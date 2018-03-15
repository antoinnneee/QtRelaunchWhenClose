#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    rlE.setInterval(2000);
    rlE.setexecutableName(ui->textEdit->toPlainText());
    rlE.setexecutableCom(ui->textEdit_2->toPlainText());
    rlE.start();
}
