#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QUdpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QTime>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void CloseBtnClicked();
    void dataReceived();
private:
    QTextEdit *Text;
    QPushButton *CloseBtn;
    QVBoxLayout *Layout;

    int port;
    QUdpSocket *socket;
};

#endif // WIDGET_H
