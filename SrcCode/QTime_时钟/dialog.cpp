#include "dialog.h"

Dialog::Dialog(const QColor &color,QWidget *parent)
    : QLCDNumber(parent)
{
    p=palette();
    p.setColor(QPalette::Window,color);
    setPalette(p);

    setWindowFlag(Qt::FramelessWindowHint);

    setWindowOpacity(0.5);

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);
    showTime();
    resize(150,60);

    showColon=true;
}

Dialog::~Dialog()
{

}

void Dialog::showTime()
{
    QTime time=QTime::currentTime();
    QString timeStr=time.toString("hh:mm");
    if(showColon)
    {
        timeStr[2]=':';
        showColon=false;
    }
    else {timeStr[2]=' ';showColon=true;}

    display(timeStr);

}
void Dialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
       {
        dragPosition=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
}
void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        move(event->globalPos()-dragPosition);
        event->accept();
    }
}
