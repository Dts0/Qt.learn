#include "widget.h"
#include "ui_widget.h"
#include <QLabel>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
}

Widget::~Widget()
{
    delete ui;

}

void Widget::init()
{
    ui->treeWidget->clear();
    num=0;
    QTreeWidgetItem *gr=/* new QTreeWidgetItem(ui->treeWidget);*/createNode(10);
    //gr->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    //gr->setCheckState(0,Qt::Unchecked);

    QLabel *l=new QLabel(this);
    l->setText( gr->text(0));

}

QTreeWidgetItem* Widget::createNode(int nodes)
{
    QTreeWidgetItem *group1=new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0,"group"+QString("%1").arg(num));
    group1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group1->setCheckState(0,Qt::Unchecked);


    for(int i=0;i<nodes;++i)
    {QTreeWidgetItem *item1=new QTreeWidgetItem(group1);
    item1->setText(0,"item"+QString("%1").arg(i));
    item1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    item1->setCheckState(0,Qt::Unchecked);}

    num++;

    return group1;
}


