#ifndef WIDGET_H
#define WIDGET_H

#include "server.h"
#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QListWidget *ContentList;
    QLabel *PortL;
    QLineEdit *PortLE;
    QPushButton *CreateBtn;
    QGridLayout *Layout;

    int port;
    server *Server;
public slots:
    void slotCreateServer();
    void updateServer(QString msg,int length);
};

#endif // WIDGET_H
