#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    p_myTimer = new QTimer;
    connect(p_myTimer, SIGNAL(timeout()), this, SLOT(tick()));
    p_myTimer->start(1000);
    tick();
    setWindowTitle(tr("Digital Clock"));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tick()
{
    QDateTime current = QDateTime::currentDateTime();
    QTime time = QTime::currentTime();
    QString strDate = current.toString("yyyy:mm:dd hh:mm:ss");
    QString strTime = current.toString("hh:mm:ss");
    if ((time.second() % 2) == 0)
        strTime[2] = strTime[5] = ' ';

    ui->lcdNumber->display(strTime);
    ui->statusBar->showMessage(strDate);

    qsTemp = strDate;
    qDebug() <<qsTemp;
}
