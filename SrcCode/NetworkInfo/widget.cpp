#include "widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    HostNameL=new QLabel("主机名:");
    HostNameLE=new QLineEdit;
    IPL=new QLabel("IP:");
    IPLE=new QLineEdit;
    DetailBtn=new QPushButton("细节");

    Layout=new QGridLayout(this);
    Layout->addWidget(HostNameL,0,0);
    Layout->addWidget(HostNameLE,0,1);
    Layout->addWidget(IPL,1,0);
    Layout->addWidget(IPLE,1,1);
    Layout->addWidget(DetailBtn,2,0,1,2);

    getHostInfo();
    connect(DetailBtn,SIGNAL(clicked(bool)),this,SLOT(getDetail()));
}

Widget::~Widget()
{

}

void Widget::getHostInfo()
{
    QString HostName=QHostInfo::localHostName();
    HostNameLE->setText(HostName);

    QList<QHostAddress> hostInfo=(QHostInfo::fromName(HostName)).addresses();
    IPLE->setText(hostInfo.value(0).toString());
}
void Widget::getDetail()
{
    QString detail="";
    QList<QNetworkInterface> list=QNetworkInterface::allInterfaces();
    for(int i=0;i<list.count();++i)
    {
        detail+="设备:"+list.at(i).name()+"\n";
        detail+="硬件地址:"+list.at(i).hardwareAddress()+"\n";
        QList<QNetworkAddressEntry> entryList=list.at(i).addressEntries();
        for(int j=0;j<entryList.count();++j)
        {
            detail+="\tIP地址:"+entryList.at(j).ip().toString()+"\n";
            detail+="\t子网掩码:"+entryList.at(j).netmask().toString()+"\n";
            detail+="\t广播地址:"+entryList.at(j).broadcast().toString()+"\n";
        }
    }
    QMessageBox::information(this,"细节",detail);

}
