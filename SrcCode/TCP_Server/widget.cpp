#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("TCP Server");

    ContentList=new QListWidget;
    PortL=new QLabel("端口:");
    PortLE=new QLineEdit;
    CreateBtn=new QPushButton("创建服务器");
    Layout=new QGridLayout(this);

    Layout->addWidget(ContentList,0,0,1,2);
    Layout->addWidget(PortL,1,0);
    Layout->addWidget(PortLE,1,1);
    Layout->addWidget(CreateBtn,2,0,1,2);

    port=8010;
    PortLE->setText(QString::number(port));

    connect(CreateBtn,SIGNAL(clicked(bool)),this,SLOT(slotCreateServer()));

}

Widget::~Widget()
{

}

void Widget::slotCreateServer()
{
    Server=new server(this,port);
    connect(Server,SIGNAL(UpdateServer(QString,int)),this,SLOT(updateServer(QString,int)));

    CreateBtn->setEnabled(false);
    ContentList->addItem("服务器启动,端口:"+QString::number(port));
}

void Widget::updateServer(QString msg, int length)
{
    ContentList->addItem(msg.left(length));
}
