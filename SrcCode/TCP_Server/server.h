#ifndef SERVER_H
#define SERVER_H

#include "qclientsocket.h"
#include <QTcpServer>
#include <QObject>

class server : public QTcpServer
{
    Q_OBJECT
public:
    server(QObject *parent=0,int port=0);
    QList<ClientSocket*> TcpClientList;
signals:
    void UpdateServer(QString msg,int length);
public slots:
    void updateClients(QString msg, int length);
    void slotDisconnected(int descriptor);
protected:
    void incomingConnection(int socketDescriptor);

};

#endif // SERVER_H
