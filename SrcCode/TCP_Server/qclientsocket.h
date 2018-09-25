#ifndef QCLIENTSOCKET_H
#define QCLIENTSOCKET_H

#include <QTcpSocket>
#include <QObject>

class ClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    ClientSocket(QObject *parent=0);
signals:
    void UpdateClients(QString msg,int length);
    void disconnected(int);
protected slots:
    void dataReceived();
    void slotDisconnected();
};

#endif // QCLIENTSOCKET_H
