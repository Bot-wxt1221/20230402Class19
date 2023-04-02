#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QToolButton>
#include <QLCDNumber>
#include <QTime>
#include <fstream>
#include <QRandomGenerator>
Ui::MainWindow *uii;

QString student[60];

void Random(){
    int time=QRandomGenerator::global()->bounded(10)+10;
    int now=0;
    for(int i=1;i<=time;i++){
        now=QRandomGenerator::global()->bounded(50)+1;
        uii->label->setText(QString::number(now)+"   "+student[now]);
        QTime t;
        t.start();
        while(t.elapsed()<100)
            QCoreApplication::processEvents();
    }
    int time2=QRandomGenerator::global()->bounded(10)+10;
    int now2=0;
    for(int i=1;i<=time2;i++){
        now2=QRandomGenerator::global()->bounded(50)+1;
        uii->label_2->setText(QString::number(now2)+"   "+student[now2]);
        QTime t;
        t.start();
        while(t.elapsed()<100)
            QCoreApplication::processEvents();
    }
    return ;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    std::ifstream inn("/home/wxt/data.csv");
    for(int i=1;i<=51;i++){
        int aa;
        inn>>aa;
        char temp;
        inn>>temp;
        std::string temp2;
        inn>>temp2;
        student[aa]=QString::fromStdString(temp2);
    }
    uii=ui;
    ui->setupUi(this);
    QFont a;
    a.setPointSize(42);
    ui->label->setFont(a);
    ui->label_2->setFont(a);
    ui->label_3->setFont(a);
    QObject::connect( ui->pushButton,&QToolButton::clicked,ui->pushButton,Random);
}
MainWindow::~MainWindow()
{
    delete ui;
}

