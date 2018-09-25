#include "drawer.h"

Drawer::Drawer(QWidget *parent,Qt::WindowFlags f):QToolBox(parent,f)
{
    setWindowTitle("MyQQ");
    QSize IconSize=QSize(48,48);

    btn1_1=new QToolButton;
    btn1_1->setText("Name1");
    btn1_1->setIcon(QPixmap("../QToolBox/cats/cat (1).png"));
    btn1_1->setIconSize(IconSize);
    btn1_1->setAutoRaise(true);
    btn1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    btn1_2=new QToolButton;
    btn1_2->setText("Name1");
    btn1_2->setIcon(QPixmap("../QToolBox/cats/cat (2).png"));
    btn1_2->setIconSize(IconSize);
    btn1_2->setAutoRaise(true);
    btn1_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    btn2_1=new QToolButton;
    btn2_1->setText("Name1");
    btn2_1->setIcon(QPixmap("../QToolBox/cats/cat (3).png"));
    btn2_1->setIconSize(IconSize);
    btn2_1->setAutoRaise(true);
    btn2_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    btn2_2=new QToolButton;
    btn2_2->setText("Name1");
    btn2_2->setIcon(QPixmap("../QToolBox/cats/cat (4).png"));
    btn2_2->setIconSize(IconSize);
    btn2_2->setAutoRaise(true);
    btn2_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    btn3_1=new QToolButton;
    btn3_1->setText("Name1");
    btn3_1->setIcon(QPixmap("../QToolBox/cats/cat (5).png"));
    btn3_1->setIconSize(IconSize);
    btn3_1->setAutoRaise(true);
    btn3_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    btn3_2=new QToolButton;
    btn3_2->setText("Name1");
    btn3_2->setIcon(QPixmap("../QToolBox/cats/cat (6).png"));
    btn3_2->setIconSize(IconSize);
    btn3_2->setAutoRaise(true);
    btn3_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    GBox1=new QGroupBox;
    Layout1=new QVBoxLayout(GBox1);
    Layout1->setMargin(10);
    Layout1->addWidget(btn1_1);
    Layout1->addWidget(btn1_2);
    //Layout1->addStretch();

    GBox2=new QGroupBox;
    Layout2=new QVBoxLayout(GBox2);
    Layout2->setMargin(10);
    Layout2->addWidget(btn2_1);
    Layout2->addWidget(btn2_2);

    GBox3=new QGroupBox;
    Layout3=new QVBoxLayout(GBox3);
    Layout3->setMargin(10);
    Layout3->addWidget(btn3_1);
    Layout3->addWidget(btn3_2);

    addItem(GBox1,"Group1");
    addItem(GBox2,"Group2");
    addItem(GBox3,"Group3");
}
