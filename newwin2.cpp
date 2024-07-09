#include "newwin2.h"
#include "ui_newwin2.h"
#include "qtimer.h"//timer
#include "qdatetime.h"//current time
newwin2::newwin2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::newwin2)
{
    ui->setupUi(this);
    timerUpdate();
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
}

newwin2::~newwin2()
{
    delete ui;
    delete timer2;
    delete timer;
    delete timer3;
}

void newwin2::timerUpdate(void)
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("hh:mm:ss");

    ui->label_2->setText(str);

}

void newwin2::timerUpdate2()
{
    if(isCounting!=true){
        s+=1;
        if (s == 60){
            s=0;
            m+=1;
        }
        if(m==60){
            m=0;
            h+=1;
        }
    }

    QString timeString = QString("Work Remain:<br>%1:%2:%3").arg(h, 2, 10, QChar('0')).arg(m, 2, 10, QChar('0')).arg(s, 2, 10, QChar('0'));

    ui->label_3->setText(timeString);
}

void newwin2::on_pushButton_clicked()
{
    isCounting = 0;
    QTimer *timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(timerUpdate2()));
    timer2->start(1000);
    ui->label->setText("Work");
}

void newwin2::timerUpdate3()
{

    s1+=1;
    if (s1 == 60){
        s1=0;
         m1+=1;
    }
    if(m1==60){
        m1=0;
        h1+=1;
    }


    QString timeString1 = QString("Current Rest:<br>%1:%2:%3").arg(h1, 2, 10, QChar('0')).arg(m1, 2, 10, QChar('0')).arg(s1, 2, 10, QChar('0'));

    ui->label_4->setText(timeString1);
}
void newwin2::on_pushButton_2_clicked()
{
    //timer2->stop();
    isCounting = true;
    timer3 = new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(timerUpdate3()));
    timer3->start(1000);
    ui->label->setText("Rest");
}

