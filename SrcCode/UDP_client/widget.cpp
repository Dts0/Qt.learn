#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("UDP客户端");

    Text=new QTextEdit;
    CloseBtn=new QPushButton("关闭");
    Layout=new QVBoxLayout(this);
    Layout->addWidget(Text);
    Layout->addWidget(CloseBtn);

    port=5555;
    socket=new QUdpSocket(this);
    connect(CloseBtn,SIGNAL(clicked(bool)),this,SLOT(CloseBtnClicked()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(dataReceived()));

    if(!socket->bind(port))
        QMessageBox::information(this,"Error","UDP Socket Error!");
}

void Widget::CloseBtnClicked()
{
    close();
}

void Widget::dataReceived()
{
    while(socket->hasPendingDatagrams())
    {
        QByteArray dataPram;
        dataPram.resize(socket->pendingDatagramSize());

        socket->readDatagram(dataPram.data(),dataPram.size());

        Text->append(QTime::currentTime().toString()+"\n"+QString(dataPram.data()));
    }
}

Widget::~Widget()
{

}
