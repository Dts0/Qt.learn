#include "server.h"

server::server(QObject *parent,int port)
    :QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
    qDebug()<<"create listener";
}
void server::incomingConnection(int socketDescriptor)
{
    ClientSocket *tcpClientSocket=new ClientSocket(this);
    connect(tcpClientSocket,SIGNAL(UpdateClients(QString,int)),this,SLOT(updateClients(QString,int)));
    connect(tcpClientSocket,SIGNAL(disconnected(int)),this,SLOT(slotDisconnected(int)));

    tcpClientSocket->setSocketDescriptor(socketDescriptor);
qDebug()<<tcpClientSocket->Text;
    TcpClientList.append(tcpClientSocket);

}

void server::updateClients(QString msg, int length)
{
    emit UpdateServer(msg,length);
    for(int i=0;i<TcpClientList.count();++i)
    {
        QTcpSocket *item=TcpClientList.at(i);
        if(item->write(msg.toLatin1(),length)!=length)
        {
            qDebug()<<"update client"<<item;
            continue;
        }
    };
}

void server::slotDisconnected(int descriptor)
{
    for(int i=0;i<TcpClientList.count();++i)
    {
        QTcpSocket *item=TcpClientList.at(i);
        if(item->socketDescriptor()==descriptor)
        {
            qDebug()<<"disconnect"<<TcpClientList.at(i);
            TcpClientList.removeAt(i);
        }
    }

}
