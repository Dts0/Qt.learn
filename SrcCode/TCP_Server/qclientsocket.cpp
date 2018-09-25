#include "qclientsocket.h"

ClientSocket::ClientSocket(QObject *parent):QTcpSocket(parent)
{

    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));

}
void ClientSocket::dataReceived()
{
   while(bytesAvailable()>0)
   {
       int length=bytesAvailable();
       char buf[1024];

       read(buf,length);

       QString msg=buf;
       emit UpdateClients(msg,length);
   }
}
void ClientSocket::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
}

