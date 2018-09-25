#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QUdpSocket>
#include <QTimer>
#include <QHostAddress>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void timeOut();
    void startBtnClicked();
private:
    QLabel *TimerL;
    QLineEdit *TextLE;
    QPushButton *startBtn;
    QVBoxLayout *Layout;

    int port;
    bool isStarted;
    QUdpSocket *Socket;
    QTimer *Timer;
};

#endif // WIDGET_H
