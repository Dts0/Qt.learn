#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    List=new QListWidget(this);
    Stack=new QStackedWidget(this);
    l1=new QLabel("Label1");
    l2=new QLabel("Label2");
    l3=new QLabel("Label3");

    Stack->addWidget(l1);
    Stack->addWidget(l2);
    Stack->addWidget(l3);

    List->insertItem(0,"label1");
    List->insertItem(1,"label2");
    List->insertItem(2,"label3");

    QHBoxLayout *Layout=new QHBoxLayout(this);
    Layout->addSpacing(10);
    //Layout->addStretch(10);
    Layout->addWidget(List);
    Layout->addWidget(Stack,0,Qt::AlignHCenter|Qt::AlignCenter);
    Layout->setStretchFactor(List,1);
    Layout->setStretchFactor(Stack,3);

    connect(List,SIGNAL(currentRowChanged(int)),Stack,SLOT(setCurrentIndex(int)));
}

Widget::~Widget()
{
    delete ui;
}
