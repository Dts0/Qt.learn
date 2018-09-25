#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

#include <QHostAddress>
#include <QTcpSocket>

#include <QMessageBox>
#include <QHostInfo>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QListWidget *contentList;
    QLineEdit *sendLE;
    QPushButton *sendBtn;
    QLabel *UserNameL;
    QLineEdit *UserNameLE;
    QLabel *serverIPL;
    QLineEdit *serverIPLE;
    QLabel *portL;
    QLineEdit *portLE;
    QPushButton *entryBtn;
    QGridLayout *Layout;

    bool status;
    int port;
    QHostAddress *serverIP;
    QString UserName;
    QTcpSocket *socket;

public slots:
    void slotEntry();
    void slotConected();
    void slotDisconnected();
    void dataReceived();
    void slotSend();
};

#endif // WIDGET_H
