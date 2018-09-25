#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QNetworkInterface>
#include <QHostInfo>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public:
    void getHostInfo();
public slots:
    void getDetail();
private:
    QGridLayout *Layout;
    QLabel *HostNameL;
    QLabel *IPL;
    QLineEdit *HostNameLE;
    QLineEdit *IPLE;
    QPushButton *DetailBtn;
};


#endif // WIDGET_H
