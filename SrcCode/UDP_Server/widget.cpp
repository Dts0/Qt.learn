#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    TimerL=new QLabel("计时器:");
    TextLE=new QLineEdit;
    startBtn=new QPushButton("开始");
    Layout=new QVBoxLayout(this);
    Layout->addWidget(TimerL);
    Layout->addWidget(TextLE);
    Layout->addWidget(startBtn);

    Timer=new QTimer(this);
    port=5555;
    isStarted=false;
    Socket=new QUdpSocket(this);
    connect(startBtn,SIGNAL(clicked(bool)),this,SLOT(startBtnClicked()));
    connect(Timer,SIGNAL(timeout()),this,SLOT(timeOut()));

}

Widget::~Widget()
{

}

void Widget::timeOut()
{
    QString msg=TextLE->text();
    int len=0;
    if(msg=="")
        return;
    if((len=Socket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port))!=msg.length())
    {
        return;
    }
}

void Widget::startBtnClicked()
{
    if(!isStarted)
    {
        startBtn->setText("停止");
        Timer->start(1000);
        isStarted=true;
    }
    else {
        startBtn->setText("开始");
        isStarted=false;
        Timer->stop();
    }
}
