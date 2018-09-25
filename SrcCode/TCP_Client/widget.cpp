#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("TCP Client");

    contentList=new QListWidget;
    sendLE=new QLineEdit;
    sendBtn=new QPushButton("发送");
    UserNameL=new QLabel("用户名:");
    UserNameLE=new QLineEdit("defaultName");
    serverIPL=new QLabel("服务器IP:");
    serverIPLE=new QLineEdit("127.0.0.1");
    portL=new QLabel("端口");
    portLE=new QLineEdit;
    entryBtn=new QPushButton("进入聊天室");

    Layout=new QGridLayout(this);
    Layout->addWidget(contentList,0,0,1,2);
    Layout->addWidget(sendLE,1,0);
    Layout->addWidget(sendBtn,1,1);
    Layout->addWidget(UserNameL,2,0);
    Layout->addWidget(UserNameLE,2,1);
    Layout->addWidget(serverIPL,3,0);
    Layout->addWidget(serverIPLE,3,1);
    Layout->addWidget(portL,4,0);
    Layout->addWidget(portLE,4,1);
    Layout->addWidget(entryBtn,5,0,1,2);

    status=false;
    port=8010;
    portLE->setText(QString::number(port));

    serverIP=new QHostAddress;

    connect(entryBtn,SIGNAL(clicked(bool)),this,SLOT(slotEntry()));
    connect(sendBtn,SIGNAL(clicked(bool)),this,SLOT(slotSend()));

    sendBtn->setEnabled(false);
}
void Widget::slotEntry()
{
    if(!status)//if not connected,enter
    {
        QString ip=serverIPLE->text();
        if(!serverIP->setAddress(ip))
        {
            QMessageBox::information(this,"Error!","Server ip error!");
            return;
        }
        if(UserNameLE->text()=="")
        {
            QMessageBox::information(this,"error!","UserName error!");
            return;
        }
        UserName=UserNameLE->text();
        socket=new QTcpSocket(this);
        connect(socket,SIGNAL(connected()),this,SLOT(slotConected()));
        connect(socket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
        connect(socket,SIGNAL(readyRead()),this,SLOT(dataReceived()));

        socket->connectToHost(*serverIP,port);

        qDebug()<<"connect to host";

    }
    else //if connected,leave
    {
        int length=0;
        QString msg=UserName+":Leave Chat Room";
        if((length=socket->write(msg.toLatin1(),msg.length()))!=msg.length())
            return;
        socket->disconnectFromHost();
        status=false;
    }
}
void Widget::slotConected()
{
    status=true;
    sendBtn->setEnabled(true);
    entryBtn->setText("离开");
qDebug()<<"connect successfully";
    int length=0;
    QString msg=UserName+":Enter Chat Room";
    if((length=socket->write(msg.toLatin1(),msg.length()))!=msg.length())
        return;
}
void Widget::slotSend()
{
    if(sendLE->text()=="")
        return;

    QString msg=UserName+":"+sendLE->text();

    qDebug()<<msg.toLatin1()<<msg;
    socket->write(msg.toLocal8Bit(),msg.length());
    sendLE->clear();
}
void Widget::slotDisconnected()
{
    sendBtn->setEnabled(false);
    entryBtn->setText("进入聊天室");
}
void Widget::dataReceived()
{
    while(socket->bytesAvailable()>0)
    {
        QByteArray datagram;
        datagram.resize(socket->bytesAvailable());

        socket->read(datagram.data(),datagram.size());

        QString msg=datagram.data();
        contentList->addItem(msg.left(datagram.size()));
    }
}

Widget::~Widget()
{

}
