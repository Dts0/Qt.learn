#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTime>
#include <QTimer>
#include <QPalette>
#include <QMouseEvent>
#include <QLCDNumber>

class Dialog : public QLCDNumber
{
    Q_OBJECT
public slots:
    void showTime();
public:
    Dialog(const QColor &color=Qt::blue,QWidget *parent = 0);
    ~Dialog();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    QPoint dragPosition;
    QPalette p;
    bool showColon;

};

#endif // DIALOG_H
