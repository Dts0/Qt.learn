#ifndef DRAWER_H
#define DRAWER_H

#include <QToolBox>
#include <QToolButton>
#include <QGroupBox>
#include <QVBoxLayout>

class Drawer : public QToolBox
{
    Q_OBJECT
public:
    Drawer(QWidget *parent=0,Qt::WindowFlags f=0);
private:
    QGroupBox *GBox1;
    QGroupBox *GBox2;
    QGroupBox *GBox3;

    QVBoxLayout *Layout0;
    QVBoxLayout *Layout1;
    QVBoxLayout *Layout2;
    QVBoxLayout *Layout3;

    QToolButton *btn1_1;
    QToolButton *btn1_2;

    QToolButton *btn2_1;
    QToolButton *btn2_2;

    QToolButton *btn3_1;
    QToolButton *btn3_2;
};

#endif // DRAWER_H
